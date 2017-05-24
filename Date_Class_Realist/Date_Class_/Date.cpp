#include "Date.h"
void Date::display()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}


int GetMonthDay(int year, int month)
{
	static int MonthDay[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2)
	{
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		{
			return MonthDay[month] - 1;
		}
	}
	     return MonthDay[month];
}



bool Date::IsLegal()
{
	if ((_year >= 0) && (_month > 0) && (_month
		< 13) && (_day>0) && (_day <= GetMonthDay(_year, _month)))
	{
		return true;
	}
	else
	{
		return false;
	}
}


inline Date Date:: operator+(int day)   //不改变初始日期的值
{
	if (day < 0)
	{
		return *this - (-day);
	}
	Date tmp = *this;
	tmp._day += day;
	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
	{
		tmp._day = tmp._day - GetMonthDay(tmp._year, tmp._month);
		if (tmp._month == 12)
		{
			tmp._month = 1;
			tmp._year += 1;
		}
		else
		{
			tmp._month += 1;
		}
	}
	return  tmp;
}

inline Date & Date::operator+=(int day)
{
	*this = *this + day;    //代码的复用
	return *this;            
}

Date Date::operator-(int day)  //减去多少天，不改变初始日期的值
{
	if (day < 0)  //d1-(-100)
	{
		return *this + (-day);
	}
	Date tmp = *this;
	tmp._day = tmp._day - day;
	while (tmp._day <= 0)
	{
		if (tmp._month == 1)
		{
			tmp._month = 12;
			tmp._year -= 1;
		}
		else
		{
			tmp._month -= 1;
		}
		tmp._day = tmp._day + GetMonthDay(tmp._year, tmp._month);
	}
	return tmp;
}

bool Date:: operator==(const Date&d) //比较日期大小
{
	if ((_year != d._year) || (_month != d._month) || (_day != d._day))
	{
		return  false;
	}
	return  true;
}

bool Date:: operator!=(const Date&d) //比较日期大小
{
	return !((*this).operator==(d));
}

Date & Date :: operator-=(int day)  //减去多少天，改变初始日期的值
{
	*this = *this - day;
	return *this;
}

bool Date::operator> (const Date&d)  //比较日期大小
{
	if ((this->_year>d._year) 
		|| ((this->_month>d._month)&&(this->_year==d._year))
	    ||((this->_day>d._day)&&(this->_month==d._month)&&(this->_year==d._year)))          
	{
		return true;
	}
	return false;
}

Date Date:: operator++(int)     //date++；
{
	Date tmp = *this;
	*this += 1;
	return  tmp;
}

Date & Date:: operator++()     //date++；
{
	*this += 1;
	return  *this;
}

int  Date::operator-(const Date&d)   //两个日期相减相差多少天
{
	Date FutureDay;
	Date PastDay;
	int i = 0;
	if (*this > d)
	{
		 FutureDay = *this;
	     PastDay = d;
	}
	else
	{
		 FutureDay = d;
		 PastDay = *this;
	}
	while (FutureDay != PastDay)
	{
		PastDay += 1;
		i++;
	}
	return i;
}
