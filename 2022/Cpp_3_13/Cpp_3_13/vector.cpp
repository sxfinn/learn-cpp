//#include<iostream>
//using namespace std;
//
//
//int main()
//{
//	char a[6];
//	cin >> a;
//	cout << a;
//	return 0;
//}

//class S
//{
//public:
//	S()
//		:
//		s(s.c_str())
//	{
//		
//	}
//	int operator()(int a, int b)
//	{
//		return a;
//	}
//	int operator+(int a)
//	{
//		return a + _b;
//	}
//	int _a = 1;
//	int _b =  1;
//	string s;
//};
//int main()
//{
//	S s;
//	s.operator()(3,4);//这两者等同
//	s(3, 4);
//	cout << s + 1;
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution
//{
//public:
//    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
//    {
//        vector<int> tmp(nums1);
//        int i = 0, j = 0;
//        nums1.resize(0);
//        while (i < m || j < n)
//        {
//            if (i == m)
//            {
//                nums1.push_back(nums2[j++]);
//            }
//            else if (j == n)
//            {
//                nums1.push_back(tmp[i++]);
//            }
//            else
//            {
//                if (tmp[i] < nums2[j])
//                {
//                    nums1.push_back(tmp[i++]);
//                }
//                else
//                {
//                    nums1.push_back(nums2[j++]);
//                }
//            }
//        }
//    }
//};
//int main()
//{
//    vector<int> v1;
//    v1.push_back(1);
//    v1.push_back(2);
//    v1.push_back(3);
//    v1.push_back(0);
//    v1.push_back(0); 
//    v1.push_back(0);
//
//    vector<int>v2;
//    v2.push_back(2);
//    v2.push_back(5);
//    v2.push_back(6);
//    Solution().merge(v1,3, v2,3);
//    for (auto& e : v1)
//    {
//        cout << e << " ";
//    }
//    return 0;
//}
//class Solution
//{
//public:
//    int removeDuplicates(vector<int>& nums)
//    {
//        int cur = 0;
//        for (auto& e : nums)
//        {
//            if (e != nums[cur])
//                nums[++cur] = e;
//        }
//        return cur + 1;
//    }
//};


//class Solution
//{
//public:
//    int removeElement(vector<int>& nums, int val)
//    {
//        int cur = 0;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (val == nums[i])
//                nums[cur++] = nums[i];
//        }
//        return cur;
//    }
//};

//#include"test.h"
//
////template
////int add(int a, int b);
////int add(int a, int b)
////{
////	return a + b;
////}
////template
////int add(int a, int b);
//template<class T>
//T add(T a, T b)
//{
//	return a + b;
//}
//
//int func(int a, int b)
//{
//	return a + b;
//}
