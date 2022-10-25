#pragma once
#include<iostream>
#include<vector>
#include<assert.h>

using namespace std;
namespace sx
{
	template<class T>
	struct less
	{
		bool operator()(const T& left, const T& right)
		{
			return left < right;
		}
	};

	template<class T>
	struct greater
	{
		bool operator()(const T& left, const T& right)
		{
			return left > right;
		}
	};

	template<class T, class Container = vector<T>, class Cmp = less<T>>
	class priority_queue
	{
	public:
		priority_queue(Cmp cmp = Cmp())
			:_cmp(cmp)
		{}
		
		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push(*first);
				++first;
			}
		}

		void adjustup(size_t pos)
		{
			size_t child = pos;
			size_t parent = (child - 1) / 2;
			while (child > 0)
			{
				if (_cmp(_con[parent], _con[child]))
					std::swap(_con[child], _con[parent]);
				else
					break;
				child = parent;
				parent = (child - 1) / 2;
			}
		}
		void push(const T& val)
		{
			_con.push_back(val);
			adjustup(_con.size() - 1);
		}

		void adjustdown(size_t pos)
		{
			size_t parent = pos;
			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && _cmp(_con[child] , _con[child + 1]))
					++child;
				if (_cmp(_con[parent], _con[child]))
					std::swap(_con[parent], _con[child]);
				else
					break;
				parent = child;
				child = parent * 2 + 1;
			}
		}
		void pop()
		{
			assert(!_con.empty());
			std::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjustdown(0);
		}

		bool empty()const
		{
			return _con.empty();
		}

		size_t size()const
		{
			return _con.size();
		}

		const T& top()const
		{
			return _con.top();
		}
	private:
		Container _con;
		Cmp _cmp;
	};
}