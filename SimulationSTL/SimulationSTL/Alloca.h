#pragma once
typedef void(*HANDLE_FUNC) ();

template <int inst>
class __MallocAllocTemplate
{
public:
	static void* OOM_Malloc(size_t size)
	{
		while (1)
		{
			if (_handle == NULL)
			{
				throw bad_alloc();
			}
			_handle();
			void* ret = malloc(size);
			if (ret != NULL)
				return ret;
		}
	}
	static void* Allocate(size_t size)
	{

		void* ret = malloc(size);
		if (ret == 0)
		{
			ret = OOM_Malloc(size);
		}
		return ret;
	}

	static void Deallocate(void* p, size_t  n)
	{
		free(p);
	}

	static HANDLE_FUNC SetMallocHander(HANDLE_FUNC f)
	{
		HANDLE_FUNC old = f;
		_handle = f;
		return old;
	}
private:
	static HANDLE_FUNC _handle;
};


template<int inst>
HANDLE_FUNC __MallocAllocTemplate<inst>::_handle = 0;

//////////////////////////////////////////////
//二级空间配置器

template <bool threads, int inst>
class __DefaultAllocTemplate
{
public:
	static size_t FREELIST_INDEX(size_t bytes)
	{
		return (((bytes)+__ALIGN - 1) / __ALIGN - 1);
	}
	static size_t ROUND_UP(size_t bytes)  //对齐
	{
		return ((bytes)+__ALIGN - 1)&(~(__ALIGN - 1));
	}

	//从内存池中分配大块内存
	static char* ChunkAlloc(size_t size, size_t& nobjs)
	{
		char* result;
		size_t totalBytes = size*nobjs;  //需要申请的内存所占字节大小
		size_t leftBytes = _endFree - _startFree;  //内存池中剩于的内存大小
		if (leftBytes >= totalBytes)  //内存池足够申请nobjs个对象
		{
			result = _startFree;
			_startFree += totalBytes;
			return result;
		}
		else if (leftBytes >= size)  //内存池不够申请nobjs个对象,但是至少够一个
		{
			nobjs = leftBytes / size;
			totalBytes = size*nobjs;
			result = _startFree;
			_startFree += totalBytes;
			return result;
		}
		else   //内存池连一个对象的内存都不能够申请到
		{
			if (leftBytes > 0)  //处理剩余内存
			{
				size_t index = FREELIST_INDEX(leftBytes);  //将它挂到自由链表合适的位置去
				((Obj*)_startFree)->_freeListLink = _freeList[index];
				_freeList[index] = (Obj*)_startFree;
			}
			size_t  bytesToGet = totalBytes * 2 + ROUND_UP(_heapSize >> 4);  //?
			_startFree = (char*)malloc(bytesToGet);
			if (0 == _startFree)
			{
				//证明此时内存已经吃紧,到更大自由链表去取
				for (size_t i = size; i < __NFREELISTS; i++)
				{
					Obj* ret = _freeList[i];
					if (ret != NULL)
					{
						_freeList[i] = ret->_freeListLink;
						_startFree = (char*)ret;
						_endFree = _startFree + (i + 1)*__ALIGN;
						return ChunkAlloc(size, nobjs);
					}
				}
				_startFree = (char*)__MallocAllocTemplate<0>::Allocate(bytesToGet);
			}
			_heapSize += bytesToGet;
			_endFree = _startFree + bytesToGet;
			return ChunkAlloc(size, nobjs);
		}
	}

	static char* ReFill(size_t  size)
	{
		size_t nobjs = 20;
		char* chunk = ChunkAlloc(size, nobjs);
		if (nobjs == 1)
			return chunk;
		//将剩余的nobjs-1块挂到自由链表下面
		size_t index = FREELIST_INDEX(size);  //(1)求出下标
		_freeList[index] = (Obj*)(chunk + size);
		Obj* cur = _freeList[index];
		for (size_t i = 2; i < nobjs; i++)
		{
			Obj* next = (Obj*)((char*)cur + size);
			cur->_freeListLink = next;
			cur = next;
		}
		cur->_freeListLink = NULL;
		return chunk;
	}

	static  void* Allocate(size_t n)
	{
		if (n > __MAX_BYTES)  //超过自由链表所表示的最大范围,去一级空间配置器上申请
		{
			return __MallocAllocTemplate<0>::Allocate(n);
		}
		size_t  index = FREELIST_INDEX(n);
		if (NULL != _freeList[index])  //自由链表上结点不为空，取第一个结点给它
		{
			Obj* ret = _freeList[index];
			_freeList[index] = ret->_freeListLink;
			return ret;
		}
		else  //证明自由链表结点为空，需要到内存池上申请
		{
			return ReFill(ROUND_UP(n));
		}
	}
	static  void Deallocate(void* ptr, size_t n)
	{
		if (n > __MAX_BYTES)
		{
			__MallocAllocTemplate<0>::Deallocate(ptr, n);
		}
	}
private:
	enum { __ALIGN = 8 };
	enum { __MAX_BYTES = 128 };
	enum { __NFREELISTS = __MAX_BYTES / __ALIGN };

	union Obj
	{
		union Obj* _freeListLink;
		char client_data[1];
	};
	static Obj* _freeList[__NFREELISTS];
	static char* _startFree;
	static char* _endFree;
	static size_t _heapSize;
};

template<bool threads, int inst>
typename __DefaultAllocTemplate<threads, inst>::Obj*  __DefaultAllocTemplate<threads, inst>::_freeList[__NFREELISTS] = { 0 };

template <bool threads, int inst>
char* __DefaultAllocTemplate<threads, inst>::_startFree = NULL;

template <bool threads, int inst>
char* __DefaultAllocTemplate<threads, inst>::_endFree = NULL;

template  <bool threads, int inst>
size_t __DefaultAllocTemplate<threads, inst>::_heapSize = 0;

#ifdef __USE_MALLOC
typedef __MallocAllocTemplate<0> alloc;
#else
typedef __DefaultAllocTemplate<true, 0> alloc;
#endif  //__USE_MALLOC

template<class T, class Alloc>
class SimpleAlloc
{
public:
	static T* Allocate(size_t n)
	{
		return 0 == n ? 0 : (T*)Alloc::Allocate(n*sizeof(T));
	}
	static T* Allocate(void)
	{
		return (T*)Alloc::Allocate(n*sizeof(T));
	}

	static void Deallocate(T *p, size_t n)
	{
		if (0 != n) Alloc::Deallocate(p, n * sizeof (T));
	}

	static void Deallocate(T *p)
	{
		Alloc::Deallocate(p, sizeof (T));
	}
};