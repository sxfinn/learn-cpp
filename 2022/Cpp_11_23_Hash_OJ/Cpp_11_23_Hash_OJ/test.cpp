#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<sstream>
using namespace std;


//在长度 2N 的数组中找出重复 N 次的元素
class Solution1
{
    unordered_map<int, int> hash;
public:
    int repeatedNTimes(vector<int>& nums) 
    {
        for (auto& e : nums)
        {
            if (hash[e] >= 1)
                return hash[e];
            hash[e]++;
        }
        return 0;
    }
};

class Solution2 
{
    unordered_map<int, pair<int, int>> hash;
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        for (auto& e : nums1)
        {
            hash[e].first++;
        }
        for (auto& e : nums2)
        {
            hash[e].second++;
        }
        vector<int> ans;
        for (auto& e : hash)
        {
            int cnt = min(e.second.first, e.second.second);
            for(int i = 0; i < cnt; ++i)
                ans.push_back(e.first);
        }
        return ans;
    }
};

class Solution 
{
    unordered_map<string, int> hash;
public:
    vector<string> uncommonFromSentences(string s1, string s2) 
    {
        stringstream ss1(s1);
        stringstream ss2(s2);
        string substr;
        while (ss1 >> substr)
        {
            hash[substr]++;
        }
        while (ss2 >> substr)
        {
            hash[substr]++;
        }
        vector<string> ans;
        for (auto& e : hash)
        {
            if (e.second == 1)
            {
                ans.push_back(e.first);
            }
        }
        return ans;
    }
};

int main()
{
    //vector<string> ret = Solution().uncommonFromSentences("this apple is sweet", "this apple is sour");
    //for (auto& e : ret)
    //{
    //    cout << e << endl;
    //}

    stringstream ss1;
    ss1 << "12 23you are so pretty!";
    int n = 0;
    int m = 0;
    string str;
    ss1 >> n;
    ss1 >> m;
    cout << n << " " << m;
	return 0;
}