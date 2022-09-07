#include<iostream>
#include<list>
#include<algorithm>
#include<vector>
using namespace std;
template<class T>
void print(list<T>& data)
{
	for (auto e : data)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test1()
{
	int arr[] = { 2,4,1,0,9 };
	sort(arr, arr + 5);
	for (auto e : arr)
	{
		cout << e << " ";
	}
}
void test2()
{
	string tmp("hello");
	string* a = (string*)malloc(sizeof(string)*2);
	new(a)string;
	//new(a)string[2]{"hehe", "haha"};
	cout << *a;
}
void test3()
{
	int* a = new int(1);
	cout << *a << endl;
	int* b = new int[5]{ 1,2,3,4,5 };
	for (int i = 0; i < 5; i++)
	{
		cout << b[i] << " ";
	}
}
void test4()
{
	list<int> l1(1);
	list<int>l2(l1);
}
int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}
//int main()
//{
//	int arr[10] = { 1,2,8,9,10,13,14,15,16 ,18 };
//	int num = 13;
//	/*for (int i = 0; i < 10; i++)
//	{
//		cin >> arr[i];
//	}*/
//	int left = 0;
//	int right = 9;
//	int sum = 0;	
//	size_t min = 100;
//	while (left < right)
//	{
//		sum = arr[left] + arr[right];
//		if (sum > num)
//			right--;
//		else if (sum < num)
//			left++;
//		else
//		{
//			min = 0;
//			break;
//		}
//		if (min > abs(sum - num))
//			min = abs(sum - num);
//	}
//	cout << min;
//	return 0;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	//list<int> l();
//	list<int> l1;
//	l1.push_back(1);
//	l1.push_back(2);
//	l1.push_back(1);
//	l1.push_back(2);
//	list<int> l2(l1);//拷贝构造
//	list<int> l3(l1.begin(), l1.end());//迭代器区间构造
//	list<int> l(arr, arr + 5);
//	print(l);
//	print(l1);
//	print(l2);
//	print(l3);
//	//l1.reverse();
//	//使用迭代器遍历链表
//	//for (auto& e : l1)
//	//{
//	//	cout << e << " ";
//	//	e += 1;
//	//}
//	//cout << endl;
//	//list<int>::iterator it = l1.begin();
//	//while (it != l1.end())
//	//{
//	//	cout << *it << " ";
//	//	++it;
//	//}
//	return 0;
//}