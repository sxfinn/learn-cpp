#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Solution 
{
public:
	void replaceSpace(char* str, int length)
	{
		int n = 0;
		for (int i = 0; i < length; i++)
		{
			if (str[i] == ' ')
				n++;
		}
		char* tmp = (char*)malloc(sizeof(char) * (length + 2 * n + 1));
		strcpy(tmp, str);
		int p = 0;
		for (int i = 0; i < length + 1; i++)
		{
			if (tmp[i] == ' ')
			{
				str[p++] = '%';
				str[p++] = '2';
				str[p++] = '0';
			}
			else
			{
				str[p++] = tmp[i];
			}
		}
	}
};
int main()
{
	int a = 5.1;

	cout << sizeof(long);
	/*char arr[20] = "we are";
	int len = strlen(arr);
	Solution s;
	s.replaceSpace(arr, len);
	printf("%s", arr);*/
	return 0;
}
//using namespace std;
//
//#define M 100
//int main()
//{
//	printf("%d", M);
////#if 100 < 1
////	if (100 < M)
////		printf("yes");
////	else
////		printf("no");
////#endif
//}

//#define M 101
////条件预编译，在预处理阶段如果该条件为真则保留，为假则删除,且条件表达式中只能用有整数
//int main()
//{
//#if M < 100
//	printf("<");
//#elif M == 100
//	printf("==");
//#else
//	printf(">");
//#endif
//	return 0;
//}


//int main()
//{
//	if (1)
//		;
//	else if (1)
//		;
//	else
//		;
//	return 0;
//}

//#define M 10
//int main()
//{
//#undef M//取消宏定义的有效性
//	int a = M;
//
//	return 0;
//}

//宏不能递归
//#define MAX(x) x< 10 ? 1 :MAX(x + 1)
//
//int main()
//{
//	printf("%d", MAX(1));
//	return 0;
//}
//#define M(x,y) x##y//这里相当于xy
//#define W(x) printf("value " #x " is %d", x)//这里相当于把x的标识符转化为字符串。
////#define i int
//int main()
//{
//	int ab = 1;
//	W(ab);
//	/*printf("value %s is %d\n", W(ab), ab);*/
//	printf("%d", M(a, b));
//	//int*** a, b;
//	return 0;
//}

//当类的成员含有指针类型时，或许是编译器为了防止初始化的时候有野指针，直接将所以成员变量预定义为0；
//class S
//{
//public:
//	S()
//		:
//		_b(_a),
//		_a(_b)
//	{}
//
//	int _a;
//	int _b;
//	int* _p;
//};
//int main()
//{
//	S s;
//	cout << s._a;
//	return 0;
//}

//strcpy被编译器视为不安全，在cpp中语法检查更严格，

//c通常不会检查权限的扩大，但cpp会。
//int main()
//{
//	char arr[10];
//	const char* p = "hello world";
//	strcpy(arr, p);
//	cout << arr;
//	return 0;
//}