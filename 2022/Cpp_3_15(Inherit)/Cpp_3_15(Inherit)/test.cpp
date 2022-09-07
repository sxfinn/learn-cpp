#include<iostream>
#include<utility>
#include<vector>
#include<list>
using namespace std;
//简单继承
class person
{
public:
	person(const string name = "songxin", int age = 19)
		:
		_name(name),
		_age(age)
	{}
	void print()
	{
		cout << _name << endl;
		cout << _age << endl;
	}
protected:
	string _name;
	int _age;
};

class student:public person
{
public:
	student()
		:
		person(),
		_stuid(10010)
	{

	}
	void print()
	{
		cout << _age << " " << _name << endl;
		cout << " stuid :" << _stuid << endl;
	}
private:
	int _stuid;
};

class teacher:public person
{
public:

private:
	int _jobid;
};
void test1()
{
	student s1;
	teacher t1;
	s1.print();
	t1.print();
}

int main()
{
	test1();
	return 0;
}
//为什么自定义的对象只要是自己写的拷贝构造就无法使用std中的swap函数呢？
//class S
//{
//public:
//	S()
//	{
//		a = 1;
//		b = 10;
//	}
//	/*S(S& s)
//	{
//		a = s.a;
//		b = s.b;
//	}*/
//	void operator=(S s)
//	{
//		a = s.a;
//		b = s.b;
//	}
//	int a;
//	int b;
//};
//int main()
//{
//	S s1;
//	S s2;
//	::swap(s1, s2);
//	return 0;
//}
//class B
//{
//public:
//	B(int x = 0, int y = 1)
//		:
//		_x(x),
//		_y(y)
//	{}
//	B(B& data)
//		:
//		_x(data._x),
//		_y(data._y)
//	{
//
//	}
//	B operator=(B b)
//	{
//		swap(b);
//		return *this;
//	}
//	void print()
//	{
//		cout << _x << _y << endl;
//	}
//	void swap(B& b)
//	{
//		::swap(_x, b._x);
//		::swap(_y, b._y);
//	}
//	int _x;
//	int _y;
//};
//void test3()
//{
//
//}
//void test2()
//{
//	B b1(1, 9);
//	B b2(2, 8);
//	B b4;
//	b4 = b1;
//	b1.swap(b2);
//	//B b3(b2);
//	b1.print();
//	b2.print();
//	//b4.print();
//	//b3.print();
//	//list<int> l1;
//	//list<int> l2;
//	//std::swap(l1, l2);
//	std::swap(b1, b2);
//}
//void test1()
//{
//	S s1(10, 10);
//	S s2(20,20);
//	S s3(s1);
//	//std::swap(s1, s2);
//	s1.print();
//	s2.print();
//	s3.print();
//	//vector<int> v1;
//	//vector<int> v2;
//	//::swap(v1, v2);
//	//string s1("hello");
//	//string s2("hehe");
//	//std::swap(s1, s2);
//	//cout << s1 << s2;
//}

//int main()
//{
//	test3();
//	test2();
//	//test1();
//	return 0;
//}
//class S
//{
//public:
//	S(int a = 9, int b = 9)
//		:
//		_a(a),
//		_b(b)
//	{}
//	S(S& s)
//		:
//		_a(s._a),
//		_b(s._b)
//	{
//		
//	}
//
//
//	void swap(S& s)
//	{
//		::swap(_a, s._a);
//		::swap(_b, s._b);
//	}
//	
//	void print()
//	{
//		cout << _a << _b << endl;
//	}
//	int _a;
//	int _b;
//};
//class person
//{
//public:
//	person()
//		:
//		age(10),
//		sex(1)
//		//teachage(99)
//	{}
//	void print()
//	{
//		cout << age;
//	}
////private:
////protected:
//	int age;
//	int sex;
//	//int teachage;
//};
//
//class stu:public person
//{
//public:
//	stu()
//		:
//		id(0)
//	{
//
//	}
//	void print()
//	{
//		printf("%d", id);
//	}
//	int id;
//};
//class teacher
//{
//public:
//	teacher()
//		:
//		teachage(50)
//	{}
//	class person;
//	int teachage;
//
//};
//class S
//{
//public:
//	S()
//		:
//		a(101)
//	{}
//	int a;
//};
//
//void test2()
//{
//
//}
//int main()
//{
//	//test1();
//	return 0;
//}
//void test1()
//{
//	stu s1;
//	//cout << s1.teachage;
//	cout << s1.age;
//	teacher t1;	
//	cout << sizeof(t1);
//}
//int main()
//{
//	
//	//test1();
//	double d = 901.9;
//	int* t1 = (int*)& d;
//	int& t2 = (int&)d;
//	cout << *t1 << " " << t2;
//	return 0;
//}

//int main()
//{
//	cout << S().a;
//	S s;
//	cout << s.a;
//	//cout << s.a;
//	//int cur(99);
//	//cout << cur;
//	//stu s1;
//	//cout << s1.age;
//	//s1.print();
//	return 0;
//}