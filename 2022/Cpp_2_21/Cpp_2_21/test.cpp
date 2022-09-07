#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int m[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int main()
{
	int year1 = 0, year2 = 0;
	int month1 = 0, month2 = 0;
	int day1 = 0, day2 = 0;
	int date1 = 0, date2 = 0;
	
	while (scanf("%d", &date1) != EOF && scanf("%d", &date2) != EOF)
	{
		int tmp = 0;
		if (date1 > date2)
		{
			tmp = date1;
			date1 = date2;
			date2 = tmp;
		}
		int ret = 0;
		year1 = date1 / 10000;
		year2 = date2 / 10000;
		month1 = date1 / 100 % 100;
		month2 = date2 / 100 % 100;
		day1 = date1 % 100;
		day2 = date2 % 100;
		if (year1 != year2)
		{
			for (int i = year1 + 1; i < year2; i++)
			{
				if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
				{
					ret += 366;
				}
				else
				{
					ret += 365;
				}
			}
			for (int i = month1; i <= 12; i++)
			{
				ret += m[i];
			}
			ret -= day1;
			if (year1 <= 2 && (year1 % 4 == 0 && year1 % 100 != 0 || year1 % 400 == 0))
			{
				ret++;
			}
			for (int i = 1; i < month2; i++)
			{
				ret += m[i];
			}
			if (year2 > 2 && (year2 % 4 == 0 && year2 % 100 != 0 || year2 % 400 == 0))
			{
				ret += 1;
			}
			ret += day2 + 1;
			cout << ret << endl;
		}
		else
		{
			for (int i = month1; i < month2; i++)
			{
				if (i > 2 && (year2 % 4 == 0 && year2 % 100 != 0 || year2 % 400 == 0))
				{
					ret += 1;
				}
				ret += m[i];
			}
			ret += day2;
			ret -= day1;
			if (month1 <= 2 && (year1 % 4 == 0 && year1 % 100 != 0) || year1 % 400 == 0)
			{
				ret++;
			}
			
			cout << ret + 1 << endl;
		}
	}
	
	return 0;
}
//class S
//{
//public:
//	friend void test();
//	
//	int a = 1;
//};
//
//void test()
//{
//
//}
//int main()
//{
//	S s;
//	test();
//	return 0;
//}
//class S
//{
//public:
//	/*S(int a = 10, int b = 11)
//	{
//		_a = a;
//		_b = b;
//	}*/
//
//
//	/*int _a = 3;
//	int _b = 2;*/
//	int _c;
//};
//
//class L
//{
//public:
//	int a;
//	int b;
//};
//int main()
//{
//	L l(1);
//	cout << l.a;
//	//S s;
//	//cout << s._a << s._b << s._c << endl;
//	//cout << s._c;
//	return 0;
//}
//class S
//{
//public:
//	static void a(int a)
//	{
//		cout << "static" << a << endl;
//	}
//	void b()
//	{
//		this->a(2);
//	}
//		int _a;
//};
//int main()
//{
//	S s;
//	s.b();
//	return 0;
//}
//int main()
//{
//	printf("ddd");
//	return 0;
//}

//class S
//{
//public:
//	S(int a = 1, int b = 2)
//	{
//		_a = a;
//		_b = b;
//		cout << "S构造函数调用结束" << endl;
//	}
//	int _a;
//	int _b;
//};
//class Test
//{
//public:
//	Test(int year = 0, int month = 0)
//		:
//		_year(year),
//		_month(month)
//		//s(3,4)
//	{
//		_year = 100;
//	}
//	int _year;
//	int _month;
//	S s;
//};
//int main()
//{
//	Test t;
//	cout << t.s._a << t.s._b << endl;
//	return 0;
//}
//struct S
//{
//public:
//	S(int a = 1, int b = 2)
//		:
//		_b(b),
//		_a(_b)
//	{
//		c = 0;
//	}
//	void operator<<()
//private:
//	int& _a;
//	int _b;
//	int c;
//};
//int main()
//{
//	S s;
//	cout
//	return 0;
//}
//int main()
//{
//	int a;
//	a = 1;
//	cout << a;
//	return 0;
//}
//class Date
//{
//public:
//	Date(int year = 1, int month = 0, int day = 0) 
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void add(int day);
//	friend void operator<<(ostream& out, const Date& a);
//	friend void operator>>(istream& in, Date& a);
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void operator<<(ostream& out, const Date& a)
//{
//	out << a._year << "-" << a._month << "-" << a._day << endl;
//}
//void operator>>(istream& in, Date& a)
//{
//	in >> a._year >> a._month >> a._day;
//}
//void Date::add(int day)
//{
//	_day += day;
//}
//

//int main()
//{
//	Date a;
//	cout << a;
//	/*a.add(1);
//	cout << a;*/
//	cin >> a;
//	cout << a;
//	return 0;
//}