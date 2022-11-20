#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<list>
using namespace std;
template<class T1, class T2>
void test(T1* p1, T2* p2)
{
	cout << "test<T1*, T2*>" << endl;
}

template<class T1, class T2>
void test/*<T1, T2>*/(T1 t1, T2 t2)//提示非法使用显示模板参数
{
	cout << "test<T1, T2>" << endl;
}

template<>
void test<char, int>(char c, int i)//可以正常跑
{
	cout << "test<char, int>" << endl;
}
template<class T1>
void test<double, T1>(double t, T1 d)
{
	cout << "test<double, T1>" << endl;
}
int main()
{
	test<char,int>('a', 1);//test<char, int>
	test(1.2, 'a');//test<double, T1>
	test<double, char>(1.2, 'a');//test<T1, T2>
	return 0;
}



//template<typename Type>
//
//Type Max(const Type& a, const Type& b)
//
//{
//
//	cout << "This is Max<Type>" << endl;
//
//	return a > b ? a : b;
//
//}
//
//template<>
//
//int Max<int>(const int& a, const int& b)
//
//{
//
//	cout << "This is Max<int>" << endl;
//
//	return a > b ? a : b;
//
//}
//
//template<>
//
//char Max<char>(const char& a, const char& b)
//
//{
//
//	cout << "This is Max<char>" << endl;
//
//	return a > b ? a : b;
//
//}
//
//int Max(const int& a, const int& b)
//
//{
//
//	cout << "This is Max" << endl;
//
//	return a > b ? a : b;
//
//}
//
//int main()
//
//{
//
//	Max(10, 20);
//
//	Max(12.34, 23.45);
//
//	Max('A', 'B');
//
//	Max<int>(20, 30);
//
//	return 0;
//
//}



//template<class T&>
//void test1(T* t)
//{
//	cout << t << endl;
//}
//
//int main()
//{
//	int a = 0;
//	int* pa = &a;
//	test1(pa);
//	return 0;
//}
namespace sx
{
	template<class T1, class T2>
	class S
	{
	public:
		S()
		{
			cout << "class S<T1, T2>" << endl;
		}
	};
	template<>
	class S<char, int>
	{
	public:
		S()
		{
			cout << "class S<char, int>" << endl;
		}
	};
	template<class T>
	class S<T, char>
	{
	public:
		S()
		{
			cout << "class S<T, char>" << endl;
		}
	};

	template<class T1, class T2>
	class S<T1&, T2&>
	{
	public:
		S()
		{
			cout << "class S<T1&, T2&>" << endl;
		}
	};

}
//int main()
//{
//	sx::S<int, char> s;
//	return 0;
//}
template<class T1&, class T2&>
class F
{
public:
	F()
	{
		cout << "F<T1, T2>" << endl;
	}
};
//template<class T1, class T2>
//class F<T1*, T2*>
//{
//public:
//	F()
//	{
//		cout << "F<T1, T2>" << endl;
//	}
//};
//int main()
//{
//	int a = 0;
//	int* pa = &a;
//	//F<int&, int&> f;
//	return 0;
//}
namespace sx
{
	template<class T>
	void swap(T& t1, T& t2)
	{
		T tmp = t1;
		t1 = t2;
		t2 = tmp;
	}
}
////template<class T1, class T2>
////void test(T1* p1, T2* p2)
////{
////	cout << "test<T1*, T2*>" << endl;
////}
//template<class T1, class T2>
//void test(T1& p1, T2& p2)
//{
//	cout << "test<T1&, T2&>" << endl;
//}
////template<class T1, class T2>
////void test(T1 t1, T2 t2)
////{
////	cout << "test<T1, T2>" << endl;
////}
////
////
////template<>
////void test(char c, int i)
////{
////	cout << "test<char, int>" << endl;
////}
////template<class T1>
////void test(double t, T1 d)
////{
////	cout << "test<double, T1>" << endl;
////}

void test_template()
{
	/*int a = 1;
	int b = 2;
	sx::swap(a, b);
	cout << a << b << endl;
	test(1.0, 1);
	test<char, int>('c', 10);*/
	//test<int&, int&>(a, b);
	//sx::S<double, double> s;
	//sx::S<char, int> s1;
	//sx::S<char, char> s2;
	//sx::S<char&, int&> s3;
	int a = 1;
	int* pa = &a;
	//test(1, 1.0);
	//test('a', 'b');
	//test('c', 1);
	//test(pa, pa);
	int& ra = a;
	ra = 2;
	test<int&, int&>(ra, ra);
}

//int main()
//{
//	test_template();
//	return 0;
//}


template<class T>
void print_list1(const list<T>& lt)
{
	typename list<T>::const_iterator it = lt.begin();
	//这里print_list实例化后不就已经确定了T的类型了吗？那么list<T>也应该是个确定的类型啊
	//，为什么还是要typename才能编译通过呢？

	cout << lt.size() << endl;
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
}


template<class Container>
void print_list2(const Container& lt)
{
	typename Container::const_iterator it = lt.begin();
	//这里print_list实例化后不就已经确定了T的类型了吗？那么list<T>也应该是个确定的类型啊
	//，为什么还是要typename才能编译通过呢？

	cout << lt.size() << endl;
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
}
//int main()
//{
//	int arr[] = { 2,8,3,6,5 };
//	list<int> lt1(arr, arr + 5);
//	print_list2(lt1);
//	return 0;
//}

//class S
//{
//public:
//	S()
//	{
//		_a1 = 0;
//	}
//	S& operator++()
//	{
//		++_a1;
//		return *this;
//	}
//	S operator++(int)
//	{
//		S tmp(*this);
//		++_a1;
//		return tmp;
//	}
//	friend ostream& operator<<(ostream& out, const S& s);
//private:
//	int _a1;
//};
//
//ostream& operator<<(ostream& out, const S& s)
//{
//	out << s._a1;
//	return out;
//}
//
//class Solution
//{
//
//public:
//	bool pop_sequence(vector<int> push, vector <int> pop)
//	{
//		stack<int> tmp;
//		int i = 0;
//		int j = 0;
//		while (j < push.size() && i < pop.size())
//		{
//			while (j < push.size() && (tmp.empty() || tmp.top() != pop[i]))
//			{
//				tmp.push(push[j]);
//				++j;
//			}
//			while(!tmp.empty() && i < pop.size() && tmp.top() == pop[i])
//			{
//				tmp.pop();
//				++i;
//			}
//		}
//		return tmp.empty();
//	}
//};
//
//
//
//int main()
//{
//	int arr[] = { 5,2,45,235,325 };
//	sort(arr, arr + 5, greater<int>());
//	for (auto e : arr)
//	{
//		cout << e << " ";
//	}
//	vector<int>::iterator i;
//	std::vector<int>::const_iterator ci = i;
//	//Test<vector<int>> a1;
//	//S s1;
//	//cout << s1++ << endl;
//	return 0;
//}

