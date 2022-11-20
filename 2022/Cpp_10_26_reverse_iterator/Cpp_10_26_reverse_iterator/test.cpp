
#include"list.h"
#include"vector.h"

//#include<vector>
void test_list()
{
	int arr[] = { 2,3,6,8,2,0,7 };
	const sx::list<int> lst1(arr, arr + 7);
	sx::list<int>::const_reverse_iterator rit = lst1.rbegin();
	while (rit != lst1.rend())
	{
		//*rit = 1;
		cout << *rit << " ";
		++rit;
	}
}

void test_vector()
{
	int arr[] = { 2,3,6,8,2,0,7 };
	sx::vector<int> v1(arr, arr + 7);
	sx::vector<int>::reverse_iterator rit = v1.rbegin();
	while (rit != v1.rend())
	{
		cout << *rit << " ";
		++rit;
	}
}
int main()
{

	test_list();
	//test_vector();
	return 0;
}