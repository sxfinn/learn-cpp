#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
//string的操作接口
int main()
{
	string s("hello");
	//s.insert(0, "x");
	cout << s << endl;
	s.insert(5, "world");
	cout << s << endl;
	//string s1("hello");
	//string s2("world");
	//s1.append("bit");
	//cout << s1 << endl;
	//s1.append(s2);
	//cout << s1 << endl;
	//s2.push_back('!');
	//cout << s2 << endl;
	//s2 += "hehe";
	//cout << s2 << endl;
	//s2 += s1;
	//cout << s2 << endl;
	return 0;
}

//int main()
//{
//	string s("test");
//	cout << s.at(1);//等同于取下标
//	cout << s.operator[](1);
//	s.at(1) = 'a';
//	cout << s;
//	s.operator[](1) = 'a';
//	//for (auto& e : s) //范围for， 底层还是迭代器
//	//{
//	//	e += 1;
//	//}
//	//cout << s << endl;
//	return 0;
//}

//int main()
//{
//	string s("hello");
//	string::reverse_iterator rit = s.rbegin(); //反向迭代器
//	while (rit != s.rend())
//	{
//		cout << *rit << endl;
//		rit++;
//	}
//	//string::iterator it = s.end();//迭代器
//	//while (it != s.begin())
//	//{
//	//	--it;
//	//	cout << *it << endl;
//	//	
//	//}
//
//	return 0;
//}

//int main()
//{
//	string s;
//	string s1("hello");
//	string s2(s1);
//	for (int i = 0; i < s1.length(); i++)
//	{
//		cout << s1[i];
//	}
//	s2.operator[](1) = 'h';
//	cout << s2 << endl;
//	//cout << s1 << s2 << endl;
//	//cout << "yes" << endl;
//	return 0;
//}

//int getday(int y, int m)
//{
//	int arr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	if (m == 2 && (y % 4 == 0 && y % 100 != 0 || y % 400 == 0))
//		arr[2] = 29;
//	return arr[m];
//}
//int main()
//{
//	int n = 0;
//	int year = 0;
//	int month = 0;
//	int day = 0;
//	int num = 0;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d %d %d %d", &year, &month, &day, &num);
//		day += num;
//		while (day > getday(year,month))
//		{
//			day -= getday(year, month);
//			month++;
//			if (month > 12)
//			{
//				month = 1;
//				year++;
//			}
//		}
//		printf("%d-%d-%d", year, month, day);
//	}
//	return 0;
//}

//int main()
//{
//	int m[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	int year = 0;
//	int n = 0;
//	int month = 0;
//	int day = 0;
//	while (~scanf("%d", &year) && ~scanf("%d", &n))
//	{
//		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//		{
//			m[2] = 29;
//		}
//		else
//		{
//			m[2] = 28;
//		}
//		int i = 0;
//		for (i = 1; n > m[i]; i++)
//		{
//			n -= m[i];
//		}
//		month = i;
//		day = n;
//		printf("%d-%02d-%02d\n", year, month, day);
//	}
//	return 0;
//}
//class Solution 
//{
//public:
//    Solution()
//    {
//        i++;
//        sum += i;
//    }
//    int Sum_Solution(int n) 
//    {
//        i = 0;
//        sum = 0;
//        Solution arr[n];
//        return sum;
//    }
//    static int i;
//    static int sum;
//};
//int Solution::i = 0;
//int Solution::sum = 0;
