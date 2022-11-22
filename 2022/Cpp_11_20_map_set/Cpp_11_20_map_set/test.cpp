#include"map.h"
#include"set.h"
#include<map>
void test_set()
{
	sx::set<int> s1;
	srand((unsigned int)time(nullptr));
	for (int i = 0; i < 20; i++)
	{
		int random = rand();
		s1.insert(i);
	}
	const sx::set<int> s2 = s1;
	int cnt = 0;
	sx::set<int>::iterator it = s1.begin();
	while (it != s1.end())
	{
		++cnt;
		cout << *it << " ";
		++it;
	}
	cout << endl;
	sx::set<int>::iterator cit = s2.begin();
	while (cit != s2.end())
	{
		cout << *cit << " ";
		++cit;
	}
	cout << endl;
	
	it = s1.find(19);
	if(it != s1.end())
		cout << *it << endl;

	cit = s2.find(0);
	if (cit != s2.end())
		cout << *cit << endl;

	s1.IsValid();
	s2.IsValid();
	//cout << s1.empty() << endl;
}

void test_map()
{
	sx::map<int, int> m1;
	for (int i = 0; i < 20; i++)
	{
		m1.insert(make_pair(i, i));
	}
	
	m1[10] = 10000;
	const sx::map<int, int> m2 = m1;

	m1.clear();
	m1.insert(make_pair(222, 222));
	sx::map<int, int>::iterator it = m1.begin();
	while (it != m1.end())
	{
		cout << it->first << ":" << it->second << endl;
		it++;
	}
	sx::map<int, int>::const_iterator cit = m2.begin();
	cout << endl;
	while (cit != m2.end())
	{
		cout << cit->first << ":" << cit->second << endl;
		cit++;
	}
	cout << endl;
	it = m1.find(222);
	if (it != m1.end())
		cout << it->first << ":" << it->second << endl;
	cit = m2.find(20);
	if(cit != m2.end())
		cout << cit->first << ":" << cit->second << endl;
	cout << endl;


	cout << m1.IsValid() << endl;
	cout << m2.IsValid() << endl;
}

void test_map1()
{
	sx::map<int, string> m1;
	m1[1] = "one";
	m1[2] = "tow";
	m1[9] = "nine";
	m1[3] = "three";
	m1[2] = "tow";
	m1[9] = "nine";
	const sx::map<int, string> m2 = m1;
	sx::map<int, string> m3;
	m3 = m2;
	sx::map<int, string>::iterator it = m1.find(9);
	do
	{
		cout << it->second << endl;
		
	} while (it-- != m1.begin());
	
	sx::map<int, string>::const_iterator cit = m2.begin();
	while (cit != m2.end())
	{
		//cit->second = "hhe";
	}
}

void test_stdmap();


void test_map2()
{
	sx::map<int, string> m1;
	for (int i = 0; i < 26; i++)
	{
		m1[i] = 'a' + i;
	}
	const sx::map<int, string> m2 = m1;
	const sx::map<int, string> m3;
	for (auto& e : m2)
	{
		cout << e.first << ":" << e.second << endl;
	}
	m2.clear();
	//m1.insert(make_pair(1, "1"));
	//m2.insert(make_pair(1, "1"));


	//m1[1] = "qqq";
	//m2[1] = "qqqqqq";

	//sx::map<int, string>::iterator it1 = m1.find(2);
	//sx::map<int, string>::const_iterator ret2 = m2.find(2);
	//it1->second = "111";
	//it2->second = "222";

	//sx::map<int, string> m3;
	//m1.swap(m3);
	//for (auto& e : m3)
	//{
	//	cout << e.second << endl;
	//}

	//m1.IsValid();
	//m2.IsValid();


	//cout << m1.empty() << endl;
	//cout << m2.empty() << endl;
	//cout << m1.size() << endl;
	//cout << m2.size() << endl;
	//m1.clear();
	//m2.clear();

	//cout << m1.empty() << endl;
	//cout << m2.empty() << endl;
	//cout << m1.size() << endl;
	//cout << m2.size() << endl;

	//for (int i = 0; i < 26; i++)
	//{
	//	m1[i] = 'a' + i;
	//}
	//for (auto& e : m1)
	//{
	//	cout << e.second << endl;
	//}
}

void test_set1()
{
	sx::set<int> s1;
	for (int i = 0; i < 26; i++)
	{
		s1.insert(i);
	}
	const sx::set<int> s2 = s1;

	//pair<sx::set<int>::iterator, bool> ret = s1.insert(-1);
	//cout << *(ret.first);
	//*(ret.first) = 1;


	//sx::set<int>::iterator it1 = s1.begin();
	//sx::set<int>::const_iterator it2 = s2.begin();
	//*it1 = 2;
	//*it2 = 3;

	//s1.insert(-1);
	//s2.insert(-2);

	//sx::set<int>::iterator it1 = s1.find(1);
	//sx::set<int>::const_iterator it2 = s2.find(2);
	//*it1 = 1;
	//*it2 = 2;


	//s1.IsValid();
	//s2.IsValid();

	//sx::set<int> s3;
	//s3 = s2;
	//for (auto& e : s3)
	//{
	//	cout << e << endl;
	//}
	//s1.swap(s3);

	//cout << s1.empty() << endl;
	//cout << s2.empty() << endl;
	//cout << s1.size() << endl;
	//cout << s2.size() << endl;

	//s1.clear();
	//s2.clear();

	//cout << s1.empty() << endl;
	//cout << s2.empty() << endl;
	//cout << s1.size() << endl;
	//cout << s2.size() << endl;
}

void test_stdmap1();
int main()
{
	test_map2();
	//test_set1();
	//test_map1();
	//test_set();
	//test_map();
	//test_stdmap1();
	
	//test_stdmap();
	return 0;
}

void test_stdmap1()
{
	std::map<int, string> m;
	for (int i = 0; i < 26; i++)
	{
		m[i] = 'a' + 1;
	}
	const std::map<int, string> m1 = m;
	std::map<int, string>::iterator it = m.find(2);
	std::map<int, string>::const_iterator cit = m1.find(3);

	it->second = "haha";
	//cit->second = "haha";
}

void test_stdmap()
{
	std::map<int, string> m1;
	for (int i = 0; i < 26; i++)
	{
		m1[i] = 'a' + i;
	}

	for (auto& e : m1)
	{
		cout << e.second << endl;
	}
	std::map<int, string> m;
	for (int i = 0; i < 20; i++)
	{
		m[i] = "haha";
	}
	const std::map<int, string> m2 = m;
	std::map<int, string>::iterator it = m.begin();
	for (auto& e : m)
	{
		e.second = 1;
	}
	std::map<int, string>::const_iterator cit = m2.begin();
	//cit->second = string("hehe");
}