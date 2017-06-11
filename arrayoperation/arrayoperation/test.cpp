#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#include "arrayoperation.h"
int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(10);
	v.push_back(3);
	Gift gift;
	cout << gift.getValue(v, v.size()) << endl;
	return 0;
}