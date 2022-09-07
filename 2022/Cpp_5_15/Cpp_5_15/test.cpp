#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int MonthDay[13] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };

bool IsLeapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return true;
	else
		return false;
}

class Date
{
public:
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

	/*Date& operator-=(int day)
	{
		while (day--)
		{
			_day--;
			if (_day < 1)
			{
				_month--;
				if (_month < 1)
				{
					_year--;
					_month = 12;
				}
				_day = GetDay(_year, _month);
			}
		}
		return *this;
	}*/
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
	int operator-(const Date& d)const
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

	void print()const
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(2022, 5, 21);
	Date d2 = d1 - (-3);
	int ret = d2 - d1;
	cout << ret << endl;
	d2.print();
	return 0;
}
//class Date
//{
//public:
//	void Display()
//	{
//		cout << "Display ()" << endl;
//		cout << "year:" << _year << endl;
//		cout << "month:" << _month << endl;
//		cout << "day:" << _day << endl << endl;
//	}
//	void Display() const
//	{
//		cout << "Display () const" << endl;
//		cout << "year:" << _year << endl;
//		cout << "month:" << _month << endl;
//		cout << "day:" << _day << endl << endl;
//	}
//private:
//	int _year; // 年
//	int _month; // 月
//	int _day; // 日
//};
//void Test()
//{
//	Date d1;
//	d1.Display();
//	const Date d2;
//	d2.Display();
//}
//int main()
//{
//	Date d1;
//	Date d2(2018, 10, 1);
//	// 这里d1调用的编译器生成operator=完成拷贝，d2和d1的值也是一样的。
//	d1 = d2;
//	d1.Display();
//	d2.Display();
//	return 0;
//}
//int main()
//{
//	Date d1(2001, 7, 28);
//	Date d2(d1);
//	d1.Display();
//	d2.Display();
//	return 0;
//}



class String
{
public:
	String(const char* str = "songxin")
	{
		cout << "String(const char* str = \"songxin\")" << endl;
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		cout << "~String()" << endl;
		free(_str);
		_str = nullptr;
	}
private:
	char* _str;
};
//int main()
//{
//	String s1("tanmei");
//	String s2;
//	s2 = s1;
//	
//	return 0;
//}
class Person
{
public:
	Person()
		:
		_age(20),
		_name()
	{
		cout << "Person()" << endl;
	}
	~Person()
	{
		cout << "~Person()" << endl;
	}
private:
	String _name;
	int _age;
};


class Stack
{
public:
	Stack(int capacity = 4)
		:
		_size(0),
		_capacity(capacity),
		_p(new int[_capacity])
	{
		cout << "Stack(int capacity = 4)" << endl;
	}
	~Stack()
	{
		cout << "~Stack()" << endl;
		if (_p)
		{
			delete[](_p);
		}
		_size = _capacity = 0;
	}
private:	
	int _capacity;
	int _size;
	int* _p;
};



//int main()
//{
//	//Stack s;
//	return 0;
//}

//class S
//{
//public:
//	S(int i = 0, int j = 0)
//		:_i(i),
//		_j(j)
//	{}
//private:
//	const int _i;
//	int _j;
//};
//int main()
//{
//	S s;
//	return 0;
//}
//class Time
//{
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		:_hour(hour),
//		_minute(minute),
//		_second(second)
//	{
//		cout << "Time(int hour = 0, int minute = 0, int second = 0)" << endl;
//	}
//	void DisPlay()
//	{
//		cout << _hour << "-" << _minute << "-" << _second << endl;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//	
//};
//class Date
//{
//public:
//	Date()
//		:
//	_t()
//	{
//		cout << "Date()" << endl;
//	}
//	void Display()
//	{
//		cout << "Date:";
//		cout << _year << "-" << _month << "-" << _day << endl;
//		cout << "Time:";
//		_t.DisPlay();
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//int main()
//{
//	Date d1;
//	d1.Display();
//	cout << int() << endl;
//	return 0;
//}


// 
// 
//1.下面程序能编译通过吗？
// 2.下面程序会崩溃吗？在哪里崩溃
//class A
//{
//public:
//	void PrintA()
//	{
//		cout << (int*) & _b << endl;
//	}
//	void Show()
//	{
//		cout << "Show()" << endl;
//	}
//private:
//	int _a;
//	int _b;
//};
//int main()
//{
//	A* p = nullptr; 
//	p->PrintA();
//	p->Show();
//	//cout << *(p ) << endl;
//}
//class Date
//{
//public:
//	void Display()
//	{
//		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//	}
//	void SetDate(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year; // 年
//	int _month; // 月
//	int _day; // 日
//};
//int main()
//{
//	Date d1, d2;
//	d1.SetDate(2018, 5, 1);
//	d2.SetDate(2018, 7, 1);
//	d1.Display(&d1);
//	//d2.Display();
//	return 0;
//}
//class Person1
//{
//public:
//	void PrintPersonInfo();
//private:
//	char c;
//	int _age;
//};
//
//class Person2
//{
//private:
//	int _age;
//};
//
//class Person3
//{};
//int main()
//{
//	cout << sizeof(Person1) << endl;
//	cout << sizeof(Person2) << endl;
//	cout << sizeof(Person3) << endl;
//	return 0;
//}