#include"UnorderedMap.h"
#include"UnorderedSet.h"
#include<iostream>
void test_unordered_set()
{
	sx::unordered_set<int> s1;
	s1.insert(1);
	//s1.insert(11);
	//s1.insert(111);
	//s1.insert(3);
	//s1.insert(5);
	//s1.insert(7);
	s1.insert(17);
	s1.insert(17);
	//s1.insert(9);
	//s1.insert(19);
	//s1.insert(15);
	
	sx::unordered_set<int> s2;
	s2 = s1;

	for (auto& e : s1)
	{
		cout << e << endl;
	}

	for (auto& e : s2)
	{
		cout << e << endl;
	}
}


void test_unordered_map()
{
	//sx::unordered_map<int, int> m1;
	//m1[1] = 1;
	//m1[1] = 2;
	const char* arr[] = { "apple", "orange", "banana", "pear", "apple", "banana", "pear" , "apple", "orange", "banana", "pear" , "peach" };
	sx::unordered_map<string, int> m2;
	
	for (auto& e : arr)
	{
		m2[e]++;
	}
	sx::unordered_map<string, int> m3 = m2;


	//m2.erase("peach");
	//m2.erase("aaa");

	m2["peach"] = 15;
	for (auto& e : m3)
	{
		cout << e.first << " " << e.second << endl;
	}
	cout << endl;

	sx::unordered_map<string, int>::iterator it;
	it = m2.begin();
	while (it != m2.end())
	{
		cout << it->first << " "  << it->second << endl;
		++it;
	}
	int a = 0;
}

int main()
{
	test_unordered_map();
	//test_unordered_set();
	return 0;
}