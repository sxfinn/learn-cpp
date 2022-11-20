#include<iostream>

using namespace std;

class A
{
public:
	A()
		:
		_a(1)
	{
		cout << "A()" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}
	int _a;
};

class B : virtual public A
{
public:
	B()
	{
		_b = 2;
		cout << "B()" << endl;
	}

	~B()
	{
		cout << "~B()" << endl;
	}
protected:
	int _b;
};

class C : virtual public A
{
public:
	C()
	{

		_c = 3;
		cout << "C()" << endl;
	}

	~C()
	{
		cout << "~C()" << endl;
	}
protected:
	int _c;
};

class D : public B, public C
{
public:
	D()
	{
		_d = 4;
		cout << "D()" << endl;
	}
	~D()
	{
		cout << "~D()" << endl;
	}
protected:
	int _d;
};

void test_inherit()
{
	D d;
	B* ptr1 = &d;
	C* ptr2 = &d;
	D* ptr3 = &d;

	B& r1 = d;
	C& r2 = d;
	D& r3 = d;
	//cout << sizeof(d) << endl;
}


class Person
{
public:
	Person(const char* name = "张三")
		:_name(name)
	{
		cout << "Person()" << endl;
	}

	virtual void buy_ticket(int val = 100)
	{
		cout << "普通人-票价：" << val << endl;
	}
	string _name;
};

class Student : public Person
{
public:
	Student(int id)
		:
		student_id(id)
	{
		cout << "Student()" << endl;
	}
	void buy_ticket(int val = 50)
	{
		cout << "学生-票价：" << val << "id:" << student_id << endl;
	}
	int student_id;
};

class soldier : public Person
{
public:
	soldier(int id)
		:soldier_id(id)
	{
		cout << "soldier()" << endl;
	}
	virtual void buy_ticket(int val = 80)
	{
		cout << "军人-票价：" << val << "id:" << soldier_id << endl;
	}
	int soldier_id;
};

class medical_students : public Student
{
public:
	medical_students(int id)
		:
		Student(id)
	{
		cout << "medical_students()" << endl;
	}
	void buy_ticket(int val = 30)
	{
		cout << "医学生-票价：" << val << "id:" << student_id << endl;
	}
};
void test_polymorphism()
{
	//Person p;
	Student st(1);
	//soldier sr(2);
	//Person* ptr1 = &p;
	//Person* ptr2 = &st;
	//Person* ptr3 = &sr;
	//ptr1->buy_ticket();
	//ptr2->buy_ticket();
	//ptr3->buy_ticket();
	st.Person::buy_ticket();
	st.buy_ticket();
	cout << "=========================" << endl;
	//Student* ptr4 = &st;
	//ptr4->buy_ticket();
	//ptr4->Person::buy_ticket();

	cout << "=========================" << endl;

	medical_students ms(10);
	Student* pr1 = &ms;
	Student* pr2 = &st;
	pr1->buy_ticket();
	pr2->buy_ticket();
}

class A1
{
public:
	virtual void test1()
	{
		cout << "A1::test1()" << endl;
	}
	virtual void test2()
	{
		cout << "A1::test2()" << endl;
	}
};

class B1
{
public:
	virtual void test1()
	{
		cout << "B1::test1()" << endl;
	}
	virtual void test2()
	{
		cout << "B1::test2()" << endl;
	}
};

class C1:public A1, public B1
{
public:
	virtual void test()
	{
		cout << "C1::test()" << endl;
	}
	virtual void test1()
	{
		cout << "C1::test1()" << endl;
	}
};

typedef void(*pfunc)();
void print_vfptr(pfunc* pf)
{
	for (int i = 0; pf[i] != nullptr; ++i)
	{
		printf("%p\n", pf[i]);
		pf[i]();
	}
}
void  test_for_multiple_inheritance()//测试多继承的虚表
{
	C1 c;
	/*print_vfptr((pfunc*)*(long long*)&c);
	cout << " ----------------------------------" << endl;
	print_vfptr((pfunc*)*(long long*)((char*)(&c) + sizeof(A1)));*/
	A1* ptr1 = &c;
	B1* ptr2 = &c;
	printf("%p\n", &(C1::test1));
	auto tmp = &(C1::test1);
	printf("%p", tmp);
	//tmp();
	ptr1->test1();
	ptr2->test1();
}
//如果Mid1和Mid2都对Base的func虚函数进行了重写，而菱形继承又是虚继承的话，这样由于Drive类
// 的Base虚表就只有一个了，就会产生冲突，不确定Base的虚表到底存哪一个重写的，而如果Drive类中
// 这时Drive能将func再重写，再重写的func就会覆盖掉Mid1、2的重写（相当于两者重写为一个），
//也就消除了歧义就不会出现冲突了
class Base
{
public:
	virtual void func()
	{
		cout << "Base::func" << endl;
	}
	int _a;
};

class MidBase1: virtual public Base
{
public:
	virtual void func()
	{
		cout << "1::func" << endl;
	}
	virtual void func1()
	{
		cout << "MidBase1::func1" << endl;
	}
	virtual void func2()
	{
		cout << "MidBase1::func2" << endl;
	}
	int _b;
};

class MidBase2: virtual public Base
{
public:
	virtual void func()
	{
		cout << "2::func" << endl;
	}
	virtual void func1()
	{
		cout << "MidBase2::func1" << endl;
	}
	virtual void func2()
	{
		cout << "MidBase2::func2" << endl;
	}
	int _c;
};

class Drive:public MidBase1, public MidBase2
{
public:
	virtual void func()
	{
		cout << "Drive::func" << endl;
	}
	int _d;
};
void testing_diamond_inheritance()
{
	Drive d1;
}



class Father
{
public:
	 virtual void test()
	{
		cout << "F" << endl;
	}
	 /*virtual void test1()
	{
		cout << "test1" << endl;
	}*/
	int _A;
};

class Son :public Father
{
public:
	virtual void test()
	{
		cout << "S" << endl;
	}
	
	int _B;
};


//int main()
//{
//	Son s;
//	Father f;
//	Father* pf = &s;
//	Son* ps = &s;
//	printf("%p\n", &Son::test);
//	s.test();
//-	printf("%p\n", &Father::test);
//	f.test();
//	print_vfptr((pfunc*)( * (long long*)((char*)(&s))));
//
//
//	//Father* ptr1 = &s;
//	//Father* ptr2 = &f;
//	//ptr1->test();
//	//ptr1->test1();
//
//	//ptr2->test();
//	//ptr2->test1();
//	//testing_diamond_inheritance();
//	//test_for_multiple_inheritance();
//	//test_polymorphism();
//	//test_inherit();
//	return 0;
//}

class A2

{

public:

	A2() :m_iVal(0) { test(); }

	virtual void func() { std::cout << m_iVal << ""; }

	void test()
	{ 
		func(); 
	}

public:

	int m_iVal;

};



class B2 : public A2

{

public:

	B2()
		:
		_b(10)
	{ test(); }

	virtual void func()

	{

		++m_iVal;

		std::cout << m_iVal << " ";

	}
	int _b;
};



int main(int argc, char* argv[])

{

	A2* p = new B2;

	p->test();

	return 0;

}