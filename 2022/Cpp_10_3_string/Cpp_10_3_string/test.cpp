#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include<string>
using namespace std;


namespace sx
{
	class string
	{
	public:
		string(const char* str = "")
			:
			_size(strlen(str)),
			_capacity(_size)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		//string(const string& s)//传统写法
		//	:
		//	_size(s._size),
		//	_capacity(s._capacity)
		//{
		//	_str = new char[_capacity + 1];
		//	strcpy(_str, s._str);
		//}

		string(const string& s)//这种好像有点问题，遇到size比'\0'的位置大的
			:
			_str(nullptr),
			_size(0),
			_capacity(0)
		{
			string tmp(s._str);
			swap(tmp);
		}

		//string& operator=(const string& s)//传统版本
		//{
		//	if (s._capacity > _capacity)
		//	{
		//		reserve(s._capacity);
		//	}
		//	strcpy(_str, s._str);
		//	_size = s._size;
		//	return *this;
		//}

		string& operator=(string s)
		{
			swap(s);
			return *this;
		}
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}
		~string()
		{
			delete[]_str;
			_size = _capacity = 0;
			_str = nullptr;
		}

		void reserve(size_t n = 0)
		{
			assert(n >= 0);
			if (n >= _size || n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[]_str;
				_str = tmp;
				_capacity = n;
			}
		}

		void resize(size_t n, char c = '\0')
		{
			if (n > _capacity)
			{
				reserve(n);
				_capacity = n;
				for (int i = _size; i < n; i++)
				{
					_str[i] = c;
				}
				_size = n;
				_str[_size] = '\0';
			}
			else
			{
				if (n > _size)
				{
					for (int i = _size; i < n; i++)
					{
						_str[i] = c;
					}
					
				}
				_size = n;
				_str[_size] = '\0';
			}
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void print()
		{
			cout << _str << endl;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}

void test1()
{
	sx::string s1;
	sx::string s2("songxin");
	s1.print();
	s2.print();
	sx::string s3(s2);
	s3.print();
}

void test2()
{
	sx::string s1("songxin");
	s1.reserve(10);
}

void test3()
{
	std::string s1("hello");
	s1.reserve(200);
	s1.resize(4, 'x');
	cout << s1;
}
void test4()
{
	sx::string s1("songxin");
	s1.reserve(20);
	s1.resize(3, 'x');
}

void test5()
{
	sx::string s1("songxin");
	sx::string s2;
	s2 = s1;
	cout << s1[2];
}
int main()
{
	test5();
	//test4();
	//test3();
	//test2();
	//test1();
	return 0;
}