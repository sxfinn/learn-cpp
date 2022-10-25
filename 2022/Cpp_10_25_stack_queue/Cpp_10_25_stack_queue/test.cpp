#include"stack.h"
#include"queue.h"
#include"priority_queue.h"
#include<deque>
void test_stack()
{
	sx::stack<int, deque<int>> st1;
	st1.push(1);
	st1.push(2);
	st1.push(3);
	st1.push(4);
	st1.push(5);
	sx::stack<int, deque<int>> st2;
	st2.push(10);
	st2.push(20);
	st2.push(30);
	st2.push(40);
	st2.push(50);
	st1.swap(st2);
	cout << st1.size() << "   " << st2.size() << endl;
	while (!st1.empty())
	{
		cout << st1.top() << " ";
		st1.pop();
	}
	cout << endl;
	while (!st2.empty())
	{
		cout << st2.top() << " ";
		st2.pop();
	}
	cout << endl;
}

void test_queue()
{
	sx::queue<int> que1;
	que1.push(1);
	que1.push(2);
	que1.push(3);
	que1.push(4);
	sx::queue<int> que2;
	que2.push(10);
	que2.push(20);
	que2.push(30);
	que1.swap(que2);
	cout << que1.size() << "   " << que2.size() << endl;
	//que1.swap(que2);
	while (!que1.empty())
	{
		cout << que1.front() << " ";
		que1.pop();
	}
	cout << endl;
	while (!que2.empty())
	{
		cout << que2.front() << " ";
		que2.pop();
	}
	cout << endl;
}

struct goods
{
	goods(int price, int sales, int praise)
	{
		_price = price;
		_sales = sales;
		_praise = praise;
	}
	
	size_t _price;
	size_t _sales;
	size_t _praise;

};
struct goodscmpless
{
	bool operator()(goods g1, goods g2)
	{
		return g1._price < g2._price;
	}
};

bool cmppriceless(goods g1, goods g2)
{
	return g1._price < g2._price;
}
void test_priority_queue()
{
	goods a(1, 5, 10);
	goods b(2, 4, 7);
	goods c(10, 1, 9);
	goods d(1, 5, 10);
	goods e(9, 4, 7);
	goods f(20, 1, 9);
	goods g(1, 5, 10);
	goods h(28, 4, 7);
	goods i(0, 1, 9);
	sx::priority_queue<goods, vector<goods>, bool(*)(goods g1, goods g2)> pq(cmppriceless);
	pq.push(d);
	pq.push(e);
	pq.push(f);
	pq.push(g);
	pq.push(h);
	pq.push(i);
	pq.push(a);
	pq.push(b);
	pq.push(c);
	
	/*int i = 0;
	while (i < 10)
	{
		int num = rand() % 10;
		pq.push(num);
		++i;
	}
	pq.pop();
	pq.pop();
	pq.pop();
	pq.pop();*/
}

void test_priority_queue2()
{
	int a[] = { 1, 4, 2, 7, 8, 9 };
	sx::priority_queue<int> pq(a, a + 6);
}
int main()
{
	
	//test_priority_queue();
	test_priority_queue2();
	//test_stack();
	//test_queue();
	return 0;
}