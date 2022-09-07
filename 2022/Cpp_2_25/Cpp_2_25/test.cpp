#include<iostream>
#include<string>
using namespace std;

int main()
{
	int sz = s.size();
	cout << sz;
	return 0;
}

//class S
//{
//public:
//	void print();
//	S(int a = 0)
//		:
//		_a(a)
//	{}
//	int _a;
//};
//void S::print()
//{
//	cout << _a << endl;
//}
//int main()
//{
//	S s;
//	cout << s._a;
//	return 0;
//}
//class S
//{
//public:
//	S(int a = 3 , int b = 4)
//		:
//		_a(5),
//		_b(6)
//	{
//		/*_a = a;
//		_b = b;*/
//	}
//	int _a = 1;//缺省值，在编译器自动生成的环境下可起作用
//	int _b = 2;
//};
//int main()
//{
//	S s();
//	cout << s._a << s._b;
//	return 0;
//}
//int main()
//{
//    
//    string s;
//    while (cin >> s)
//    {
//        int hash[128] = { 0 };
//        int i = 0;
//        int n = s.size();
//        for (i = 0; i < n; i++)
//        {
//            hash[s[i]]++;
//        }
//        for (i = 0; i < n; i++)
//        {
//            if (hash[s[i]] == 1)
//            {
//                cout << s[i] << endl;
//                break;
//            }
//        }
//        if (i == n)
//            cout << -1;
//    }
//    return 0;
//}
//class Solution 
//{
//public:
//    string multiply(string num1, string num2) 
//    {
//        string ret;
//        
//        int sz1 = num1.size();
//        int sz2 = num2.size();
//        int sz = (int)(sz1 + sz2);
//        ret.resize(sz + 1);
//        int* num = (int*)malloc(sizeof(int) * (sz));
//        memset(num, 0, sizeof(int) * (sz));
//        int i = 0, j = 0;
//        for (i = sz1 - 1; i >= 0; --i)
//        {
//            for (j = sz2 - 1; j >= 0; --j)
//            {
//                num[sz1 + sz2 - i - j - 2] += (num1[i] - '0') * (num2[j] - '0');
//            }
//        }
//        for (i = 0; i < sz - 1; i++)
//        {
//            num[i + 1] = num[i] / 10 + num[i + 1];
//            num[i] = num[i] % 10;
//        }
//        while (sz > 1 && num[sz - 1] == 0)
//        {
//            sz--;
//        }
//        for (i = 0; i < sz; i++)
//        {
//            ret[i] = '0' + num[i];
//        }
//        ret.resize(sz);
//        reverse(ret.begin(), ret.end());
//        return ret;
//    }
//};
//int main()
//{
//    string ret = Solution().multiply("123", "456");
//    cout << ret;
//    return 0;
//}
//class Solution
//{
//public:
//    string multiply(string num1, string num2) 
//    {
//        string s;
//        
//        int sz1 = num1.size();
//        int sz2 = num2.size();
//        size_t sz = sz1 + sz2;
//        int* ret = (int*)malloc(sizeof(int) * sz);
//        s.resize(sz, 0);
//        int i = 0, j = 0;
//        size_t next = 0;
//        for (i = sz1 - 1; i >= 0; i--)
//        {
//            //size_t tmp = num1[i] - '0';
//            for (j = sz2 - 1; j >= 0; j--)
//            {
//                size_t val1 = num1[i] - '0';
//                size_t val2 = num2[j] - '0';
//                size_t cur = val1 * val2;
//                //cur %= 10;
//                ret[sz1 + sz2 - i - j - 2] += cur;
//            }
//        }
//        next = 0;
//        for (i = 0; i < sz; i++)
//        {
//            size_t tmp = ret[i];
//            if (tmp + next > 9)
//            {
//                s[i] = (tmp + next) % 10 + '0';
//                next = (tmp + next) / 10;
//            }
//            /*else if (tmp + next == 0)
//                break;*/
//            else
//            {
//                s[i] = tmp + next + '0';
//            }
//        }
//        reverse(ret.begin(), ret.end());
//        return ret;
//    }
//};
//
//int main()
//{
//    string a(Solution().multiply("99", "99"));
//    cout << a;
//    return 0;
//}
//class Solution 
//{
//public:
//    string reverseWords(string s)
//    {
//        size_t n = s.size();
//        size_t i = 0;
//        size_t j = (s.find(' '), n);
//        while (i < n && j <= n)
//        {
//            reverse(s.begin() + i, s.begin() + j);
//            i = min(j + 1, n);
//            
//            j = min(s.find(' ', i), n);
//        }
//        return s;
//    }
//};
//int main()
//{
//    string ret = Solution().reverseWords("Let's take LeetCode contest");
//    cout << ret;
//    return 0;
//}
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 5; i += 2)
//	{
//		cout << i << " ";
//	}
//	return 0;
//}

//反转2k个字符中的前k个

//class Solution
//{
//public:
//    string reverseStr(string s, int k) 
//    {
//        int n = s.size();
//        int i = 0;
//        for (i = 0; i < n; i += 2 * k)
//        {
//            reverse(s.begin() + i, s.begin() + min(i + k, n));
//        }
//        return s;
//    }
//};
//
//int main()
//{
//    string ret(Solution().reverseStr("abcdefghijk", 2));
//    cout << ret;
//	return 0;
//}