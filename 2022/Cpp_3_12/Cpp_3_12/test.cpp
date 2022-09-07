#include<iostream>
#include<queue>
#include<list>
#include<vector>
#include<stack>
#include<deque>
#include<string>
using namespace std;
//template<class T, class Container =  vector<T>>
//class S
//{
//public:
//    //typedef  Container::value_type v;
//    typedef typename Container::value_type v1;
//    typedef T t;
//    typedef int i;
//    S()
//    {}
//    void print()
//    {}
//    //Container a;
//    int b;
//    static int s;
//};
class S
{
public:
    S(int _a = 1)
        :
        a()
    {}
    int a;
};
template<class T>
bool eq(T& a, T& b)
{
    return a == b;
}
bool eq(const char*const  a,const  char*const  b)
{
    return strcmp(a, b) == 0;
}
int main()
{
    char arr1[] = "hehe";
    char arr2[] = "hehe";
    cout << eq(arr1, arr2);
    cout << eq("hehe", "hehe");
    //string s1 = "hehe";
    //string s2 = "hehe";
    //s1 += '1';
    //s2 += '1';
    //cout << s1.compare(s2);
    //S().a;
    //int& a = int(4);
    //vector<int> d1;
    //d1.push_back(1);
    //vector<int> d2;
    //d2.push_back(1);
    ////d2.push_back(2);
    //cout << (d1 == d2);
    return 0;
}
//层序遍历二叉树
 /*struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> vv;
        queue<TreeNode*> q1;
        if (root)
            q1.push(root);
        else
            return vv;
        int len = 1;
        while (q1.front())
        {
            vector<int> v;
            for (int i = 0; i < len; i++)
            {
                if(q1.front())
                    v.push_back(q1.front()->val);
                q1.push(q1.front()->left);
                q1.push(q1.front()->right);
                q1.pop();
            }
            vv.push_back(v);
            len = q1.size();
        }
        return vv;
    }
};*/

////双队列实现栈
//class MyStack 
//{
//public:
//    MyStack() 
//    {
//
//    }
//
//    void push(int x) 
//    {
//        q1.push(x);
//    }
//
//    int pop() 
//    {
//        while (q1.size() > 1)
//        {
//            q2.push(q1.front());
//            q1.pop();
//        }
//        int ret = q1.front();
//        q1.pop();
//        q1.swap(q2);
//        return ret;
//    }
//
//    int top() 
//    {
//        while (q1.size() > 1)
//        {
//            q2.push(q1.front());
//            q1.pop();
//        }
//        int ret = q1.front();
//        q2.push(ret);
//        q1.pop();
//        q1.swap(q2);
//        return ret;
//    }
//
//    bool empty() 
//    {
//        return q1.empty();
//    }
//private:
//    queue<int> q1;
//    queue<int> q2;
//};
//void test1()
//{
//
//}
//int main()
//{
//    test1();
//    return 0;
//}
//int main()
//{
//    stack<int> s1;
//    s1.push(1);
//    stack<int> s2 = s1;
//    return 0;
//}
//namespace sx
//{
//	template<class T>
//	class queue
//	{
//	public:
//		queue()
//		{
//
//		}
//		T& front()
//		{
//			return l.front();
//		}
//		void pop()
//		{
//			l.pop_front();
//		}
//		bool empty()
//		{
//			return l.empty();
//		}
//		void push(const T& val)
//		{
//			l.push_back(val);
//		}
//	private:
//		list<T> l;
//	};
//	template<class T>
//	class stack
//	{
//	public:
//		
//		stack()
//			:
//			v1()
//			
//		{}
//		void push(const T &val)
//		{
//			v1.push_back(val);
//		}
//		void pop()
//		{
//			v1.pop_back();
//		}
//		T& top()
//		{
//			return v1.back();
//		}
//		bool empty()
//		{
//			return v1.empty();
//		}
//
//	private:		
//		vector<T> v1;
//	};
//}
//template<class T>
//T add(T a, T b)
//{
//	return a + b;
//}
//int main()
//{
//	int t1 = 1;
//	int t2 = 2;
//	int ret = add(t1, t2);
//	int ret1 = add<int>(3, 4);
//	return 0;
//}