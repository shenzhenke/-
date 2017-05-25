#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <assert.h>
using namespace std;
typedef int Datetype;
class Seqlist
{
public:
	Seqlist();  

	Seqlist(Datetype d);

	Seqlist(const Seqlist &s);

	Seqlist &  operator=(const Seqlist &s);

	~Seqlist(); 

	Seqlist  Push_Back(Datetype d);  

	Seqlist & Push_Front(Datetype d);

	Seqlist & Pop_Front();

	Seqlist & Pop_Back();

	Seqlist & Insert(size_t pos, Datetype d);
	
	int  Find( Datetype d);

	Seqlist & Erase(size_t pos);

	Seqlist & Remove(Datetype d);

	Seqlist & Inverse();

	Seqlist & Sort();

	void  Check_Capacitty();

	void Display();
private:
	Datetype * _a;
	size_t _size;
	size_t _capacity;
};
