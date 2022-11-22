#include"AVLTree.h"
#include<string>
#include<Windows.h>

void test_avltree1()
{
	int arr[] = { 16851, 17865 ,17219 ,15219, 6904, 5717 ,16364 , 83248};
	sx::AVLTree<int, int> t1;
	srand(size_t(time(nullptr)));
	//for (int i = 0; i < 8; i++)
	//{
	//	t1.Insert(make_pair(arr[i], arr[i]));
	//}
	for (int i = 0; i < 200000; i++)
	{
		int random = rand();
		t1.Insert(make_pair(random, random));
		t1.Insert(make_pair(random*2, random*2));
		//cout << random << " ";
	}
	cout << "是否平衡:" << t1.IsBLTree();
	cout << "是否平衡，平衡因子是否在范围内，平衡因子是否与实际一致:" << t1.IsBalanceTree();
	cout << "高度:" << t1.Height() << endl;
	cout << "遍历:";
	t1.InOrder();
}


void test_avltree2()
{
	sx::AVLTree<int, int> t1;
	for (int i = 0; i < 2000000; i++)
	{
		t1.Insert(make_pair(i, i));
	}
	cout << "是否平衡:" << t1.IsBLTree() << endl;
	cout << "是否平衡，平衡因子是否在范围内，平衡因子是否与实际一致:" << t1.IsBalanceTree() << endl;
	cout << "高度:" << t1.Height() << endl;
}

void test_avltree3()
{
	sx::AVLTree<int, int> t1;
	for (int i = 0; i < 200; i++)
	{
		t1.Insert(make_pair(i, i));
	}
	sx::AVLTree<int, int> t2;
	//t2.Insert(make_pair(202,202));
	//t2.Insert(make_pair(303, 303));
	//t1.swap(t2);
	t2 = t1;
	t1.InOrder();
	cout << endl;
	t2.InOrder();
	
}

void test_avltree4()
{
	sx::AVLTree<int, int> t1;
	for (int i = 0; i < 20; i++)
	{
		t1.Insert(make_pair(i, i));
	}

	sx::AVLTree<int, int> t2 = t1;
	t2 = t1;
	cout << t1.IsBalanceTree();
	cout << t1.IsBLTree();
	cout << t1.Height();
	cout << endl;
	cout << t2.IsBalanceTree();
	cout << t2.IsBLTree();
	cout << t2.Height();

	cout << endl;
	t1.InOrder();
	cout << endl;
	t2.InOrder();
}

int main()
{
	//test_avltree1();
	//test_avltree2();
	//test_avltree3();
	test_avltree4();
	return 0;
}