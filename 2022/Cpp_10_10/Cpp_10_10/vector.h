#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;
namespace sx
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		vector<T>()
			:
			_start(nullptr),
			_finish(nullptr),
			_end(nullptr)
		{}
		vector<T>(int n, const T& val)//第一个参数用size_t会有构造函数参数匹配错误的问题。
		{
			while (n--)
			{
				push_back(val);
			}
		}
		template<class Inputinterator>
		vector<T>(Inputinterator first, Inputinterator last)
			:
			_start(nullptr),
			_finish(nullptr),
			_end(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		//vector(iterator start = nullptr, iterator finish = nullptr)
		//	:
		//	_start(nullptr),
		//	_finish(nullptr),
		//	_end(nullptr)
		//{
		//	size_t len = finish - start;//有问题，不一定所有的迭代器都是线性的
		//	if (!len)
		//		return;
		//	_start = new T[finish - start];
		//	iterator tmp = _start;
		//	while (start < finish)
		//	{
		//		*_start = *start;
		//		++start, ++_start;
		//	}
		//	_start = tmp;
		//	_finish = _start + len;
		//	_end = _finish;
		//}
		vector<T>(const vector<T>& v)
			:
			_start(nullptr),
			_finish(nullptr),
			_end(nullptr)
		{
			vector<T> tmp(v._start, v._finish);
			swap(tmp);
		}
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end, v._end);
		}
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}
		~vector<T>()
		{
			if (_start)
			{
				delete[]_start;
				_start = _end = _finish = nullptr;
			}
		}
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin()const
		{
			return _start;
		}
		const_iterator end()const
		{
			return _finish;
		}
		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _end - _start;
		}
		T& operator[](size_t pos)
		{
			assert(pos < size());
			return *(_start + pos);
		}
		const T& operator[](size_t pos)const
		{
			assert(pos < size());
			return *(_start + pos);
		}
		void reserve(size_t n)
		{
			size_t len = size();
			if (n > capacity())
			{
				iterator start = _start;
				iterator tmp = new T[n];
				if (_start)
				{
					while (_start < _finish)
					{
						*(tmp++) = *(_start++);
					}
					delete[]start;
				}
				_start = tmp - len;
				_finish = _start + len;
				_end = _start + n;
			}
		}

		void resize(size_t n, const T& val = T())
		{
			if (n <= size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}
				iterator finish = _finish;
				_finish = _start + n;
				while (finish < _finish)
				{
					*(finish++) = val;
				}
			}
		}
		void push_back(const T& val)
		{
			//size_t capc = capacity();
			//if (_finish == _end)
			//{
			//	reserve(capc == 0 ? 4 : 2 * capc);
			//}
			//*(_finish++) = val;
			insert(end(), 1, val);
		}
		void insert(iterator pos, size_t n, const T& val)
		{
			assert(pos <= _finish && pos >= _start);
			size_t i = pos - _start;
			if (size() + n > capacity())
			{
				reserve(size() + n);
			}
			iterator finish = _finish - 1;
			pos = _start + i;
			while (finish >= pos)
			{
				*(finish + n) = *finish;
				finish--;
			}
			size_t tmp = n;
			while (tmp--)
			{
				*(pos++) = val;
			}
			_finish = _finish + n;
		}
		iterator insert(iterator pos, const T& val)
		{
			size_t i = pos - _start;
			insert(pos, 1, val);
			return _start + i;
		}
		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);
			size_t i = pos - _start;
			iterator tmp = pos + 1;
			while (tmp < _finish)
			{
				*(tmp - 1) = *tmp;
				++tmp;
			}
			_finish--;
			return _start + i;
		}
		iterator erase(iterator first, iterator last)
		{
			assert(first >= _start && last <= _finish);
			size_t i = first - _start;
			while (last < _finish)
			{
				*(first++) = *(last++);
			}
			_finish = first;
			return _start + i;
		}
		void clear()
		{
			_finish = _start;
		}
		void pop_back()
		{
			assert(_finish != _start);
			_finish--;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _end;
	};
}



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