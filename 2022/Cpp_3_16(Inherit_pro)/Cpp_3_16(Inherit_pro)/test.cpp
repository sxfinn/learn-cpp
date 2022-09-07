//感觉继承下来的基类出了初始化构造外，
//其他的例如拷贝构造并不需要 <一定> 去调用基类的拷贝构造，而是可以直接写

#include<iostream>
using namespace std;

//int main()
//{
//	int n = 10;
//	int* ret = &n;
//	printf("%lld ", ret);
//	printf("%lld", ret + 1);
//	return 0;
//}
//虚拟继承
//class A
//{
//public:
//	int _a;
//};
//class B:virtual public A
//{
//public:
//	int _b;
//};
//
//class C:virtual public A
//{
//public:
//	int _c;
//};
//
//class D:public B,public C
//{
//public:
//	int _d;
//};
//
//int main()
//{
//	D t;
//	t.C::_a = 1;
//	t.B::_a = 2;
//	t._b = 3;
//	t._c =4;
//	t._d = 5;
//	int* r1 = (int*) & t._b - 1;
//	int* r2 =(int*) & t._c - 1;
//	//cout << *r1 << endl;
//	//cout << *r2 << endl;
//	 
//	int arr[6] = { 0 };
//	cout << arr + 1 << " " << arr + 1 << " " << arr + 2 << endl;
//	int n = 0;
//	int* p = &n;
//	cout << sizeof(int*) << endl;
//	//cout << p << " " << p + 1;
//	return 0;
//}
//class student;
//class person
//{
//public:
//	person(const string name = "songxin", int age = 19)
//		:
//		_name(name),
//		_age(age)
//	{}
//	person(const person& p)
//		:
//		_name(p._name),
//		_age(p._age)
//	{
//
//	}
//	person& operator=(const person p)
//	{
//		_name = p._name;
//		_age = p._age;
//		return *this;
//	}
//	friend void print(person& p, student& s);
//
//	
////private:
//protected:
//	string _name;
//	int _age;
//};
//
//class student:public person
//{
//public:
//	student(const string name = "宋鑫", int age = 20,const string stuid = "202008642")
//		:
//		person(name, age),
//		_stuid(stuid)
//	{
//
//	}
//	student(const student& s)
//		:
//		person((student&)s),//const 修饰要注意
//		_stuid(s._stuid)
//	{
//
//	}
//	student& operator=(const student& s)
//	{
//		person::operator=(s);
//		//_age = s._age;
//		//_name = s._name;
//		_stuid = s._stuid;
//		return *this;
//	}
//	void print()
//	{
//		cout << "student " << _name << _age << _stuid << endl;
//	}
//	
//private:
//	string _stuid;
//};
////友元关系无法继承
//void print(person& p, student& s)
//{
//	cout << "person " << p._age << p._name << s._age << endl;
//}
//void test2()
//{
//	student s1;
//	person p1;
//	print(p1,s1);
//}
//int main()
//{
//	test2();
//	//test1();
//	return 0;
//}
//void test1()
//{
//	student s1("tanmei", 50, "00010");
//	s1.print();
//	student s2;
//	s2.print();
//	s2 = s1;
//	s2.print();
//
//
//	person p1("tanmei", 50);
//	//person p2;
//	//p2 = p1;
//	//p2.print();
//	//p2.print();
//
//
//
//	//s1.print();
//	//person* pp = &s1;
//	//person& vp = s1;
//	
//	//S s1(4);
//	//S s2(5);
//	//::swap(s1, s2);
//}


//class S
//{
//public:
//	S(int a = 0)
//		:
//		_a(10)
//	{}
//	S(S& s)
//	{
//		_a = s._a;
//	}
//	int _a;
//};
