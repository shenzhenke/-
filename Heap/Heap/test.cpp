#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include  <vector>
using namespace std;
#include"topK.hpp"
#include "Heap.hpp"
#include "HeapSort.hpp"
int main()
{
	TestHeap();
	TestHeapSearchTopK();
	TestHeapSort();
	return 0;
}