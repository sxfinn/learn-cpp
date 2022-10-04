#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

class S
{
public:
	S(const char* str = "")
		:
		_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
	}
	~S()
	{
		if (_str)
			delete[]_str;
	}
	S(const S& s)
		:
		_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	void swap(S& s)
	{
		char* tmp = _str;
		_str = s._str;
		s._str = tmp;
	}

	/*S& operator=(const S& s)
	{
		S tmp(s);
		swap(tmp);
		return *this;
	}*/

	S& operator=(const S& s)
	{
		if (strlen(_str) < strlen(s._str))
		{
			if(_str)
				delete[]_str;
			_str = new char[strlen(s._str) + 1];
		}
		strcpy(_str, s._str);
		return *this;
	}
	/*S& insert(size_t pos, const char* s)
	{
		size_t len = strlen(s);
		if (len + _size > _capacity)
		{
			reserve(len + size);
		}

		for (int i = _size + len; i >= pos + len; --i)
		{
			_str[i] = _str[i - len];
		}
		strpcy(_str + pos, s);
		return *this;
	}*/
	void print()
	{
		cout << _str << endl;
	}
private:
	char* _str;
};
static int f = 1;
void test(int t = f)
{
	//cout << t << endl;
	cout << "" << "haha";
}

int main()
{
	test(1);
	cout << f << endl;
	/*f = 2;
	cout << f;
	string s("hello");
	cout << s.size();
	cout << s << endl;
	s += '\0';
	cout << " " << s.size();
	cout << s << endl;*/

	/*S s1("hello");
	S s2(s1);
	S s3;
	s3 = s1;
	s1.print();
	s2.print();
	s3.print();

	char* ret = new char[0];
	printf("%p", ret);*/
	return 0;
}


//class S
//{
//public:
//	S(int x, int y)
//		:
//		_x(x),
//		_y(y)
//	{
//		cout << "struct" << endl;
//	}
//	void print()
//	{
//		cout << _x << _y << endl;
//	}
//private:
//	int _x;
//	int _y;
//};
//
//int main()
//{
//	S s = S{ 1,2 };
//	s.print();
//	//string s("hello");
//	//s += "world";
//	//cout << s << endl;
//	return 0;
//}

//int main()
//{
//	for (int i = 0; i < 1000; i++)
//	{
//		if ((i & (~6)) == (((i ^ 6) ^ (i ^ 6)) & 6))
//			;
//		else
//		{
//			printf("error\n");
//		}
//	}
//	return 0;
//}