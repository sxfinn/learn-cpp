#include<iostream>
#include<vector>

using namespace std;

//栈的模拟

namespace sx
{
	template<class T>
	class stack
	{
	public:
		stack()
			:
			_v()
		{

		}
		stack(stack& s)
		{
			for (int i = 0; i < s._v.size(); i++)
			{
				_v.push_back(s._v[i]);
			}
		}
		T& top()
		{
			return _v.back();
		}
		void pop()
		{
			_v.pop_back();
		}
		void push(const T& val)
		{
			_v.push_back(val);
		}
		bool empty()
		{
			return _v.empty();
		}
	private:
		std::vector<T> _v;
	};

}
void test1()
{
	sx::stack<int> s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	cout << s1.top() << endl;
	s1.pop();
	cout << s1.top();

}
int main()
{
	test1();
	return 0;
}

////改进
//class MyQueue 
//{
//public:
//    MyQueue()
//        :
//        s1(),
//        s2(),
//        val(0)
//    {
//
//    }
//
//    void push(int x)
//    {
//        if (s1.empty())
//        {
//            val = x;
//        }
//        s1.push(x);
//    }
//
//    int pop()
//    {
//        int ret = 0;
//        if (!s2.empty())
//        {
//            ret = s2.top();
//            s2.pop();
//            return ret;
//        }
//        while (!s1.empty())
//        {
//            s2.push(s1.top());
//            s1.pop();
//        }
//        ret = s2.top();
//        s2.pop();
//        return ret;
//    }
//
//    int peek()
//    {
//        if (s2.empty())
//            return val; 
//        else
//            return s2.top();
//    }
//
//    bool empty()
//    {
//        return s1.empty() && s2.empty();
//    }
//private:
//    stack<int> s1;
//    stack<int> s2;
//    int val;
//};
//两个栈实现队列
//class MyQueue {
//public:
//    MyQueue() 
//        :
//        s1(),
//        s2()
//    {
//
//    }
//
//    void push(int x) 
//    {
//        s1.push(x);
//    }
//
//    int pop() 
//    {
//        while (!s1.empty())
//        {
//            s2.push(s1.top());
//            s1.pop();
//        }
//        int ret = s2.top();
//        s2.pop();
//        while (!s2.empty())
//        {
//            s1.push(s2.top());
//            s2.pop();
//        }
//        return ret;
//    }
//
//    int peek() 
//    {
//        while(!s1.empty())
//        {
//            s2.push(s1.top());
//            s1.pop();
//        }
//        int ret = s2.top();
//        
//        while (!s2.empty())
//        {
//            s1.push(s2.top());
//            s2.pop();
//        }
//        return ret;
//    }
//
//    bool empty() 
//    {
//        return s1.empty();
//    }
//private:
//    stack<int> s1;
//    stack<int> s2;
//};
//int main()
//{
//    MyQueue m;
//    m.push(1);
//    m.push(2);
//    cout << m.peek();
//    cout <<m.pop();
//	return 0;
//}