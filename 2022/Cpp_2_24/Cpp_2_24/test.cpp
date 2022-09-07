#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool is_letterornum(char e)
{
	if ('A' <= e && e <= 'Z' || 'a' <= e && e <= 'z' || '0' <= e && e <= '9')
		return true;
	else
		return false;
}
class Solution 
{
public:
	bool isPalindrome(string s) 
	{
		for (auto& e : s)
		{
			if ('A' <= e && e <= 'Z')
				e += 32;
		}
		size_t start = 0;
		size_t end = s.size();
		while (start < end)
		{
			while (start < end && !is_letterornum(s[start]))
				start++;
			while (start < end && !is_letterornum(s[end]))
				--end;
			if (s[start] != s[end])
				return false;
		}
		return true;
	}
};
//int main()
//{
//	string name;
//	getline(cin, name);
//	size_t pos = name.rfind(' ');
//	size_t end = name.size();
//	cout << end - pos - 1;
//	return 0;
//}
//class Solution
//{
//public:
//	int firstUniqChar(string s)
//	{
//		bool hash[128] = { 0 };
//		int i = 0;
//		int end = s.size();
//		for (i = 0; i < end; i++)
//		{
//			++hash[s[i]];
//		}
//		for (i = 0; i < end; i++)
//		{
//			if (hash[s[i]] == 1)
//				return i;
//		}
//		return -1;
//	}
//};

//bool is_letter(char c)
//{
//	if ('a' <= c && c <= 'z' || 'A' <= c && c <= 'Z')
//		return true;
//	else
//		return false;
//}
//class Solution 
//{
//public:
//	string reverseOnlyLetters(string s) 
//	{
//		int start = 0;
//		int end = s.size() - 1;
//		while (start < end)
//		{
//			while (start < end && !is_letter(s[start]))
//				++start;
//			while (start < end && !is_letter(s[end]))
//				--end;
//			swap(s[start], s[end]);
//			++start;
//			--end;
//		}
//		cout << s << endl;
//		return s;
//	}
//};
//bool is_letter(char c)
//{
//	if ('a' <= c && c <= 'z' || 'A' <= c && c <= 'Z')
//		return true;
//	else
//		return false;
//}
//class Solution
//{
//public:
//	string reverseOnlyLetters(string s)
//	{
//		int start = 0;
//		int end = s.size() - 1;
//		while (start < end)
//		{
//			while ( !is_letter(s[start]))
//				++start;
//			while ( !is_letter(s[end]))
//				--end;
//			if (start < end)
//			{
//				swap(s[start], s[end]);
//				++start;
//				--end;
//			}
//		}
//		cout << s << endl;
//		return s;
//	}
//};
//int main()
//{
//	Solution().reverseOnlyLetters("7_28]");
//	return 0;
//}
//int main()
//{
//	string a("hello");
//	cout << a.operator[]
//	//cout << a << a.capacity() << endl;
//	//a.reserve(10);
//	//cout << a << a.capacity()<<endl;
//	return 0;
//}

//class Solution
//{
//public:
//	string addStrings(string num1, string num2)
//	{
//		string ret;
//		int end1 = num1.size() - 1;
//		int end2 = num2.size() - 1;
//		int next = 0;
//		while (end1 >= 0 || end2 >= 0)
//		{
//			
//			int val1 = end1 < 0 ? 0 : num1[end1] - '0';
//			int val2 = end2 < 0 ? 0 : num2[end2] - '0';
//			int cur = val1 + val2 + next;
//			next = cur / 10;
//			cur %= 10;
//			ret += '0' + cur;
//			--end1, --end2;
//		}
//		if (next)
//		{
//			ret += '1';
//		}
//		string::iterator start = ret.begin();
//		string::iterator end = ret.end();
//		//reverse(ret.begin(), ret.end());
//		reverse(start, end);
//		return ret;
//	}
//};

//int main()
//{
//	string ret = Solution().addStrings("1123", "123");
//	cout << ret << endl;
//	return 0;
//}
//bool isdigit(char c)
//{
//	return (c <= '9' && c >= '0');
//}

//class Solution 
//{
//public:
//	int StrToInt(string str) 
//	{
//		int ret = 0;
//		int flag = 1;
//		int start = 0;
//		size_t end = str.size();
//		if (str[0] == '+' || str[0] == '-')
//		{
//			if (str[0] == '-')
//				flag = -1;
//			++start;
//		}
//		for (int i = start; i < end; i++)
//		{
//			if (!isdigit(str[i]))
//			{
//				return 0;
//			}
//			ret = ret * 10 + str[i] - '0';
//		}
//		return ret * flag;
//	}
//};
//int main()
//{
//	int ret = Solution().StrToInt("+123");
//	Solution b;
//	cout << ret << endl;
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	while ((cin >> a))// cin\getline 都会在标准输入流中读取不到东西时返回一个false
//	{
//		cout << a << " ";
//	}
//	return 0;
//}
//最后一个单词的长度
//int main()
//{
//	string s("we are the best");
//	size_t pos = s.rfind(' ');
//	size_t end = s.size();
//	if (pos != string::npos)
//	{
//		cout << end - pos - 1 << endl;
//	}
//	return 0;
//}

//int main()
//{
//	string s("");
//	//s.resize(20);
//	cout << s.empty() << endl;
//	return 0;
//}

//struct  S
//{
//	int a;
//	int b;
//};
//找到域名和协议
void fd(string& s1)
{
	size_t pos = s1.find(':');
	if (pos != string::npos)
	{
		cout << "protocal: " << s1.substr(0, pos) << endl;
	}
	else
	{
		cout << "protocal: " << "not found" << endl;
	}
	size_t start = pos + 3;
	size_t end = s1.find('/', start);
	if (end != string::npos)
	{
		cout << "domain name: " << s1.substr(start, end - start) << endl;
	}
	else
	{
		cout << "domain name: " << "not found" << endl;
	}
}
//int main()
//{
//	string s1("https://www.cplusplus.com/reference/string/string/find/");
//	string s2("http://web.shanbay.com/wordsweb/#/study/entry");
//	fd(s1);
//	fd(s2);
//	return 0;
//}

//int main()
//{
//	string s("hello");
//	
//	s. resize(30);
//	s += "!!!";
//	cout << s << endl;
//	cout << s.c_str() << endl;
//	return 0;
//}
//int main()
//{
//	string s("hello");
//	s += 'a';
//	string s1 = s + 'h';
//	string s3 = "hehe";
//	cout << s + 'a' << endl;
//	cout << s1 << endl;
//	cout << s3;
//	return 0;
//}