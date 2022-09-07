#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;


class Solution
{
public:
    inline int comeout(stack<int>& s1, char ch)
    {
        int right = s1.top();
        s1.pop();
        int left = s1.top();
        s1.pop();
        if (ch == '+')
            return left + right;
        else if (ch == '-')
            return left - right;
        else if (ch == '*')
            return left * right;
        else
            return left / right;
    }
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> s;
        for (auto& e : tokens)
        {
            switch (e[e.size() - 1])
            {
            case '+':
                s.push(comeout(s, '+'));
                break;
            case '-':
                s.push(comeout(s, '-'));
                break;
            case '*':
                s.push(comeout(s, '*'));
                break;
            case '/':
                s.push(comeout(s, '/'));
                break;
            default:
                int tmp = stoi(e);
                s.push(tmp);
            }
        }
        return s.top();
    }
   
};
int main()
{
    vector<string> v1;
    v1.push_back("4");
    v1.push_back("13");
    v1.push_back("5");
    v1.push_back("/");
    v1.push_back("+");
    int ret = Solution().evalRPN(v1);
    cout << ret;
    return 0;
}
//int main()
//{
//
//    string s("+-123");
//    int ret = stoi(s);
//    cout << ret;
//    return 0;
//}
//class Solution 
//{
//public:
//    bool IsPopOrder(vector<int> pushV, vector<int> popV) 
//    {
//        stack<int> s;
//        int i = 0 , j = 0;
//        while (i < pushV.size())
//        {
//            s.push(pushV[i]);
//            ++i;
//            while (j < popV.size() && !s.empty() && s.top() == popV[j])
//            {
//                s.pop();
//                ++j;
//            }
//        }
//        return i == j;
//    }
//};
//int main()
//{
//    vector<int> v1;
//    vector<int> v2;
//    v1.push_back(2);
//    v1.push_back(1);
//    v1.push_back(0);
//    v2.push_back(1);
//    v2.push_back(2);
//    v2.push_back(0);
//    bool ret = Solution().IsPopOrder(v1, v2);
//    cout << ret;
//    return 0;
//}
//class S
//{
//public:
//    S(int data = 0, int cnt = 1)
//    {
//        _data = data;
//        _cnt = cnt;
//    }
//    S& operator++()
//    {
//        _cnt++;
//        return *this;
//    }
//    S& operator--()
//    {
//        --_cnt;
//        return *this;
//    }
//
//    int _data;
//    int _cnt;
//};
//class MinStack {
//public:
//    MinStack()
//        :
//        _s(),
//        _minst()
//    {
//
//    }
//
//    void push(int val) 
//    {
//        _s.push(val);
//        if (_minst.empty() || val <= _minst.top()._data)
//        {
//            if (_minst.empty() || val < _minst.top()._data)
//            {
//                _minst.push(val);
//            }
//            else if(_minst.empty() || val == _minst.top()._data)
//            {
//                ++_minst.top();
//            }
//        }
//    }
//
//    void pop() 
//    {
//        if (_s.top()._data == _minst.top()._data)
//        {
//            if (_minst.top()._cnt > 1)
//                --_minst.top();
//            else
//                _minst.pop();
//        }
//        _s.pop();
//    }
//
//    int top() 
//    {
//        return _s.top()._data;
//    }
//
//    int getMin() 
//    {
//        return _minst.top()._data;
//    }
//private:
//    stack<S> _s;
//    stack<S> _minst;
//};
//void test1()
//{
//    MinStack m;
//    m.push(0);
//    m.push(1);
//    m.push(0);
//    cout << m.getMin() << endl;
//    m.pop();
//    cout << m.getMin();
//}
//class T
//{
//public:
//    T(int a = 1, int b = 0)
//        :
//        //_a(a),
//        _b()
//    {
//        
//    }
//    int _a = 10;
//    int _b = 10;
//};
//int main()
//{
//    //T t;
//    //cout << t._a << t._b;
//    test1();
//    return 0;
//}
//class MinStack 
//{
//public:
//    MinStack() 
//        :
//        _s(),
//        _minst()
//    {
//
//    }
//
//    void push(int val) 
//    {
//        _s.push(val);
//        if (_minst.empty() || val <= _minst.top())
//        {
//            _minst.push(val);
//        }
//    }
//
//    void pop() 
//    {
//        if (_s.top() == _minst.top())
//        {
//            _minst.pop();
//        }
//        _s.pop();
//    }
//
//    int top() 
//    {
//        return _s.top();
//    }
//
//    int getMin() 
//    {
//        return _minst.top();
//    }
//private:
//    stack<int> _s;
//    stack<int> _minst;
//};


//void test1()
//{
//	stack<int> s;
//	s.push(1);
//	s.push(2);
//	s.push(3);
//	while (!s.empty())
//	{
//		cout << s.top() << " ";
//		s.pop();
//	}
//	cout << endl;
//}
//void test2()
//{
//	queue<int> q1;
//	q1.push(1);
//	q1.push(2);
//	q1.push(3);
//	while (!q1.empty())
//	{
//		cout << q1.front() << " ";
//		q1.pop();
//	}
//	cout << endl;
//	//cout << q1.front();
//}
//void test3()
//{
//	int data = 0;
//	int min = 100;
//	stack<int> s1;
//	stack<int> minst;
//	while (cin >> data)
//	{
//		s1.push(data);
//		if (min >= data)
//		{
//			minst.push(data);
//			min = data;
//		}
//	}
//
//}
//int main()
//{
//	test3();
//	//test1();
//	//test2();
//	return 0;
//}