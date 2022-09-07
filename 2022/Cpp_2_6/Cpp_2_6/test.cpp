#include<iostream>
using namespace std;


int add(int a, int b)
{
	return a + b;
}

int main()
{
	int a = 1;
	cout << a << endl;  
	int& b = a;
	cin >> a;
	cout << a << endl;
	cout << b << endl;
	return 0;
}