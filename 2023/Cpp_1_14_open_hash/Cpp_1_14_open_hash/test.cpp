#include"HashTable.h"
#include<iostream>

template<class K, class V>
struct KeyOfMap
{
	K operator()(const pair<K, V> data)
	{
		return data.first;
	}
};
void test_hashT();
void test_string();


int main()
{
	test_string();
	//test_hashT();
	return 0;
}

void test_string()
{
	sx::HashTable<string, pair<string, string>, KeyOfMap<string, string>, sx::DefaultHash<string>> h1;
	h1.Insert(make_pair("apple", "ƻ��"));
	h1.Insert(make_pair("heacp", "����"));
	h1.Insert(make_pair("peach", "����"));
	h1.Insert(make_pair("pear", "��"));
	h1.Insert(make_pair("hit", "����"));
	h1.Insert(make_pair("list", "�б�"));
	h1.Erase("heacp");
	h1.Erase("1");
}

void test_hashT()
{
	sx::HashTable<int, pair<int, int>, KeyOfMap<int, int>, sx::DefaultHash<int>> h1;
	h1.Insert(make_pair(1, 1));
	h1.Insert(make_pair(11, 11));
	h1.Insert(make_pair(2, 2));
	h1.Insert(make_pair(12, 12));
	h1.Insert(make_pair(16, 16));
	h1.Insert(make_pair(13, 13));
	h1.Insert(make_pair(21, 21));
	h1.Insert(make_pair(31, 31));
	sx::HashTable<int, pair<int, int>, KeyOfMap<int, int>, sx::DefaultHash<int>>::Iterator it = h1.Begin();
	while (it != h1.End())
	{
		cout << it->first << " " << it->second << endl;
		++it;
	}

	if (h1.Find(11)._pNode)
		cout << "�ҵ���11" << endl;
	else
		cout << "û�ҵ�11" << endl;

	if (h1.Find(12)._pNode)
		cout << "�ҵ���12" << endl;
	else
		cout << "û�ҵ�12" << endl;

	if (h1.Find(19)._pNode)
		cout << "�ҵ���19" << endl;
	else
		cout << "û�ҵ�19" << endl;

	h1.Erase(11);

	it = h1.Begin();
	while (it != h1.End())
	{
		cout << it->first << " " << it->second << endl;
		++it;
	}
	//h1.Erase(4);

	//cout << endl;
	//if (h1.Find(11)._pNode)
	//	cout << "�ҵ���11" << endl;
	//else
	//	cout << "û�ҵ�11" << endl;

	//if (h1.Find(12)._pNode)
	//	cout << "�ҵ���12" << endl;
	//else
	//	cout << "û�ҵ�12" << endl;

	//if (h1.Find(19)._pNode)
	//	cout << "�ҵ���19" << endl;
	//else
	//	cout << "û�ҵ�19" << endl;

}