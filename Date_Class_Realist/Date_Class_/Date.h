#define _CRT_SECURE_NO_WARNINGS 
#ifndef  __DATE_CLASS__
#define __DATE_CLASS__

#include <iostream>
#include <windows.h>
#include <assert.h>
using namespace std;
class Date
{
public:
	Date(int year=1995,int month=5 ,int day=6)
	:_year(year)
	, _month(month)
	, _day(day)
	{
		assert(IsLegal());
	}

	void display();  //打印日期
 
	Date operator+(int day);  //加上多少天，不改变初始日期的值

	Date & operator+=(int day);  //加上多少天，改变初始日期的值

	Date operator-(int day);  //减去多少天，不改变初始日期的值

	Date & operator-=(int day);  //减去多少天，改变初始日期的值

	bool operator>(const Date&d);  //比较日期大小

	bool operator==(const Date&d);  //比较日期大小

	bool operator!=(const Date&d);  //比较日期大小

	Date operator++(int);     //date++；

	Date & operator++();       //++date;

	int operator-(const Date&d);   //两个日期相减相差多少天

	bool IsLegal();    //判断日期是否合法
private:
	int _year;
	int _month;
	int _day;
};


int GetMonthDay(int year, int day);  //判读一个月到底有多少天




#endif // __DATE_CLASS__

