#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<set>
#include<unordered_set>
#include<unordered_map>
using namespace std;

//class Solution1
//{
//	map<string, int> index;
//public:
//	struct my_less
//	{
//		bool operator()(map<string, int>::iterator left, map<string, int>::iterator right)
//		{
//			return left->second > right->second;
//		}
//
//	};
//	vector<string> topKFrequent(vector<string>& words, int k)
//	{
//		vector<map<string, int>::iterator> tmp;
//		vector<string> ret;
//		for (auto& e : words)
//		{
//			index[e]++;
//		}
//		int sz = index.size();
//		ret.reserve(sz);
//		tmp.reserve(sz);
//		map<string, int>::iterator it = index.begin();
//		while (it != index.end())
//		{
//			tmp.push_back(it);
//			++it;
//		}
//		stable_sort(tmp.begin(), tmp.end(), my_less());
//		for (int i = 0; i < k; i++)
//		{
//			ret.push_back(tmp[i]->first);
//		}
//		return ret;
//	}
//};
//
//class Solution2
//{
//	map<string, int> index;
//public:
//	struct my_grearter
//	{
//		bool operator()(pair<string, int> left, pair<string, int> right)
//		{
//			return left.second > left.second;
//		}
//	};
//
//	vector<string> topKFrequent(vector<string>& words, int k) 
//	{
//		for (auto& e : words)
//		{
//			index[e]++;
//		}
//		vector<pair<string, int>> ret;
//		vector<string> retString;
//		for (auto& e : index)
//		{
//			ret.push_back(e);
//		}
//		sort(ret.begin(), ret.end(), my_grearter());
//
//		for (int i = 0; i < k; i++)
//		{
//			retString.push_back(ret[i].first);
//		}
//		return retString;
//	}
//};
//
//class Solution3
//{
//	multimap<int, string, greater<int> >ismap;
//	map<string, int> simap;
//public:
//
//	vector<string> topKFrequent(vector<string>& words, int k) 
//	{
//		vector<string> ret;
//		for (auto& e : words)
//		{
//			simap[e]++;
//		}
//		for (auto& e : simap)
//		{
//			ismap.insert(make_pair(e.second, e.first));
//		}
//
//		for (auto& e : ismap)
//		{
//			ret.push_back(e.second);
//			k--;
//			if (k == 0)
//				break;
//		}
//		return ret;
//	}
//};

struct cmpGreater
{
	bool operator()(map<string, int>::iterator left, map<string, int>::iterator right)
	{
		return left->second > right->second;
	}
};
void test_oj1()
{
	map<string, int> simap;

	string str;
	while (cin >> str)
	{
		for (auto& e : str)
		{
			if (e >= 'A' && e <= 'Z')
			{
				e += 'a' - 'A';
			}
			if (e == '.')
				str.pop_back();
		}
		simap[str]++;
	}

	vector<map<string, int>::iterator> tmp;
	map<string, int>::iterator it = simap.begin();
	while (it != simap.end())
	{
		tmp.push_back(it);
		++it;
	}
	stable_sort(tmp.begin(), tmp.end(), cmpGreater());
	vector<string> ret;
	for (auto& e : tmp)
	{
		cout << e->first << ":" << e->second << endl;
	}
}

struct CmpGreater
{
	bool operator()(map<string, int>::iterator left, map<string, int>::iterator right)
	{
		return left->second > right->second;
	}
};
void test_oj2()
{
	map<string, int> simap;

	string str;
	while (cin >> str)
	{
		for (auto& e : str)
		{
			if (e >= 'A' && e <= 'Z')
			{
				e += 'a' - 'A';
			}
			if (e == '.')
				str.pop_back();
		}
		simap[str]++;
	}

	vector<map<string, int>::iterator> tmp;
	map<string, int>::iterator it = simap.begin();
	while (it != simap.end())
	{
		tmp.push_back(it);
		++it;
	}
	stable_sort(tmp.begin(), tmp.end(), CmpGreater());
	vector<string> ret;
	for (auto& e : tmp)
	{
		cout << e->first << ":" << e->second << endl;
	}
}

//class Solution4
//{
//	set<int> s1;
//	set<int> s2;
//public:
//	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
//	{
//		vector<int> ret;
//		for (auto& e : nums1)
//		{
//			s1.insert(e);
//		}
//		for (auto& e : nums2)
//		{
//			s2.insert(e);
//		}
//
//		for (auto& e : s2)
//		{
//			if (s1.find(e) != s1.end())
//			{
//				ret.push_back(e);
//			}
//		}
//		return ret;
//	}
//};


size_t min(size_t a, size_t b)
{
	return a > b ? b : a;
}

class Solution5
{
	map<int, int> s1;

public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
	{
		vector<int> ret;
		ret.reserve(min(nums1.size(), nums2.size()));
		for (auto& e : nums1)
		{
			s1.insert(make_pair(e, 1));
		}
		for (auto& e : nums2)
		{
			if (s1[e] == 1)
			{
				ret.push_back(e);
				++s1[e];
			}
		}
		return ret;
	}
};
class Solution6 
{
	set<int> index;
public:
	int firstMissingPositive(vector<int>& nums)
	{
		for (auto& e : nums)
		{
			index.insert(e);
		}
		int tmp = 0;
		int target = 0;
		bool isTarget = false;
		for (auto& e : index)
		{
			if (!isTarget)
			{
				target = e;
				tmp = target;
				isTarget = true;
			}
			if (e != target)
			{
				return target;
			}
			target++;
		}
		return target + 1;
	}
};

class Solution7
{
	map<int, int, greater<int>> s1;
	multimap<int, int> s2;
public:
	vector<int> frequencySort(vector<int>& nums)
	{
		vector<int> ret;
		ret.reserve(nums.size());
		for (auto& e : nums)
		{
			s1[e]++;
		}

		for (auto& e : s1)
		{
			s2.insert(make_pair(e.second, e.first));
		}

		for (auto& e : s2)
		{
			for (int i = 0; i < e.first; i++)
			{
				ret.push_back(e.second);
			}
		}
		return ret;
	}
};

class Solution8
{
	map<int, int> s;
public:
	int findPairs(vector<int>& nums, int k)
	{
		int cnt = 0;
		for (auto& e : nums)
		{
			s[e]++;
		}
		map<int, int>::iterator slow = s.begin();
		map<int, int>::iterator fast = s.begin();
		while (fast != s.end())
		{
			if (fast->first - slow->first == k)
			{
				if (k == 0)
				{
					if (fast->second > 1)
						cnt++;

				}
				else
				{
					cnt++;
				}
				slow++;
				fast++;
			}
			else if (fast->first - slow->first > k)
			{
				slow++;
			}
			else
			{
				fast++;
			}
		}
		return cnt;
	}
};

class Solution9
{

public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		vector<vector<int>> ret;

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > 0)
				continue;
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			set<int> set;
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (j > i + 2
					&& nums[j] == nums[j - 1]
					&& nums[j - 1] == nums[j - 2]) { // 三元组元素b去重
					continue;
				}


				int c = -(nums[i] + nums[j]);

				if (set.find(c) != set.end())
				{
					ret.push_back({ nums[i], nums[j], c });
					set.erase(c);
				}
				else
				{
					set.insert(nums[j]);
				}
			}
		}
		return ret;
	}
};


class Solution10
{
public:
	vector<string> findRepeatedDnaSequences(string s)
	{
		vector<string> ans;
		if (s.size() <= 10)
			return ans;

		unordered_map<string, int> map;
		string::iterator left = s.begin();
		string::iterator right = s.begin() + 9;

		while (right != s.end())
		{
			string tmp(left, right + 1);
			if (map.find(tmp) != map.end() && map[tmp] == 0)
			{
				ans.push_back(tmp);
				map[tmp] = 1;
			}
			else
			{
				if (map.find(tmp) == map.end())
					map[tmp] = 0;
			}
			right++;
			left++;
		}
		return ans;
	}
};
int arr[13];


void test_oj()
{
	int arr[] = { -1,0,1,2,-1,-4 };
	vector<int> t(arr, arr + 6);
	vector<vector<int>> ret = Solution9().threeSum(t);
	cout << endl;
	for (auto& e : ret)
	{
		for (auto& a : e)
		{
			cout << a << " ";
		}
		cout << endl;
	}
}
int main()
{
	char arr[] = "qwertyu";

	string s(arr, arr + 7);

	vector<string> ret = Solution10().findRepeatedDnaSequences("AAAAAAAAAAAAA");

	for (auto& e : ret)
	{
		cout << e << endl;
	}
	//vector<int> ret = Solution7().frequencySort(t);
	//int ret = Solution8().findPairs(t, 2);
	//cout << ret;
	/*for (auto& e : ret)
	{
		cout << e << " ";
	}*/
	return 0;
	
}