#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#include "stringoperation.h"
int main()
{
	Solution a;
	a.Insert('a');
	a.Insert('b');
	a.Insert('c');
	a.Insert('a');
	a.Insert('b');
	a.Insert('c');
	a.Insert('e');
	cout << a.FirstAppearingOnce() << endl;
	return 0;
}