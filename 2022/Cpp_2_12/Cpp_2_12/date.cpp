#include"date.h"
inline int getday(int year, int month)
{
	int m[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int day = m[month];
	if (month == 2 && (year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		day = 29;
	}
	return day;
}


Date::Date(int year, int month, int day)
{
	if (year > 0 && month > 0 && month < 13 && day > 0 && day <= getday(year, month))
	{
		cout << "初始化成功" << endl;
	}
	else
	{
		cout << "日期格式有误" << endl;
	}
	_year = year;
	_month = month;
	_day = day;
}

void Date::print()
{
	cout << _year << "年" << _month << "月" << _day << "日" << endl;
}

Date& Date::operator+=(int day)
{
	_day = _day + day;
	while (_day > getday(_year, _month))
	{
		_day -= getday(_year, _month);
		_month++;
		if (_month > 12)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}

Date Date::operator+(int day)
{
	Date a(*this);
	a += day;
	return a;
}

Date& Date::operator-=(int day)
{

	if (day < 0)
	{
		day = -day;

		*this += (day);
		return *this;
	}
	_day -= day;
	while (_day <= 0)
	{
		_month--;
		_day += getday(_year, _month);
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
	}
	return *this;
}

Date Date::operator-(int day)
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}

Date& Date::operator++()
{
	(*this) += 1;
	return *this;
}
Date Date::operator++(int)
{
	Date tmp(*this);
	(*this) += 1;
	return tmp;
}
