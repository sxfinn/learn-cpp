#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;



//int Add(int a, int b)
//{
//	cout << "Add" << endl;
//	return a + b;
//}
//typedef void (*pf)();
//int main()
//{
//	pf p = (pf) & Add;
//	p();//打印出了Add，执行了Add函数
//	return 0;
//}
//class Base1
//{
//public:
//	virtual void func1(int a)
//	{
//		cout << "Base1::func1" << endl;
//		cout << a << endl;
//	}
//};
//
//class Base2
//{
//public:
//	virtual void func1(int a)
//	{
//		cout << "Base2::func1" << endl;
//	}
//};
//
//class Derive : public Base1, public Base2
//{
//public:
//	virtual void func1(int a)
//	{
//		cout << "Derive::func1" << endl;
//		cout << a << endl;
//	}
//	virtual void func2(int a)
//	{
//		cout << "Derive::func2" << endl;
//		cout << a << endl;
//	}
//	
//};
//
//typedef void (*VFT)(Derive* ,int);
//void print(VFT* p)
//{
//	for (int i = 0; p[i] != nullptr; i++)
//	{
//		cout << p[i] << endl;
//		p[i](nullptr,1);
//	}
//}
//
//int main()
//{
//	Base1 b1;
//	print((VFT*)(*(long long*)&b1));
//	Base2 b2;
//	cout << endl;
//	print((VFT*)(*(long long*)&b2));
//	cout << endl;
//	Derive d1;
//	print((VFT*)(*(long long*)&d1));
//	cout << endl;
//	print((VFT*)( * (long long*)((char*)&d1 + sizeof(Base1))));
//	return 0;
//}
//class Person
//{
//public:
//	Person()
//	{
//		a = 10;
//	}
//	virtual void BuyTiket()
//	{
//		cout << "全价" << endl;
//	}
//	virtual ~Person()
//	{
//		cout << "Person" << endl;
//	}
//	int a;
//};
//
//class Student :public Person
//{
//public:
//	virtual void BuyTiket()
//	{
//		cout << "半价" << endl;
//	}
//	virtual ~Student()
//	{
//		cout << "Student" << endl;
//	}
//};
//
//int main()
//{
//	Person p;
//	Student s;
//	s.BuyTiket();
//	return 0;
//}
//class Person
//{
//public:
//	virtual ~Person()
//	{
//
//	}
//	virtual void BuyTiket()
//	{
//		cout << "全价" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	~Student()
//	{
//
//	}
//	virtual void BuyTiket()
//	{
//		cout << "半价" << endl;
//	}
//};
//void Buy(Person& p)
//{
//	p.BuyTiket();
//}
//int main()
//{
//	Person p;
//	Student s;
//	
//	Buy(p);
//	Buy(s);
//	return 0;
//}
//class Person {
//public:
//	
//	 virtual ~Person() { cout << "~Person()" << endl; }
//	 void print()
//	 {
//		 cout << "Person" << endl;
//	 }
//};
//class Student : public Person {
//public:
//	virtual ~Student() { cout << "~Student()" << endl; }
//};
//int main()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	p1->~Person();
//	p2->~Person();
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	char ch = 0;
//	//scanf("%d", &i);
//	scanf("%c", &ch);
//	printf("%d %c", i, ch);
//	return 0;
//}

//int main()
//{
//	int i;
//	char ch;
//	cin >> i;
//	cin >> ch;
//	cout << i << endl;
//	cout << ch << endl;
//	return 0;
//}
//class T
//{
//public:
//	T()
//	{
//		cout << "T()" << endl;
//	}
//	
//	~T()
//	{
//		cout << "~T()" << endl;
//	}
//	int x;
//};
//class T1
//{
//public:
//	T1()
//	{
//		cout << "T1()" << endl;
//	}
//
//	~T1()
//	{
//		cout << "~T1()" << endl;
//	}
//	int x;
//};
//class S
//{
//public:
//	S()
//		:a(1),
//		b(2)
//	{
//		cout << "S()" << endl;
//	}
//	~S()
//	{
//		a = 0;
//		b = 0;
//		cout << "~S()" << endl;
//	}
//	
//	int a;
//	int b;
//	
//	T1 t1;
//	T t;
//};
//int main()
//{
//	S s;
//	return 0;
//}
//int test(int a, int b)
//{
//	return a > b ? a : b;
//}
//int main()
//{
//	const int a = 1;
//	int b = a;
//	test(a, b);
//	return 0;
//}