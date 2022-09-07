#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v1;
	for (int i = 0; i < 6; i++)
	{
		v1.push_back(i);
	}
	vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		if (*it % 2 == 0)
			it = v1.erase(it);
		else
			it++;
	}
	for (auto e : v1)
	{
		cout << e << ' ';
	}
	return 0;
}

//对vector类的遍历和函数调用，大多使用迭代器
//int main()
//{
//	vector<int> v1;
//	vector<int>v2(10, 50);
//	vector<int>v3(v2);
//	v3.insert(v3.begin(),2, 20);
//	
//	v3.erase(v3.begin(),v3.end() - 1);
//	vector<int>::iterator it = v3.begin();
//	while (it != v3.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	//int size1 = v1.size();
//	//int size2 = v2.size();
//	//cout << size1 << " " << size2;
//	
//	return 0;
//}
//int main()
//{
//	//不同编译器的实现方式不同，每次增容大小不一定
//	vector<int> v1;
//	v1.push_back(1);
//	cout << v1.capacity() << endl;
//	v1.push_back(2);
//	cout << v1.capacity() << endl;
//	v1.push_back(3);
//	cout << v1.capacity() << endl;
//	v1.push_back(4);
//	cout << v1.capacity() << endl;
//	v1.push_back(5);
//	cout << v1.capacity() << endl;
//	v1.push_back(6);
//	cout << v1.capacity() << endl;
//	v1.push_back(6);
//	cout << v1.capacity() << endl;
//	//cout << v1.capacity() << endl;
//	//for (int i = 0; i < 2; i++)
//	//{
//	//	cout << v1[i] << " ";
//	//}
//	return 0;
//}
//class B
//{
//public:
//	B(double d = 1.2)
//		:
//		_d(d)
//	{}
//	B(B& b)
//		:
//		_d(b._d)
//	{}
//private:
//	double _d;
//};
//class S
//{
//public:
//	S(B b)
//		:
//		_b(b)
//	{}
//	S(S& b)
//		:
//		_b(b._b)
//	{}
//private:
//	B _b;
//};
//int main()
//{
//	B b = 2.4;
//	S s(b);
//	return 0;
//}