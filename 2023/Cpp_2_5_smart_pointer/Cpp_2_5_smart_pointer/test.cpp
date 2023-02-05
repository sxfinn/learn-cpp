#include"SmartPointer.h"
#include<iostream>

using namespace std;

void test_unique_ptr()
{
	sx::unique_ptr<int> up1(new int(1));
	sx::unique_ptr<int> up2(new int(2));

	cout << *up1 << endl;
	cout << *up2 << endl;
}


void test_auto_ptr()
{
	sx::auto_ptr<int> ap1(new int(1));
	sx::auto_ptr<int> ap2(new int(2));
	sx::auto_ptr<int> ap3 = ap2;
	ap2 = ap1;

}

void test_shared_ptr()
{
	sx::shared_ptr<int> sp1(new int);
	sx::shared_ptr<int> sp2 = sp1;

	sx::shared_ptr<int> sp3(new int);
	sp3 = sp1;


}

template<class T>
struct Free
{
	void operator()(T* ptr)
	{
		free(ptr);
	}
};

void test_weak_ptr()
{
	sx::shared_ptr<int> sp1(new int);
	sx::weak_ptr<int> wp = sp1;
	
}
int main()
{
	test_unique_ptr();
	test_auto_ptr();
	test_shared_ptr();
	test_weak_ptr();

	std::auto_ptr<int> ap1(new int(1));
	std::auto_ptr<int> ap2(new int(2));
	ap2 = ap1;
	return 0;
}