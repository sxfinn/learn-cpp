#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;

namespace sx
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

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
		string(const string& s)//这种并不严谨有点问题，遇到size比'\0'的位置大的就只会拷贝'\0'以前的
			:
			_str(nullptr),
			_size(0),
			_capacity(0)
		{
			string tmp(s._str);
			swap(tmp);
		}

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

		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator begin()const
		{
			return _str;
		}
		const_iterator end()const
		{
			return _str + _size;
		}
		~string()
		{
			delete[]_str;
			_str = nullptr;
			_size = _capacity = 0;
		}
		void reserve(size_t n = 0)
		{
			if (n > _capacity)
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
			assert(n >= 0);
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
		const char& operator[](size_t pos)const
		{
			assert(pos < _size);
			return _str[pos];
		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			for (size_t i = _size + len; i > pos + len - 1; --i)
			{
				_str[i] = _str[i - len];
			}
			strncpy(_str + pos, str, len);
			_size += len;
			return *this;
		}
		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_capacity == _size)
			{
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}
			for (int i = _size + 1; i > pos; --i)
			{
				_str[i] = _str[i - 1];
			}
			_str[pos] = ch;
			++_size;
			return *this;
		}

		void push_back(char ch)
		{
			insert(_size, ch);
		}
		string& append(const char* str)
		{
			insert(_size, str);
			return *this;
		}
		size_t find(char ch, size_t pos)const
		{
			while (pos < _size)
			{
				if (_str[pos] == ch)
					return pos;
				++pos;
			}
			return npos;
		}

		size_t find(const char* str, size_t pos)const
		{
			char* ret = strstr(_str + pos, str);
			if (ret != nullptr)
				return ret - _str;
			else
				return npos;
		}

		bool empty()const
		{
			return _size == 0;
		}
		void clear()
		{
			resize(0);
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		string operator+(char ch)const
		{
			return string(*this) += ch;
		}
		string operator+(const char* str)const
		{
			return string(*this) += str;
		}
		string& erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
				return *this;
			}
			for (int i = pos + len; i <= _size; ++i)
			{
				_str[i - len] = _str[i];
			}
			_size -= len;
			return *this;
		}
		const char* c_str()const
		{
			return _str;
		}
		size_t size()const
		{
			return _size;
		}
		
		size_t capacity()const
		{
			return _capacity;
		}
		friend ostream& operator<<(ostream& out, const string& s);
		friend istream& operator>>(istream& in, string& s);
		static const size_t npos;
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
	const size_t string::npos = -1;
	ostream& operator<<(ostream& out, const string& s)
	{
		for (auto ch : s)
		{
			out << ch;
		}
		return out;
	}

	istream& operator>>(istream& in, string& s)
	{
		s.clear();
		char buffer[128] = { 0 };
		char ch = 0;
		size_t size = 0;
		while ((ch = getchar()) != ' ' && ch != '\n')
		{
			buffer[size++] = ch;
			if (size == 127)
			{
				s += buffer;
				memset(buffer, 0, sizeof(buffer));
				size = 0;
			}
		}
		s += buffer;
		return in;
	}
	bool operator>(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) > 0;
	}
	bool operator==(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) == 0;
	}
	bool operator>=(const string& s1, const string& s2)
	{
		return (s1 > s2 || s1 == s2);
	}
	bool operator<(const string& s1, const string& s2)
	{
		return !(s1 >= s2);
	}
	bool operator<=(const string& s1, const string& s2)
	{
		return !(s1 > s2);
	}
	bool operator!=(const string& s1, const string& s2)
	{
		return !(s1 == s2);
	}
}