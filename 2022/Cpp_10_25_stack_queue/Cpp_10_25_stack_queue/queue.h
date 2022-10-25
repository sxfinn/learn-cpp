#pragma once
#include<iostream>
#include<list>
#include<vector>
using namespace std;
namespace sx
{
	template<class T, class Container = list<T>>
	class queue
	{
	public:
		void push(const T& val)
		{
			_con.push_back(val);
		}

		void pop()
		{
			_con.pop_front();
		}

		bool empty()const
		{
			return _con.empty();
		}

		size_t size()const
		{
			return _con.size();
		}

		const T& front()const
		{
			return _con.front();
		}

		T& front()
		{
			return _con.front();
		}
		const T& back()const
		{
			return _con.back();
		}
		T& back()
		{
			return _con.back();
		}

		void swap(queue& que)
		{
			_con.swap(que._con);
		}
	private:
		Container _con;
	};

}