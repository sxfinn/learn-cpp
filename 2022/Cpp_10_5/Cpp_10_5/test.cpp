#include<iostream>
#include<vector>
#include<string>
using namespace std;

//int count1[26];
//class Solution
//{
//public:
//	int firstUniqChar(string s) 
//	{
//		memset(count1, 0, sizeof(count1));
//		for (auto &e : s)
//		{
//			count1[e - 'a']++;
//		}
//		size_t cnt = 0;
//		for (auto& e : s)
//		{
//			if (count1[e - 'a'] == 1)
//				return cnt;
//			++cnt;
//		}
//		return -1;
//	}
//};

//class solution
//{
//public:
//    string multiply(string num1, string num2)
//    {
//        string ret;
//
//        int sz1 = num1.size();
//        int sz2 = num2.size();
//        int sz = (sz1 + sz2);
//        ret.resize(sz);
//        int* num = (int*)malloc(sizeof(int) * (sz));
//        memset(num, 0, sizeof(int) * sz);
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
//            ret[i] = num[i] % 10 + '0';
//        }
//        ret[sz - 1] = num[sz - 1] % 10 + '0';
//        while (sz > 1)
//        {
//            if (ret[sz - 1] == '0')
//                sz--;
//            else
//                break;
//        }
//        ret.resize(sz);
//        reverse(ret.begin(), ret.end());
//        return ret;
//    }
//};

class Solution 
{
public:
	string reverseWords(string s) 
	{
		int prev = 0;
		int cur = 0;
		while (cur < s.size())
		{
			while (cur < s.size() && s[cur] != ' ')
			{
				++cur;
			}
			reverse(s.begin() + prev, s.begin() + cur);
			++cur;
			prev = cur;
		}
	}
};
void test1()
{
	//string s1("0");
	//string s2("0");
	//string ret = Solution().multiply(s1, s2);
	//cout << ret << endl;
	//string s;
	//getline(cin, s);
	//size_t pos = s.rfind(' ');
	//cout << s.size() - pos << endl;
}
int main() 
{

	//test1();
	return 0;
}
//class Solution 
//{
//public:
//	void reverseString(vector<char>& s) 
//	{
//		vector<char>::iterator begin = s.begin();
//		vector<char>::iterator end = begin + s.size() - 1;
//		while (begin != end)
//		{
//			std::swap(*begin, *end);
//			++begin;
//			--end;
//		}
//	}
//};
//class Solution 
//{
//public:
//	string reverseStr(string s, int k)
//	{
//		string::iterator start = s.begin();
//		int begin = 0;
//		int end = k - 1;
//		while (end < s.size())
//		{
//			_reverse(start + begin, start + end);
//			begin += 2*k;
//			end += 2*k;
//		}
//		_reverse(start + begin, start + s.size());
//		return s;
//	}
//	void _reverse(string::iterator begin, string::iterator end)
//	{
//		
//		while (begin < end)
//		{
//			std::swap(*begin, *end);
//			++begin;
//			--end;
//		}
//	}
//};
//class Solution
//{
//public:
//	bool isPalindrome(string s)
//	{
//		string::iterator begin = s.begin();
//		string::iterator end = begin + s.size() - 1;
//		while (begin < end)
//		{
//			while (begin < end && !((*begin >= '0' && *begin <= '9') ||
//				(*begin >= 'a' && *begin <= 'z') || (*begin >= 'A' && *begin <= 'Z')))
//			{
//				++begin;
//			}
//			while (begin < end && !((*end >= '0' && *end <= '9') ||
//				(*end >= 'a' && *end <= 'z') || (*end >= 'A' && *end <= 'Z')))
//			{
//				--end;
//			}
//			if (*begin == *end || (*begin) + 32 == *end || (*begin) - 32 == *end)
//				;
//			else
//				return false;
//		}
//		return true;
//	}
//};
//
//class Solution 
//{
//public:
//	string addStrings(string num1, string num2)
//	{
//		string ret;
//		int end1 = num1.size() - 1;
//		int end2 = num2.size() - 1;
//		int carry = 0;
//		while (end1 >= 0 || end2 >= 0)
//		{
//			int n1 = end1 >= 0 ? num1[end1] - '0' : 0;
//			int n2 = end2 >= 0 ? num2[end2] - '0' : 0;
//			int sum = n1 + n2 + carry;
//			
//			carry = sum / 10;
//			ret.push_back(sum % 10 + '0');
//			end1--;
//			end2--;
//		}
//		ret.push_back(carry + '0');
//		reverse(ret.begin(), ret.end());
//		return ret;
//	}
//};


// 64 Î»Êä³öÇëÓÃ printf("%lld")
//int main()
//{
//
//	/*vector<char> v1;
//	v1.push_back('a');
//	v1.push_back('b');
//	v1.push_back('c');
//	v1.push_back('d');
//	Solution().reverseString(v1);
//	for (auto e : v1)
//	{
//		cout << e << " ";
//	}*/
//	/*vector<int> v1;
//	v1.push_back(1);
//	v1.rbegin();
//	string s;
//	int ret = Solution().StrToInt(s);
//	cout << ret;*/
//	return 0;
//}
//class Solution 
//{
//public:
//    int StrToInt(string str)
//	{
//		int ret = 0;
//		cin >> str;
//		int flag = 1;
//		string::iterator it = str.begin();
//		if (*it == '+' || *it == '-' || *it == '/')
//		{
//			if (*it == '-')
//				flag = -flag;
//			++it;
//		}
//		while (it != str.end())
//		{
//			if (*it < '0' || *it > '9')
//				return 0;
//			ret = ret * 10 + *it - '0';
//			++it;
//		}
//		return ret * flag;
//    }
//};
