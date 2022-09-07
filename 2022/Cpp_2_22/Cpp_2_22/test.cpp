#include<iostream>

using namespace std;

class S
{
public:
	S(int a = 0, int b = 3)
	{
		_a = a;
		_b = b;
	}
private:
	int _a;
	int static _b;
};
int S::_b = 1;


int main()
{
	
	return 0;
}
//int main()
//{
//	//int S::_b = 1;
//	S s(1);
//	cout << s._b << " " << S::_b;
//	//S::_b = 0;
//	//cout << s._a << s._b;
//	return 0;
//}
//class S
//{
//public:
//	S(int x = 0, int y = 0, int c = 0)
//		:_c(c)
//	{
//		_x = x;
//		_y = y;
//	}
//	
//	int _x;
//	int _y;
//	const int _c;
//};
//int main()
//{
//	S s1(1, 1, 1);
//	S s2 = s1;
//	S s3(s2);
//	cout << s3._c << endl;
//	cout << s2._c;
//	return 0;
//}