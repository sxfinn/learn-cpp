#include<iostream>
#include<assert.h>
using namespace std;
//模拟实现vector

//当vector的每个元素仍然是需要深拷贝的类型，例如string，则还需要更深一层的拷贝
//例如vector<int>，我们在构造另一个vector<int>类型的对象时，需要深拷贝另一块有着n个int的空间
// ，而对于其中存在的int，直接浅拷贝即可

//而对于vector<string>,我们在构造另一个vector<string>类型的对象时，需要深拷贝另一块有着n个string的空间
//并且对于每个string并不是简单的植拷贝，而是深拷贝，使每个string所指向的空间不会重叠而产生多次delete
// 等错误
//
namespace sx
{
	template<class T>
	
	class vector
	{
	public:
		typedef T* iterator;
		vector()
			:
			_start(nullptr),
			_finish(nullptr),
			_endof_storage(nullptr)
		{}
		vector(vector<T>& v)
			:
			_start(new T[v.size()]),
			_finish(_start + v.size()),
			_endof_storage(_start + v.capacity())
		{
			for (int i = 0; i < size(); i++)
			{
				*(_start + i) = v[i];
			}
		}
		~vector()
		{
			delete[](_start);
			_start = nullptr;
			_finish = nullptr;
			_endof_storage = nullptr;
		}
		void reserve(size_t n)
		{
			size_t sz = size();
			if (n > sz)
			{
				T* tmp = new T[n];
				if (_start)
				{
					for (int i = 0; i < size(); i++)
					{
						*(tmp + i) = *(_start + i);
					}
					delete[](_start);
				}
				_start = tmp;
				_finish = _start + sz;
				_endof_storage = _start + n;
			}
		}
		void push_back(T data)
		{
			size_t sz = size();
			size_t len = capacity();
			if (sz == len)
			{
				size_t newcapacity = (len == 0) ? 4 : 2 * len;
				reserve(newcapacity);
			}
			*_finish = data;
			_finish++;
		}
		iterator insert(iterator pos, T val)
		{
			assert(pos < end() && pos >= begin());
			size_t cur = pos - begin();			
			if (_finish == _endof_storage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}
			iterator tmp = _finish;
			pos = _start + cur;
			while (tmp != pos)
			{
				*(tmp) = *(tmp - 1);
				tmp--;
			}
			*pos = val;
			_finish++;
			return pos;
		}
		void pop_back()
		{
			assert(!empty());
			_finish--;
		}
		size_t size()
		{
			return _finish - _start;
		}
		size_t capacity()
		{
			return _endof_storage - _start;
		}
		void print()
		{
			for (int i = 0; i < size(); i++)
			{
				cout << *(_start + i) << " ";
			}
			cout << endl;
		}
		void swap(vector<T>& v)
		{
			::swap(_start, v._start);
			::swap(_finish, v._finish);
			::swap(_endof_storage, v._endof_storage);
		}
		vector<T>& operator = (vector<T> v)
		{
			swap(v);
			return *this;
		}
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		T& operator[](size_t pos)
		{
			size_t sz = size();
			assert(pos < sz);
			return *(_start + pos);	
		}
		void resize(size_t sz, T data = T())
		{
			size_t cur_sz = size();
			size_t len = capacity();
			if (sz > len)
				reserve(sz);
			while (cur_sz < sz)
			{
				*(_start + cur_sz) = data;
				cur_sz++;
			}
			_finish = _start + sz;
		}
		bool empty()
		{
			return _start == _finish;
		}
		iterator find(iterator it, T data)
		{
			while (it < _finish)
			{
				if (*it == data)
					return it;
				it++;
			}
			return _finish;
		}
		iterator erase(iterator it)
		{
			iterator ret = it;
			assert(it < _finish && it >= _start);
			while (it < end() - 1)
			{
				*(it) = *(it + 1);
				++it;
			}
			_finish--;
			return ret;
		}
	private:
		T* _start;
		T* _finish;
		T* _endof_storage;
	};
}
int main()
{
	sx::vector<string> s1;
	s1.push_back("hello");
	s1.push_back(" world");
	s1.resize(6, "hehe");
	sx::vector<string> s2(s1);
	s1.print();
	s2.print();
	return 0;
}
//int main()
//{
//	sx::vector<int> v1;
//	v1.push_back(1);
//	v1.insert(v1.begin(), 2);
//	v1.insert(v1.begin(), 2);
//	v1.insert(v1.begin(), 2);
//	v1.insert(v1.begin(), 3);
//	v1.insert(v1.begin(), 4);
//	v1.insert(v1.begin(), 5);
//	v1.insert(v1.begin(), 6);
//	for (auto e : v1)
//	{
//		cout << e << ' ';
//	}
//	cout << endl;
//	sx::vector<int>::iterator ret = v1.find(v1.begin(), 3);
//	sx::vector<int>::iterator it = v1.begin();
//	while (it < v1.end())
//	{
//		if(*it % 2 == 0)
//			 it = v1.erase(it);
//		else
//			it++;
//	}
//	for (auto e : v1)
//	{
//		cout << e << ' ';
//	}
//	//v1.erase(ret);
//	/*for (auto e : v1)
//	{
//		cout << e << ' ';
//	}*/
//	return 0;
//}
//int main()
//{
//	//int a = int();
//	//cout << a;
//	sx::vector<int> v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	//v1.pop_back();
//	//v1.resize(4, 10);
//	//v1.resize(6, 11);
//	v1.resize(10, 10);
//	for (auto e : v1)
//		cout << e << " ";
//	return 0;
//}
//int main()
//{
//	sx::vector<int> v1;
//	sx::vector<int> v2;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.insert(v1.begin(), 3);
//	v1.insert(v1.begin(), 3);
//	v1.insert(v1.begin(), 10);
//	v1.insert(v1.begin(), 10);
//	for (auto e : v1)
//	{
//		cout << e << " ";
//	}
//	/*v2.push_back(3);
//	v2.push_back(2);
//	v2.push_back(3);
//	v2.push_back(2);
//	v1.print();
//	v2.print();
//	v1.swap(v2);
//	v1.print();
//	v2.print();*/
//	
//	return 0;
//	//v1.print();
//	//cout << endl;
//	//v2.print();
//	
//}
//template<class T>
//vector<T>& opeartor = (vector<T> v)
//{
//	swap(v);
//	return *this;
//}


//int main()
//{
//	
//	int a = 0;
//	int& b = a;
//	int* pa = &a;
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	vector<int>::iterator it = v.begin();
//	//v.insert(it, 2);
//	vector<int>::iterator pos = v.erase(it);
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	*it = 0;
//	cout << *pos;
//	
//	return 0;
//}