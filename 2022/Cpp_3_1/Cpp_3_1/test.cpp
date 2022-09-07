#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//string类的模拟
namespace sx
{
	class string
	{
		typedef char* iterator;
	public:
		string(const char* str = "")//默认构造函数
			:
			_str(new char[strlen(str) + 1]),
			_size(strlen(str)),
			_capacity(_size)
		{
			strcpy(_str, str);
		}
		string(const string& s)//拷贝构造函数
			:
			_str(nullptr),
			_size(s._size),
			_capacity(s._capacity)
		{
			string tmp(s._str);
			std::swap(_str, tmp._str);
		}
		string operator=(string s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
			return *this;
		}
		~string()//析构函数
		{
			_size = 0;
			_capacity = 0;
			delete[](_str);
			_str = nullptr;
		}
		size_t size()
		{
			return _size;
		}
		size_t capacity()
		{
			return _capacity;
		}
		void print()
		{
			cout << _str << endl;
		}
		char& operator[](size_t pos)
		{
			return _str[pos];
		}
		void swap(string& s2)
		{
			std::swap(_str, s2._str);
			std::swap(_size, s2._size);
			std::swap(_capacity, s2._capacity);
		}
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		void resize(size_t len, char ch = '\0')
		{
			if (len > _size)
			{
				char* tmp = new char[len + 1];
				strcpy(tmp, _str);
				_str = tmp;
				while (_size < len)
				{
					_str[_size] = ch;
					++_size;
				}
				_str[_size] = '\0';
				_capacity = _size;
			}
			else
			{
				_str[_size] = '\0';
				_size = len;
			}
			
		}
		void reserve(size_t len)
		{
			if (len > _capacity)
			{
				//string tmp(*this);
				char*tmp = new char[len + 1];
				_capacity = len;
				memcpy(tmp, _str, _size + 1);
				_str = tmp;
			}
		}
		void pushback(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity * 2);
			}
			_str[_size++] = ch;
			_str[_size] = '\0';
		
		}
		void append(const string& s)
		{
			size_t len = strlen(s._str) + _size;
			if (len > _capacity)
			{
				reserve(len);
			}
			strcpy(_str + _size, s._str);
			_size = len;
		}
		string operator+=(const string& s)
		{
			append(s);
			return *this;
		}
		string operator+=(char ch)
		{
			pushback(ch);
			return *this;
		}
		bool operator>(string& s)
		{
			return strcmp(_str, s._str) > 0;
		}
		bool operator<(string& s)
		{
			return strcmp(_str, s._str) < 0;
		}
		bool operator==(string& s)
		{
			return strcmp(_str, s._str) == 0;
		}
		bool operator!=(string& s)
		{
			return !(*this == s);
		}
		friend ostream& operator<<(ostream& out, string& s);
		friend istream& operator>>(istream& in, string& s);
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
	
	ostream& operator<<(ostream& out, string& s)
	{
		cout << s._str;
		return out;
	}
	istream& operator>>(istream& in, string& s)
	{
		cin >> s._str;
		return in;
	}
}
int main()
{
	sx::string s1("songxin");
	sx::string s2("sangsang");
	sx::string s3("songxin");
	if (s1 > s2)
	{
		cout << " s1 > s2 " << endl;
	}
	if (s1 == s3)
	{
		cout << "s1 == s3" << endl;
	}
	if (s1 != s3)
	{
		cout << "s1 != s3";
	}

	/*sx::string s1("hello");
	cin >> s1;
	s1 += " world";
	s1[10] = '0';
	cout << s1;*/


	//sx::string s2("dodo");
	//s1 += s2;
	
	//cout << s1 << s2;
	//s1.resize(20,'\0');
	//s1 += "a";
	//s1 += s2;
	//s1 += "oo";
	//s1 += 'a';
	/*for (auto e : s1)
	{
		cout << e;
	}*/
	//cout << endl;
	//s1 += "hehe";
	//cout << s1;
	//cout << s1 << endl;
	/*for (auto e : s1)
	{
		cout << e;
	}*/
	//cout << s1;
	//s1 += 'a';
	//s1.print();
	//s1 += " world";
	//s1 += s2;
	//s1.print();
	//sx::string s2("hehe");
	////s1.swap(s2);
	//s1 = s2;
	//s1.print();
	//s2.print();
	//char ret = s1[1];
	//cout << ret;
	//cout << endl;
	return 0;
}
//class S
//{
//public:
//	S()
//		:
//		a(11),
//		b(1)
//	{}
//private:
//	static int a;
//	int b;
//};
//int S::a = 10;
//int main()
//{
//	S s;
//	
//	return 0;
//}