#include"date.h"
int main()
{
	test();
	return 0;
}

//#include<iostream>
//using namespace std;

//class Stack
//{
//public:
//	Stack()
//		:
//		_capacity(8)//这里_capacity会被初始化为8而不是4，我们显式初始化默认值无效。
//	{}
//private:
//	//非静态成员变量
//	int _size ;//初始化列表中使用_size(0)初始化
//	int _capacity ;
//	//int* _p ;//初始化列表中使用_size(malloc)初始化
//	char* _pc;
//};
//int main()
//{
//	Stack s;
//	return 0;
//}

//int main()
//{
//	const int a = 1;
//	print(a);
//	/*Date d1;
//	Date d2(2001, 7, 28);
//	cout << d1 << endl;
//	cout << d2 - d1 << endl;*/
//	//cout << d1++ << endl;
//	//cout << typeid(d1).name();
//	return 0;
//}
//// 全局的operator==
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//private:
//	int _year;
//	int _month;
//	int _day;
//};
//// 这里会发现运算符重载成全局的就需要成员变量是共有的，那么问题来了，封装性如何保证？
//// 这里其实可以用我们后面学习的友元解决，或者干脆重载成成员函数。
//bool operator==(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year
//	&& d1._month == d2._month
//		&& d1._day == d2._day;
//}
//int main()
//{
//	Date d1(2018, 9, 26);
//	Date d2(2018, 9, 29);
//	cout << (d1 == d2) << endl;
//	return 0;
//}
//int main()
//{
//	auto a = NULL;
//	auto b = nullptr;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name();
//	return 0;
//}
//class String
//{
//public:
//	String(const char* str = "songxin")
//	{
//		cout << "String(const char* str = \"songxin\")" << endl;
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//	~String()
//	{
//		cout << "~String()" << endl;
//		free(_str);
//		_str = nullptr;
//	}
//private:
//	char* _str;
//};
//class Person
//{
//public:
//	Person()
//		:
//		_age(20),
//		_name()
//	{
//		cout << "Person()" << endl;
//	}
//	
//private:
//	String _name;
//	int _age;
//};
//int main()
//{
//	Person p;
//	return 0;
//}

//Time top(2, 2, 2);
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1, Time& t = top)
//		:
//		_year(year),
//		_month(month),
//		_day(day),
//		_t(t)
//	{}
//	Date(Date& d)
//	{
//
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//int main()
//{
//	Time t(1, 1, 1);
//	Date d1(2001, 7, 28,t);
//	Date d2(d1);
//	return 0;
//}
//class Stack
//{
//public:
//	Stack()
//		:_capacity()
//	{}
//private:	
//	int _size = 0;
//	int _capacity;
//	int* _p = (int*)malloc(sizeof(int) * _capacity);
//};
//int main()
//{
//	Stack s;
//	return 0;
//}
//class A
//{
//public:
//	A() { ++_scount; }
//	A(const A& t) { ++_scount; }
//	static int GetACount() { return _scount; }
//private:
//	static int _scount;
//};
//int A::_scount = 0;
//void TestA()
//{
//	cout << A::GetACount() << endl;
//	A a1, a2;
//	A a3(a1);
//	cout << A::GetACount() << endl;
//}
//
//int main()
//{
//	A a[10];
//	cout << A().GetACount() << endl;
//	return 0;
//}
//class Date
//{
//public:
//	Date(int year)
//		:_year(year)
//	{}
//	explicit Date(int year)
//		:_year(year)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2018);
//	// 用一个整形变量给日期类型对象赋值
//	// 实际编译器背后会用2019构造一个无名对象，最后用无名对象给d1对象进行赋值
//	d1 = 2019;
//	Date d2 = 2020;
//}

//class Time
//{
//public:
//	Time(int hour = 0)
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//class Date
//{
//public:
//	Date()
//		:
//		_a(10),
//		_day(1)//,
//		//_t()
//	{}
//private:
//	int _day = 1;
//	int _a = 10;
//	static int _c;
//	//Time _t;
//};
//int main()
//{
//	Date d;
//	return 0;
//}

//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//	void Print()
//	{
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
//int main() 
//{
//	A aa(1);
//	aa.Print();
//}

//bool IsLeapYear(int year)
//{
//	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//		return true;
//	else
//		return false;
//}
//int MonthDay[13] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
//class Date
//{
//public:
//
//	int GetDay(int year, int month)const
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
//	Date& operator+=(int day)
//	{
//		if (day < 0)
//		{
//			return *this -= -day;
//		}
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
//	Date& operator-=(int day)
//	{
//		if (day < 0)
//		{
//			return *this += -day;
//		}
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
//	void swap(Date& d)
//	{
//		::swap(_year, d._year);
//		::swap(_month, d._month);
//		::swap(_day, d._day);
//	}
//	int operator-(const Date& d)const
//	{
//		Date d1(*this);
//		Date d2(d);
//		int flag = -1;
//		int ret = 0;
//		int num1 = 0;
//		int num2 = 0;
//		if (d1 > d2)
//		{
//			d1.swap(d2);
//			flag = 1;
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
//		return ret * flag;
//	}
//	bool operator>(const Date& d)const
//	{
//		if (_year > d._year || _year == d._year && _month > d._month ||
//			_year == d._year && _month == d._month && _day > d._day)
//			return true;
//		else
//			return false;
//	}
//	bool operator>=(const Date& d)const
//	{
//		return *this > d || *this == d;
//	}
//	bool operator==(const Date& d)const
//	{
//		return _year == d._year && _month == d._month && _day == d._day;
//	}
//	bool operator!=(const Date& d)const
//	{
//		return !(*this == d);
//	}
//	bool operator<(const Date& d)const
//	{
//		return !(*this >= d);
//	}
//	bool operator<=(const Date& d)const
//	{
//		return *this < d || *this == d;
//	}
//	friend ostream& operator<<(ostream& out, const Date& d);
//	friend istream& operator>>(istream& in, Date& d);
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//ostream& operator<<(ostream& out, const Date& d)
//{
//	printf("%0.2d-%0.2d-%0.2d", d._year, d._month, d._day);
//	return out;
//}
//
//istream& operator>>(istream& in, Date& d)
//{
//	printf("%0.2d-%0.2d%0.2d", d._year, d._month, d._day);
//	return in;
//}
//int main()
//{
//
//	int year = 0;
//	int n = 0;
//
//	while (cin >> year >> n)
//	{
//		Date d1(year, 1, 1);
//		cout << d1 + n - 1;
//	}
//	return 0;
//}
//class Solution 
//{
//public:
//	Solution()
//	{
//		++i;
//		ret += i;
//	}
//	int Sum_Solution(int n) 
//	{
//		new Solution[n];
//		return ret;
//	}
//	static int i;
//	static int ret;
//};
//int Solution:: i = 0;
//int Solution::ret = 0;
//int main()
//{
//	int ret = Solution().Sum_Solution(1);
//	cout << ret << endl;
//	return 0;
//}
//int main()
//{
//	Date d1(2011, 4, 12);
//	Date d2(2011, 4, 22);
//	cout << d2 - d1 << endl;
//	/*int num1 = 0;
//	int num2 = 0;
//	while (cin >> num1 >> num2)
//	{
//		int day1 = num1 % 100;
//		int month1 = num1 / 100 % 100;
//		int year1 = num1 / 10000;
//		int day2 = num2 % 100;
//		int month2 = num2 / 100 % 100;
//		int year2 = num2 / 10000;
//		Date d1(year1, month1, day1);
//		Date d2(year2, month2, day2);
//		cout << d2 - d1 << endl;
//	}
//	return 0;*/
//}
//class A
//{
//public:
//	A(int a)
//		:
//		_a(a)
//	{}
//private:
//	int _a;
//};
//int global = 0;
//class B
//{
//public:
//	B(int b , int aa)
//		:
//		_b(b),
//		_aa(aa),
//		_ref(global)
//	{}
//private:
//	const int _b;
//	int& _ref;
//	A _aa;
//};
//int main()
//{
//	B tmp(1, 2);
//	return 0;
//}