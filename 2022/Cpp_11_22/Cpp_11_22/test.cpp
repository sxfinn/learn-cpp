#include"map.h"

#include"set.h"

void test_map()
{
	sx::map<int, int> m1;
	for (int i = 0; i < 20; i++)
	{
		m1[i] = i;
	}
	const sx::map<int, int> m2 = m1;
	sx::map<int, int>::iterator it = m1.begin();
	
	it->first = 2;//first理应是不能改变的
	cout << it->first << ":" << it->second << endl;
}

//void test_set()
//{
//	sx::set<int> s1;
//	for (int i = 0; i < 20; i++)
//	{
//		s1.insert(i);
//	}
//	for (auto& e : s1)
//	{
//		cout << e << " ";
//	}
//	//sx::set<int>::iterator it = s1.find(1);
//	//cout << *it;
//}
int main()
{
	test_map();
	return 0;
}