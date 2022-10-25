#pragma once
#include<iostream>
#include<vector>
using namespace std;

namespace sx
{
	template<class T, class Container = vector<T>>
	class stack
	{
	public:
		void push(const T& val)
		{
			_con.push_back(val);
		}

		void pop()
		{
			_con.pop_back();
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
			return _con.back();
		}

		T& top()
		{
			return _con.back();
		}

		void swap(stack& st)
		{
			_con.swap(st._con);
		}
	private:
		Container _con;
	};
}