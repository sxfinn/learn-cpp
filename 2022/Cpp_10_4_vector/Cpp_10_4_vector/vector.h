#pragma once
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
		vector()
			:
			_start(nullptr),
			_finish(nullptr),
			_end(nullptr)
		{}
		vector(size_t n, const T& val)
		{
			while (n--)
			{
				push_back(val);
			}
		}
		template<class Inputinterator>
		vector(Inputinterator first, Inputinterator last)
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
		vector(vector& v)
		{
			vector tmp(v._start, v._finish);
			swap(tmp);
		}
		void swap(vector& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end, v._end);
		}
		vector& operator=(vector v)
		{
			swap(*this, v);
		}
		~vector()
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

		void resize(size_t n, const T& val = 0)
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
		iterator insert(iterator pos, size_t n, const T& val)
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
				*(finish + n)= *finish;
				finish--;
			}
			size_t tmp = n;
			while (tmp--)
			{
				*(pos++) = val;
			}
			_finish = _finish + n;
			return _start;
		}
		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);
			iterator tmp = pos + 1;
			while (tmp < _finish)
			{
				*(tmp - 1) = *tmp;
			}
			_finish--;
			return _start;
		}
		iterator erase(iterator first, iterator last)
		{
			while (last < _finish)
			{
				*(first++) = *(last++);
			}
			_finish = first ;
			return _start;
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