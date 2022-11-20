#include<iostream>
#include<stdlib.h>
#include<map>
#include<string>
using namespace std;
#include"binary_search_tree.h"

class S
{
public:
	S()
		:
		_a(10),
		b(0)
	{

	}
private:
	 int _a;
	int b;
};
void test()
{
	//if(1)
	//	;
	//else
	//{
	//	//ѡ��������������Сֵ����滻
	//	Node* reparent = nullptr;
	//	Node* replace = cur->right;
	//	while (replace->left)
	//	{
	//		reparent = replace;
	//		replace = replace->left;
	//	}
	//	swap(replace, cur);
	//	if (replace->right)
	//	{
	//		reparent->left = replace->right;
	//	}

	//}

	//cout << "test" << endl;

	S s1;
	S s2;
	std::swap(s1, s2);
}

void test_map()
{
	string arr[] = { "apple", "banana", "apple" };
	map<string, int> count_map;
	for (auto& e : arr)
	{
		auto ret = count_map.insert(make_pair(e, 1));
		if (ret.second == false)
		{
			ret.first->second++;
		}
	}
	for (auto& e : count_map)
	{
		cout << e.first << ":" << e.second << endl;
	}
}

void test_tree()
{
	sx::BSTree<int, int> t;
	t.insert_r(1, 1);
	t.insert_r(3, 2);
	t.insert_r(2, 0);
	
	sx::BSTree<int, int> tmp = t;

	tmp = t;

	tmp.in_order();
	cout << endl;

	t.erase_r(2);
	t.erase(1);
	t.erase_r(3);
	t.erase_r(4);
	t.in_order();
	t.insert_r(1, 0);
	t.insert(2, 0);
	t.insert(0, 0);
	t.in_order();
}

//void test_btree()
//{
//	key::BSTree<int> t1;
//	t1.Insert(1);
//	t1.Insert(3);
//	t1.Insert(2);
//}

void TestBSTree2()
{
	string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };
	// ˮ�����ֵĴ���
	sx::BSTree<string, int> countTree;
	for (const auto& str : arr)
	{
		auto ret = countTree.find_r(str);
		if (ret == nullptr)
		{
			countTree.insert_r(str, 1);
		}
		else
		{
			ret->_val++;  // �޸�value
		}
	}

	countTree.in_order();
}


void TestBSTree()
{
	sx::BSTree<string, string> dict;
	dict.insert_r("insert", "����");
	dict.insert_r("erase", "ɾ��");
	dict.insert_r("left", "���");
	dict.insert_r("string", "�ַ���");
	dict.erase_r("left");
	dict.insert("left", "�뿪");
	string str;
	while (cin >> str)
	{
		auto ret = dict.find(str);
		if (ret)
		{
			cout << str << ":" << ret->_val << endl;
		}
		else
		{
			cout << "����ƴд����" << endl;
		}
	}

	string strs[] = { "ƻ��", "����", "ƻ��", "ӣ��", "ƻ��", "ӣ��", "ƻ��", "ӣ��", "ƻ��" };
	// ͳ��ˮ�����ֵĴ�
	sx::BSTree<string, int> countTree;
	for (auto str : strs)
	{
		auto ret = countTree.find(str);
		if (ret == nullptr)
		{
			countTree.insert_r(str, 1);
		}
		else
		{
			ret->_val++;
		}
	}
	countTree.erase_r("ƻ��");
	countTree.in_order();
}

void TestBSTree3()
{
	sx::BSTree<int, string> t1;
	t1.insert(6, "six");
	t1.insert_r(1, "one");
	t1.insert(2, "two");
	t1.insert(3, "three");
	t1.insert_r(4, "four");
	t1.insert(5, "five");
	t1.insert(6, "six");
	t1.insert_r(1, "one");
	t1.insert(2, "two");
	t1.insert(3, "three");
	t1.insert_r(4, "four");
	t1.insert(5, "five");
	t1.insert(6, "six");
	sx::BSTree<int, string> t2;
	t2 = t1;
	t2.erase_r(2);
	t2.erase_r(6);
	t2.in_order();
}

void TestBSTree4()
{
	sx::BSTree<int, string> t1;
	t1.insert_r(10, "10");
	t1.insert_r(7, "7");
	t1.insert_r(13, "13");
	t1.insert_r(11, "11");
	t1.insert_r(15, "15");
	t1.insert_r(12, "12");
	t1.erase_r(10);
	t1.erase_r(11);
	t1.in_order();
}
int main()
{
	//TestBSTree4();
	//TestBSTree3();
	TestBSTree();
	//TestBSTree2();
	//test_btree();
	//test_tree();
	//test();
	//test_map();

	return 0;
}