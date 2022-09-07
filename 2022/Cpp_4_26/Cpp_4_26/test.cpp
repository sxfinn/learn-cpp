#include<iostream>
//using namespace std;
using std::cout;
using std::endl;
using std::cin;


int main()
{

	return 0;
}

//int Add(int a, int b)
//{
//	cout << "int Add(int a, int b)" << endl;
//	return a + b;
//}
//double Add(double a, double b)
//{
//	cout << "double Add(double a, double b)" << endl;
//	return a + b;
//}
//float Add(float a, float b)
//{
//	cout << "float Add(float a, float b)" << endl;
//	return a + b;
//}
//
//int main()
//{
//	int ret1 = Add(1, 2);
//	int ret2 = Add(1.1, 2.2);
//	int ret3 = Add((float)1.1, (float)2.2);
//	return 0;
//}

//int a = 1;
//int a = 1;
//
//namespace sx
//{
//	int a;
//	void swap(int& a, int& b)
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	}
//}
//
////using namespace sx;
//int main()
//{
//	cout << ::a << endl;
//	return 0;
//}

//void testfunc(int t = 10)
//{
//	cout << t << endl;
//}
//
//void FAll(int x = 1, int y = 2, int z = 3)
//{
//	cout << x << y << z << endl;
//}
//void FHalf(int x, int y = 10, int z = 30)
//{
//	cout << x << y << z << endl;
//}
//
////void Test(int a = 10);
//void Test(int a = 20)
//{
//	cout << a << endl;
//}
//int main()
//{
//	FAll();
//	FHalf(5);
//	return 0;
//}
//int main()
//{
//	int i = 1;
//	double d = 1.1;
//	cout << "i =" << i << ",d =" << d << endl;
//	return 0;
//}
//namespace sx
//{
//	int a;
//	void swap(int& a, int& b)
//	{
//		cout << " namespace:sx " << endl;
//		int tmp = a;
//		a = b;
//		b = tmp;
//	}
//	struct Stu
//	{
//		char name[10];
//		int age;
//	};
//}
//using sx::Stu;
//void test1()
//{
//	sx::Stu s = { "songxin", 20 };
//}
//int main()
//{
//	test1();
//	return 0;
//}

//using std::swap;
//namespace sx
//{
//	int a;
//	void swap(int& a, int& b)
//	{
//		cout << " namespace:sx " << endl;
//		int tmp = a;
//		a = b;
//		b = tmp;
//	}
//	struct Stu
//	{
//		char name[10];
//		int age;
//	};
//	namespace psm
//	{
//		int b;
//		void print()
//		{
//			cout << "hello psm!" << endl;
//		}
//	}
//}
//int a = 1;

//using namespace sx;
//namespace n1
//{
//	int a;
//	void swap(int& a, int& b)
//	{
//		cout << "n1:swap" << endl;
//	}
//}
//namespace n2
//{
//	int b;
//}
//namespace n1
//{
//	int c;
//	void swap(int& a, int& b)
//	{
//		cout << "n1:swap" << endl;
//	}
//}
// 
//int a;
//using sx::a;

//using namespace sx; 
//int a = 1;
//int main()
//{
//	//int a = 1;
//	cout << a << endl;
//	return 0;
//}

//int main()
//{
//	//cout << "hello world again!" << endl;
//	int x = 1;
//	int y = 2;
//	sx::swap(x, y);
//	//cout << x << y << endl;
//	return 0;
//}