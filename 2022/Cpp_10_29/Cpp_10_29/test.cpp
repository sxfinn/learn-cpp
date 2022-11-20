#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<queue>
using namespace std;
class Solution3
{
public:
    int evalRPN(vector<string>& tokens) 
    {
        for (auto& e : tokens)
        {
            int flag = 0;
            if ((++flag, e == "+" )|| (++flag, e == "-") || (++flag, e == "*") || (++flag, e == "/"))
            {
                long long right = st.top();
                st.pop();
                long long  left = st.top();
                st.pop();
                switch (flag)
                {
                case 1:st.push((long long )left + right);
                    break;
                case 2:st.push((long long)left - right);
                    break;
                case 3:st.push((long long)left * right);
                    break;
                case 4:st.push((long long)left / right);
                    break;
                default:
                    cout << "error" << endl;
                    break;
                }
            }
            else
            {
                int num = stoi(e);
                st.push(num);
            }
        }
        return (long long )st.top();
    }
private:
    stack<long long> st;
};
void test()
{
    const char* arr[] = { "-128","-128","*","-128","*","-128","*","8","*","-1","*" };
    vector<string> v1(arr, arr + 11);

    int ret = Solution3().evalRPN(v1);
    cout << ret << endl;
}
class Solution4
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        for (auto& e : nums)
        {
            heap.push(e);
        }
        while (--k)
        {
            heap.pop();
        }
        return heap.top();
    }
private:
    priority_queue<int, vector<int>, less<int>> heap;
};

class Solutio2 
{
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        int i = 0;
        for (auto& e : pushV)
        {
            st.push(e);
            while (!st.empty() && st.top() == popV[i])
            {
                st.pop();
                ++i;
            }
        }
        return st.empty();
    }
private:
    stack<int> st;
};

class Solution1 
{
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) 
    {
        int j = 0;
        int i = 0;
        while (i < pushV.size())
        {
            while (i < pushV.size())
            {
                st.push(pushV[i]);
                ++i;
                if (st.top() == popV[j])
                    break;
            }
            while (!st.empty() && j < popV.size() && st.top() == popV[j])
            {
                st.pop();
                ++j;
            }
        }
        return st.empty();
    }
private:
    stack<int> st;
};

class MinStack 
{
public:
    MinStack() 
    {

    }

    void push(int val) 
    {
        st.push(val);
        if (stmin.empty() || val <= stmin.top())
            stmin.push(val);
    }

    void pop() 
    {
        if (st.top() == stmin.top())
        {
            stmin.pop();
        }
        st.pop();
    }

    int top() 
    {
        return st.top();
    }

    int getMin() 
    {
        return stmin.top();
    }
private:
    stack<int> st;
    stack<int> stmin;
};




template<class T1, class T2>
class S
{
public:
    S()
    {
        cout << "<T1, T2>" << endl;
    }
};
template<class T1, class T2>
class S<T1&, T2*>
{
public:
    S()
    {
        cout << "<T1*, T2&>" << endl;
    }
};


template<class T1, class T2>
class S<T1*, T2*>
{
public:
    S()
    {
        cout << "<T1*, T2*>" << endl;
    }
};


void clas()
{
    S<double, int> a;
}


//template<class T1, class T2>
//void tes(T1 t1, T2 t2)
//{
//    cout << "<T1, T2>" << endl;
//}
template<class T1, class T2>
void tes(T1* t1, T2* t2)
{
    cout << "<T1*, T2*>" << endl;
}
//template<class T1, class T2>
//void tes(T1 t1, T2 t2)
//{
//    cout << "<T1*, T2*>" << endl;
//}
//template<>
//void tes(int i , char c)
//{
//    cout << "<int, char>" << endl;
//}
template<>
void tes<int, char>(int* pi, char* pc)
{
    cout << "<int*, char*>" << endl;
}
//template<class T>
//void tes(T t)
//{
    //cout << "<T>" << endl;
//}
//template<>

//void tes<char>(char c, double d)
//{
//
//}
void func()
{
    int a = 0;
    int* pa = &a;
    //tes(a);
    tes<int, char>( & a, (char*)pa);
}

class T2
{
public:
    T2()
    {

    }
private:

    int a;
};

class Test
{
public:
    static Test GetObj()
    {
        return Test();
    }
    Test(const Test& t)
        :i()
    {
        cout << "copy" << endl;
    }
private:
    Test()
        :
        i(10)
    {
        cout << "construct" << endl;
    }
    int i;
};

class A
{
public:
    A()
    {
        cout << "A()" << endl;
    }
    ~A()
    {
        cout << "~A()" << endl;
    }
    void test()
    {
        cout << "test" << endl;
    }
};

class B : public A
{
public:
    B()
    {
        cout << "B()" << endl;
        test();
    }
    ~B()
    {
        //~A();
        cout << "~B()" << endl;
    }
    void test()
    {
        cout << "test1" << endl;
    }
};
int main()
{
    B b;
    //Test t(Test::GetObj());
    //Test t1 = t;
    //func();
    //clas();
    return 0;
}