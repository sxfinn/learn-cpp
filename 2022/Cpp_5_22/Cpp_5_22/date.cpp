#include"date.h"
int Date::MonthDay[13] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
bool IsLeapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return true;
	else
		return false;
}
ostream& operator<<(ostream& out, const Date& d)//定义在外部的
{
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}
int Date::operator-(const Date& d)const
{
	Date d1(*this);
	Date d2(d);
	int flag = -1;
	int ret = 0;
	int num1 = 0;
	int num2 = 0;
	if (d1 > d2)
	{
		d1.swap(d2);
		flag = 1;
	}
	for (int i = 1; i < d1._month; i++)
	{
		num1 += GetDay(d1._year, i);
	}
	num1 += d1._day;
	for (int i = 1; i < d2._month; i++)
	{
		num2 += GetDay(d2._year, i);
	}
	num2 += d2._day;
	for (int i = d1._year; i < d2._year; i++)
	{
		ret += 365;
		if (IsLeapYear(i))
			ret++;
	}
	ret = ret + num2 - num1;
	return ret * flag;
}
void Date::test()
{
	cout << "test()" << endl;
}