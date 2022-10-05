#include"vector.h"
#include<string>
#include<vector>
#include<list>
void test3()
{
	std::list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	int arr[] = { 1,23,43,5,345 };
	sx::vector<int> v1(l1.begin(), l1.end());
	sx::vector<int> v2;
	v2.push_back(10);
	v2.push_back(10);
	v2.push_back(10);
	v2.insert(v2.begin(), 2, 9);
	cout << endl;
	for (auto e : v2)
	{
		cout << e << " ";
	}
}
void test2()
{

	std::vector<int> v1;
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(1);
	v1.reserve(3);
	v1.reserve(4);
}
void test1()
{
	sx::vector<string> v1;
	v1.push_back("func");
	v1.push_back("hello");
	v1.push_back("hello");
	v1.push_back("hello");
	v1.push_back("hello");
	v1.push_back("hello");
	v1.push_back("hello");
	v1.push_back("hello");
	v1.push_back("hello");
	v1.push_back("hello");
	sx::vector<string> v2 = v1;
	for (auto e : v1)
	{
		cout << e << " ";
	}
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	test3();
	//test2();
	//test1();
	//int arr[] = { 1,2,3,4,5,5,6 };
	//sx::vector<int> v1(arr, arr + 1);
	//sx::vector<int> v2 = v1;
	////v2.reserve(10);
	//v2.push_back(9);
	//v2.push_back(10);
	//v2.insert(v2.end() - 1, 3, 8);
	//for (auto e : v2)
	//{
	//	cout << e << " ";
	//}
	//cout << endl << v2.capacity() << v2.size();
	//cout << endl;
	//
	//v2.resize(10);
	//for (auto e : v2)
	//{
	//	cout << e << " ";
	//}
	//cout << endl << v2.capacity() << v2.size();
	//return 0;
}




//template<class T>//just a test
//class S
//{
//public:
//	S()
//	{
//		_a = 1;
//	}
//	void test1();
//	friend void test(S s);
//private:
//	T _a;
//};
//template<class T>
//void S<T>::test1()
//{
//	cout << "test1" << endl;
//}
//template<class T>
//void test(S s)
//{
//	cout << "test" << endl;
//	cout << s._a << endl;
//}
