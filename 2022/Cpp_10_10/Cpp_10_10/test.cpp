#include "vector.h";

int main()
{
	sx::string s2;
	s2.push_back('b');
	cout << s2;
	return 0;
}
//#include<iostream>
////#include<vector>
//#include<string>
//#include"vector.h"
//using namespace std;
//using namespace sx;
//const char* arr[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
//class Solution
//{
//public:
//    vector<string> letterCombinations(string digits)
//    {
//
//        vector<string> ret;
//        if (digits.size() == 0)
//            return ret;
//        string s;
//        _letterCombinations(digits, 0, ret, s);
//        return ret;
//    }
//    void _letterCombinations(string& digits, size_t pos, vector<string>& v, string str)
//    {
//        if (pos == digits.size())
//        {
//            v.push_back(str);
//            return;
//        }
//        int num = digits[pos] - '0';
//        const char* s = arr[num];
//        for (size_t i = 0; i < strlen(s); i++)
//        {
//            _letterCombinations(digits, pos + 1, v, str + s[i]);
//        }
//    }
//};
//int main()
//{
//    Solution().letterCombinations("23");
//	return 0;
//}

//class Solution 
//{
//public:
//    int FindGreatestSumOfSubArray(vector<int> array)
//    {
//        vector<int>::iterator it = array.begin();
//        int sum = 0;
//        int max = -100;
//        for (auto e : array)
//        {
//            sum += e;
//            if (sum > max)
//                max = sum;
//            if (sum < 0)
//                sum = 0;
//            
//        }
//        return max;
//    }
//};
//class Solution 
//{
//public:
//    vector<vector<int>> generate(int numRows) 
//    {
//        vector<vector<int>> vv;
//        vv.resize(numRows);
//        for (int i = 0; i < numRows; ++i)
//        {
//            vv[i].resize(i + 1);
//        }
//        for (int i = 0; i < numRows; i++)
//        {
//            for (int j = 0; j <= i; ++j)
//            {
//                if (j == 0 || i == j)
//                {
//                    vv[i][j] = 1;
//                }
//                else
//                {
//                    vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
//                }
//            }
//        }
//        return vv;
//    }
//};
//int main()
//{
//    vector<vector<int>> ret = Solution().generate(8);
//    for (int i = 0; i < ret.size(); i++)
//    {
//        for (int j = 0; j < ret[i].size(); j++)
//        {
//            cout << ret[i][j] << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}
//class Solution 
//{
//public:
//    int removeDuplicates(vector<int>& nums) 
//    {
//        int fast = 0, slow = 0;
//        while (fast < nums.size())
//        {
//            if (nums[fast] != nums[slow])
//            {
//                nums[++slow] = nums[fast];
//            }
//            ++fast;
//        }
//        return slow + 1;
//    }
//};
//int count1[32] = { 0 };
//class Solution1 
//{
//public:
//    int singleNumber(vector<int>& nums) 
//    {
//        int ret = 0;
//        for (auto e : nums)
//        {
//            for (int i = 0; i < 32; i++)
//            {
//                if (((e >> i) & 1) == 1)
//                {
//                    count1[i]++;
//                }
//            }
//        }
//        for (int i = 0; i < 32; i++)
//        {
//            count1[i] %= 3;
//            ret += count1[i] * (1 << i);
//        }
//        return ret;
//    }
//};
//int main()
//{
//    int arr[] = { 0,1,0,1,0,1,99 };
//    vector<int> v(arr, arr + 7);
//    
//    int ret = Solution1().singleNumber(v);
//    cout << ret;
//    //vector<vector<int>> ret = Solution().generate(3);
//    //for (auto e : ret)
//    //{
//    //    for (auto k : e)
//    //    {
//    //        cout << k << " ";
//    //    }
//    //    cout << endl;
//    //}
//    return 0;
//}


//class Solution 
//{
//public:
//    vector<int> singleNumber(vector<int>& nums) 
//    {
//        int dif = 0;
//        for (auto e : nums)
//        {
//            dif ^= e;
//        }
//        int flag_bit = dif - (dif & (dif - 1));
//        int ret1 = 0, ret2 = 0;
//        for (auto e : nums)
//        {
//            if (e & flag_bit)
//                ret1 ^= e;
//            else
//                ret2 ^= e;
//        }
//        vector<int> v;
//        v.push_back(ret1);
//        v.push_back(ret2);
//        return v;
//    }
//};

//class Solution 
//{
//public:
//    int MoreThanHalfNum_Solution(vector<int> numbers) 
//    {
//        int cnt = 0;
//        int num = 0;
//        for (auto e : numbers)
//        {
//            if (cnt == 0)
//            {
//                num = e;
//                cnt++;
//            }
//            else
//            {
//                if (num != e)
//                {
//                    cnt--;
//                }
//                else
//                {
//                    cnt++;
//                }
//            }
//        }
//        return num;
//    }
//};
