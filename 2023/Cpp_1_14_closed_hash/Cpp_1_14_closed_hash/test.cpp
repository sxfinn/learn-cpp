#include"HashTable.h"
#include<iostream>
using namespace std;

void test_hash();
void test_string_hash();

struct HashF
{
	size_t operator()(const string& str)
	{
		return 0;
	}
};

void test_ht_swap()
{
	sx::HashTable<string, int> h1;
	h1.Insert(make_pair("haha", 1));
	sx::HashTable<string, int> h2;

	h1.Swap(h2);
}

int main()
{
	//test_ht_swap();
	test_string_hash();
	//test_hash();
	return 0;
}

void test_string_hash()
{
	sx::HashTable<string, int> h1;
	h1.Insert(make_pair("gelmo", 1));
	h1.Insert(make_pair("idlkp", 1));
	h1.Insert(make_pair("gqlmo", 1));
	h1.Insert(make_pair("iclkp", 1));
	h1.Insert(make_pair("gklmo", 1));
	h1.Insert(make_pair("iplkp", 1));
	h1.Insert(make_pair("geblmo", 1));
	h1.Insert(make_pair("idukp", 1));
	h1.Insert(make_pair("germo", 1));
	h1.Insert(make_pair("idmkp", 1));

	cout << h1.Find("iclkp") << endl;
	cout << h1.Find("idukp") << endl;
	cout << h1.Find("idmkp") << endl;
	cout << endl;
	cout << h1.Find("idmkk") << endl;
	cout << h1.Find("acbd") << endl;
	cout << h1.Find("gello") << endl;

	cout << h1.Erase("iclkp") << endl;
	cout << h1.Erase("idukp") << endl;
	cout << h1.Erase("idmkk") << endl;

	cout << endl;
	cout << h1.Find("iclkp") << endl;
	cout << h1.Find("idukp") << endl;
	cout << h1.Find("idmkp") << endl;
	cout << endl;
	cout << h1.Find("idmkk") << endl;
	cout << h1.Find("acbd") << endl;
	cout << h1.Find("gello") << endl;
}
void test_hash()
{
	sx::HashTable<int, int> h1;

	//cout << h1.Find(1) << endl;
	//h1.Insert(make_pair(1, 1));
	//cout << h1.Find(1) << endl;
	//h1.Erase(1);
	//cout << h1.Find(1) << endl;
	h1.Insert(make_pair(1, 1));
	h1.Insert(make_pair(11, 11));
	h1.Insert(make_pair(3, 3));
	h1.Insert(make_pair(5, 5));
	h1.Insert(make_pair(23, 23));
	h1.Insert(make_pair(4, 4));
	h1.Insert(make_pair(14, 14));
	h1.Insert(make_pair(17, 17));
	h1.Insert(make_pair(13, 13));

	cout << h1.Find(1) << endl;
	cout << h1.Find(3) << endl;
	cout << h1.Find(5) << endl;
	cout << h1.Find(7) << endl;
	cout << h1.Find(9) << endl;
	cout << h1.Find(11) << endl;
	cout << h1.Find(13) << endl;

	h1.Erase(1);
	cout << h1.Find(1) << endl;
}