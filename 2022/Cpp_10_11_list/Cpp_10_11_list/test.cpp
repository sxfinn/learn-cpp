//#include<iostream>
//#include<list>
//using namespace std;
#include"list.h"
using namespace sx;


int main()
{
	list<string> lt1;
	lt1.push_back("hello");
	lt1.push_back("world");
	const list<string> lt2 = lt1;
	for (auto e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
//int main()
//{	
//	list<int> lt1;
//	lt1.push_back(1);
//	lt1.push_back(2);
//	lt1.push_back(3);
//	lt1.push_back(4);
//	lt1.push_back(5);
//	const list<int> lt2 = lt1;
//	//lt1.clear();
//	list<int>::iterator it = lt1.begin();
//	*it = 10;
//	for (auto e : lt1)
//	{
//		cout << e << " ";
//	}
//	
//	//cout << 
//	return 0;
//}

//#include"list.h"
//int main()
//{
//	sx::list<int> lt1;
//	
//	lt1.push_back(1);
//	lt1.push_back(2);
//	lt1.push_back(3);
//	lt1.push_back(4);
//	lt1.push_back(5);
//	//sx::list<int>::iterator it = lt1.begin();
//	//++it;
//	sx::list<int> lt2 ;
//	lt2 = lt1;
//	lt1.clear();
//	//lt2.push_front(0);
//	for (auto& e : lt1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	for (auto& e : lt2)
//	{
//		cout << e << " ";
//	}
//	
//	cout << endl;
//	return 0;
//}