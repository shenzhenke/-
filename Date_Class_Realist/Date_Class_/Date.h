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

	void display();  //��ӡ����
 
	Date operator+(int day);  //���϶����죬���ı��ʼ���ڵ�ֵ

	Date & operator+=(int day);  //���϶����죬�ı��ʼ���ڵ�ֵ

	Date operator-(int day);  //��ȥ�����죬���ı��ʼ���ڵ�ֵ

	Date & operator-=(int day);  //��ȥ�����죬�ı��ʼ���ڵ�ֵ

	bool operator>(const Date&d);  //�Ƚ����ڴ�С

	bool operator==(const Date&d);  //�Ƚ����ڴ�С

	bool operator!=(const Date&d);  //�Ƚ����ڴ�С

	Date operator++(int);     //date++��

	Date & operator++();       //++date;

	int operator-(const Date&d);   //�������������������

	bool IsLegal();    //�ж������Ƿ�Ϸ�
private:
	int _year;
	int _month;
	int _day;
};


int GetMonthDay(int year, int day);  //�ж�һ���µ����ж�����




#endif // __DATE_CLASS__

