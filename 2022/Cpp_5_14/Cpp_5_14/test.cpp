//#include"test.h"
//int main()
//{
//	f(1);
//	return 0;
//}

#include<iostream>
#include<time.h>

using namespace std;

int main()
{
	int* p = NULL;
	int* p1 = 0;
	cout << " " << typeid(NULL).name() << endl;
	cout << " " << typeid(nullptr).name() << endl;
	cout << sizeof(NULL) << endl;
	cout << sizeof(nullptr) << endl;
	return 0;
}
//void func(int)
//{
//	cout << "f(int)" << endl;
//}
//void func(int*)
//{
//	cout << "f(int*)" << endl;
//}
//int main()
//{
//	func(0);
//	func(nullptr);
//	func((int*)NULL);
//	return 0;
//}
//#ifndef NULL
//#ifdef __cplusplus
//#define NULL 0
//#else
//#define NULL ((void *)0)
//#endif
//#endif
//auto Add(int a, int b)
//{
//	return a + b;
//}
//void TestFor(int array[])
//{
//	for (auto& e : array)
//		cout << e << endl;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	TestFor(arr);
//	return 0;
//}

//void  func()
//{
//	cout << "func" << endl;
//}
//
//int main()
//{
//	
//	func();
//	func();
//	func();
//	func();
//	return 0;
//}
//inline void  func(int i)
//{
//	cout << "func(int i)" << endl;
//}
//
//int main()
//{
//	func(1);
//	return 0;
//}
//inline int Add(int a, int b)
//{
//	return a + b;
//}
//
//int main()
//{
//	int x = 10, y = 20;
//	int sum = Add(x, y);
//	cout << sum << endl;
//	return 0;
//}
//int MonthDay[13] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
//
//bool IsLeapYear(int year)
//{
//	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//		return true;
//	else
//		return false;
//}
//
//class Date
//{
//public:
//	int GetDay(int year, int month)
//	{
//		if (IsLeapYear(year) && month == 2)
//			return 29;
//		else
//			return MonthDay[month];
//	}
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year), _month(month), _day(day)
//	{
//		if (year <= 0 || (month < 0 || month >= 13) || day > GetDay(year, month))
//		{
//			cout << "日期错误" << endl;
//			cout << year << "-" << month << "-" << day << endl;
//			exit(-1);
//		}
//	}
//	Date(const Date& d)
//		:_year(d._year),_month(d._month), _day(d._day)
//	{}
//	~Date()
//	{
//		_year = 1;
//		_month = 1;
//		_day = 1;
//	}
//	void swap(Date& d)
//	{
//		::swap(_year, d._year);
//		::swap(_month, d._month);
//		::swap(_day, d._day);
//	}
//	Date& operator =(const Date& d)
//	{
//		Date tmp(d);
//		this->swap(tmp);
//		return *this;
//	}
//	Date& operator+=(int day)
//	{
//		_day += day;
//		while (_day > GetDay(_year, _month))
//		{
//			_day -= GetDay(_year, _month);
//			_month++;
//			if (_month > 12)
//			{
//				_month = 1;
//				_year++;
//			}			
//		}
//		return *this;
//	}
//
//	Date operator+(int day)
//	{
//		return Date(*this) += day;
//	}
//
//	/*Date& operator-=(int day)
//	{
//		while (day--)
//		{
//			_day--;
//			if (_day < 1)
//			{
//				_month--;
//				if (_month < 1)
//				{
//					_year--;
//					_month = 12;
//				}
//				_day = GetDay(_year, _month);
//			}
//		}
//		return *this;
//	}*/
//	Date& operator-=(int day)
//	{
//		_day -= day;
//		while (_day < 1)
//		{
//			_month--;
//			if (_month < 1)
//			{
//				_year--;
//				_month = 12;
//			}
//			_day += GetDay(_year, _month);
//		}
//		return *this;
//	}
//
//	Date operator-(int day)
//	{
//		return Date(*this) -= day;
//	}
//
//	bool operator>(const Date& d)
//	{
//		if (_year > d._year || _year == d._year && _month > d._month ||
//			_year == d._year && _month == d._month && _day > d._day)
//			return true;
//		else
//			return false;
//	}
//	bool operator>=(const Date& d)
//	{
//		return *this > d || *this == d;
//	}
//	bool operator==(const Date& d)
//	{
//		return _year == d._year && _month == d._month && _day == d._day;
//	}
//	bool operator!=(const Date& d)
//	{
//		return !(*this == d);
//	}
//	bool operator<(const Date& d)
//	{
//		return !(*this >= d);
//	}
//	bool operator<=(const Date& d)
//	{
//		return *this < d || *this == d;
//	}
//
//	Date& operator++()
//	{
//		*this += 1;
//		return *this;
//	}
//
//	Date operator++(int)
//	{
//		Date ret(*this);
//		*this += 1;
//		return ret;
//	}
//
//	Date& operator--()
//	{
//		*this -= 1;
//		return *this;
//	}
//
//	Date operator--(int)
//	{
//		Date ret(*this);
//		*this -= 1;
//		return ret;
//	}
//	int operator-(const Date& d)
//	{
//		Date d1(*this);
//		Date d2(d);
//		int ret = 0;
//		int num1 = 0;
//		int num2 = 0;
//		if (d1 > d2)
//		{
//			d1.swap(d2);
//		}
//		for (int i = 1; i < d1._month; i++)
//		{
//			num1 += GetDay(d1._year, i);
//		}
//		num1 += d1._day;
//		for (int i = 1; i < d2._month; i++)
//		{
//			num2 += GetDay(d2._year, i);
//		}
//		num2 += d2._day;
//		for (int i = d1._year; i < d2._year; i++)
//		{
//			ret += 365;
//			if (IsLeapYear(i))
//				ret++;
//		}
//		ret = ret + num2 - num1;
//		if (*this > d)
//			return ret;
//		else
//			return -ret;
//	}
//	
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2008, 2, 29);
//	Date d2(d1);
//	(--d2).print();
//	d2.print();
//	//cout << ret;
//	//bool b = d1 > d2;
//	//cout << b;
//	//cout << (d1 > d2) << endl;
//	//d1 += 4;
//	/*for (int i = 0; i < 100000; i++)
//	{
//		d2 = (d1 - i);
//		d1 = d1 + i;
//		if (d1 != d2)
//		{
//			cout << "filed" << endl;
//			break;
//		}
//	}*/
//	//d2 = d1 - 365 + 365;
//	//cout << (d1 != d2);
//	return 0;
//}

//using namespace std;
//
//class Date
//{
//	bool operator<(const Date& d2)
//	{
//		if (_year < d2._year)
//			return true;
//		else if (_year == d2._year)
//		{
//			if (_month < d2._month)
//				return true;
//			else if (_month == d2._month)
//			{
//				if (_day < d2._day)
//					return true;
//				else
//					return false;
//			}
//			else
//				return false;
//		}
//		else
//			return false;
//	}
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	int a = 9;
//
//	int& ra = a;
//	ra = 99;
//
//	int* pa = &a;
//	*pa = 99;
//	return 0;
//}

//int main()
//{
//	int i = 10;
//	int* p = &i;
//	int& r = i;
//	cout << "sizeofo(p) = " << sizeof(p) << endl;
//	cout << "sizeofo(r) = " << sizeof(r) << endl;
//	return 0;
//}

//int main()
//{
//	int i = 10;
//	int* p = &i;
//	int& r = i;
//	cout << " i = " << i << endl;
//	cout << " p = " << p << endl;
//	cout << " r = " << r << endl;
//	r++;
//	cout << " r++ operation：" << endl;
//	cout << " i = " << i << endl;
//	cout << " p = " << p << endl;
//	cout << " r = " << r << endl;
//	p++;
//	cout << " p++ operation：" << endl;
//	cout << " i = " << i << endl;
//	cout << " p = " << p << endl;
//	cout << " r = " << r << endl;
//	return 0;
//}

//int main()
//{
//	int i = 1;
//	int* p = &i;
//	cout << "p = " << p << endl;
//	cout << "i = " << i << endl;
//	return 0;
//}

//int main()
//{
//	double d = 9.9;
//	const int& a = d;
//	return 0;
//}

//int main()
//{
//	double d = 9.9;
//	const int& a = (int&)d;
//	cout << d << endl;
//	cout << a << endl;
//	return 0;
//}

//int main()
//{
//	double d = 9.9;
//	const int& a = d;
//	cout << "d = " << d << endl;
//	cout << "a = " << a << endl;
//	return 0;
//}
////int main()
//{
//	int a = 9;
//
//	int& ra = a;
//	ra = 99;
//
//	int* pa = &a;
//	*pa = 99;
//	return 0;
//}

//int main()
//{
//	double d = 9.0;
//	int const & a = d;
//	cout << a << endl;
//	return 0;
//}
//struct A
//{
//	A()
//	{
//		memset(arr, 0, sizeof(arr));
//	}
//	int arr[1000];
//};
//A a;
//A TestFunc1()
//{
//	return a;
//}
//
//A& TestFunc2()
//{
//	return a;
//}
//
//void TestEfficiency()
//{
//	size_t start1 = clock();
//	for (int i = 0; i < 1000000; i++)
//	{
//		TestFunc1();
//	}
//	size_t end1 = clock();
//	
//	size_t start2 = clock();
//	for (int i = 0; i < 10000; i++)
//	{
//		TestFunc2();
//	}
//	size_t end2 = clock();
//
//	cout << "值返回 void TestFunc1(A p)：" << end1 - start1 << endl;
//	cout << "引用返回 void TestFunc1(A& p)：" << end2 - start2 << endl;
//}
//
//int main()
//{
//	TestEfficiency();
//	return 0;
//}
//using namespace std;
//
//class T
//{
//public:
//	T(int a = 1)
//	{
//		cout << "T()" << endl;
//		_a = a;
//	}
//	int _a;
//};
//
//class S
//{
//public:
//	S(int year = 0)
//		:
//		_year(year),
//		t()
//	{
//
//	}
//	int _year;
//	T t;
//};
//
//int main()
//{
//	S s;
//	
//	cout << int();
//	return 0;
//}