#include<iostream>
using namespace std;

class S
{
public:
	S(int a = 1, int b = 2)
	{
		_a = a;
		_b = b;
	}
	int _a;
	int _b;
};

int main()
{
	S s1(3, 4);
	
	S& s3 = s1;
	S s2(s1);
	S s4;
	s4 = s1;
	cout << s2._a << s2._b << endl;
	cout << s4._a << s4._b << endl;
	return 0;
}

//struct S
//{
//	S(int a = 1, int b = 2)
//	{
//		_a = a;
//		_b = b;
//	}
//	int add(int a, int b)
//	{
//		return a + b;
//	}
//	int _a;
//	int _b;
//};
//int main()
//{
//	struct S s(3, 4);
//	S c;
//	cout << s._a << s._b << endl;
//	cout << c._a << c._b << endl;
//	int ret = s.add(s._a, s._b);
//	cout << ret << endl;
//	return 0;
//}

//class S
//{
//public:
//	S(int a = 0, const char* arr = "abcd", int b = 1, const char* arr2 = "cdef")
//	{
//		_a = a;
//		_arr1 = arr;
//		_b = b;
//		_arr2 = arr2;
//	}
//	int _a;
//	const char* _arr1;
//private:
//	int _b;
//	const char* _arr2;
//};
//
//int main()
//{
//	char arr[] = "abc";
//
//	printf("%d", sizeof(int));
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int b = 1;
//	cin >> a >> b;
//	cout << a << ' ' << b << endl;
//
//	return 0;
//}

//int main()
//{
//	/*int p = 0;
//	
//	cout << b << endl;
//	cout << q << endl;*/
//	S a;
//	cout << a._a << a._arr1 << endl;
//	return 0;
//}