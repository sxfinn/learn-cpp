#include"RBTree.h"

void test_rbtree1()
{
	RBTree<int, int> t;
	for (int i = 0; i < 2000000; i++)
	{
		t.Insert(make_pair(i, i));
	}
	cout << "路径长度是否满足要求:" << t.IsHeightBalance() << endl;
	cout << "是否红黑树:" << t.IsRBTree() << endl;
	cout << "标准测试是否满足要求:" << t.IsBalanceTree() << endl;
	//t.InOrder();
}

void test_rbtree2()
{
	RBTree<int, int> t;
	srand((unsigned int)time(nullptr));
	for (int i = 0; i < 20000000; i++)
	{
		int random = rand();
		t.Insert(make_pair(random * 2, random));
		t.Insert(make_pair(random * 3, random));
		t.Insert(make_pair(random * 5, random));
		//cout << random << endl;
	}
	//t.InOrder();
	//cout << endl;
	cout << "路径长度是否满足要求:" << t.IsHeightBalance() << endl;
	cout << "是否红黑树:" << t.IsRBTree() << endl;
	cout << "标准测试是否满足要求:" << t.IsBalanceTree() << endl;
}

void test_rbtree3()
{
	RBTree<int, int> t;
	int arr[] = { 8940,29130,31103,29094,22216 };
	for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
	{
		t.Insert(make_pair(arr[i], arr[i]));
	}
	cout << "路径长度是否满足要求:" << t.IsHeightBalance() << endl;
	cout << "是否红黑树:" << t.IsRBTree() << endl;
	cout << "标准测试是否满足要求:" << t.IsBalanceTree() << endl;
	//t.InOrder();
}

void test_rbtree4()
{
	RBTree<int, int> t;
	//t.Insert(make_pair(1, 1));
	cout << "路径长度是否满足要求:" << t.IsHeightBalance() << endl;
	cout << "是否红黑树:" << t.IsRBTree() << endl;
	cout << "标准测试是否满足要求:" << t.IsBalanceTree() << endl;
	//t.InOrder();
}

void test_rbtree5()
{
	RBTree<string, int> t1;
	t1.Insert(make_pair("sss", 1));
	t1.Insert(make_pair("kkk", 2));
	t1.Insert(make_pair("jjj", 3));

	RBTree<string, int> t2;
	//t2 = t1;

}
int main()
{
	test_rbtree2();
	return 0;
}
