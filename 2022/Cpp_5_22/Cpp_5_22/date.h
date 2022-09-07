#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;
#include<iostream>
using namespace std;


bool IsLeapYear(int);
//bool IsLeapYear(int year)
//{
//	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//		return true;
//	else
//		return false;
//}
class Date
{
public:
	static int MonthDay[13];
	int GetDay(int year, int month)const
	{
		if (IsLeapYear(year) && month == 2)
			return 29;
		else
			return MonthDay[month];
	}
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year), _month(month), _day(day)
	{
		if (year <= 0 || (month < 0 || month >= 13) || day > GetDay(year, month))
		{
			cout << "日期错误" << endl;
			cout << year << "-" << month << "-" << day << endl;
			exit(-1);
		}
	}
	void swap(Date& d)
	{
		::swap(_year, d._year);
		::swap(_month, d._month);
		::swap(_day, d._day);
	}
	Date& operator+=(int day)
	{
		if (day < 0)
		{
			return *this -= -day;
		}
		_day += day;
		while (_day > GetDay(_year, _month))
		{
			_day -= GetDay(_year, _month);
			_month++;
			if (_month > 12)
			{
				_month = 1;
				_year++;
			}
		}
		return *this;
	}

	Date operator+(int day)
	{
		return Date(*this) += day;
	}
	Date& operator-=(int day)
	{
		if (day < 0)
		{
			return *this += -day;
		}
		_day -= day;
		while (_day < 1)
		{
			_month--;
			if (_month < 1)
			{
				_year--;
				_month = 12;
			}
			_day += GetDay(_year, _month);
		}
		return *this;
	}

	Date operator-(int day)
	{
		return Date(*this) -= day;
	}

	bool operator>(const Date& d)const
	{
		if (_year > d._year || _year == d._year && _month > d._month ||
			_year == d._year && _month == d._month && _day > d._day)
			return true;
		else
			return false;
	}
	bool operator>=(const Date& d)const
	{
		return *this > d || *this == d;
	}
	bool operator==(const Date& d)const
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}
	bool operator!=(const Date& d)const
	{
		return !(*this == d);
	}
	bool operator<(const Date& d)const
	{
		return !(*this >= d);
	}
	bool operator<=(const Date& d)const
	{
		return *this < d || *this == d;
	}

	Date& operator++()
	{
		*this += 1;
		return *this;
	}

	Date operator++(int)
	{
		Date ret(*this);
		*this += 1;
		return ret;
	}

	Date& operator--()
	{
		*this -= 1;
		return *this;
	}

	Date operator--(int)
	{
		Date ret(*this);
		*this -= 1;
		return ret;
	}
	int operator-(const Date& d)const;
	
	
	friend ostream& operator<<(ostream& out, const Date& d);//定义在外部的
	//friend istream& operator>>(istream& in, Date& d);//定义在外部的
private:
	int _year;
	int _month;
	int _day;
};
static void test();
//static void print(const int a);
//void print(const int a)
//{
//	printf("%d ", a);
//	printf("%d ", a);
//	printf("%d ", a);
//	printf("%d ", a);
//	printf("%d ", a);
//	printf("%d ", a);
//	printf("%d ", a);
//}

//ostream& operator<<(ostream& out, const Date& d)//定义在外部的
//{
//	out << d._year << "-" << d._month << "-" << d._day << endl;
//	return out;
//}

//istream& operator>>(istream& in, Date& d)//定义在外部的
//{
//	in >> d._year >> d._month >> d._day;
//	return in;
//}