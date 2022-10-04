#include"string.h"

//void test1()
//{
//	sx::string s1;
//	s1 += "shabi";
//	const sx::string s2("hello");
//	//s1 = s2;
//	//cout << (s1 <= s2) << endl;
//	cout << s2 + 'c';
//	
//}
int main()
{
	test1();
	return 0;
}




//int main()
//{
//	//test8();
//	//test7();
//	//test6();
//	//test5();
//	//test4();
//	//test3();
//	//test2();
//	//test1();
//	return 0;
//}
//void test1()
//{
//	sx::string s1;
//	sx::string s2("songxin");
//	s1.print();
//	s2.print();
//	sx::string s3(s2);
//	s3.print();
//}
//
//void test2()
//{
//	sx::string s1("songxin");
//	s1.reserve(10);
//}
//
//void test3()
//{
//	std::string s1("hello");
//	s1.reserve(200);
//	s1.resize(4, 'x');
//	cout << s1;
//}
//void test4()
//{
//	sx::string s1("songxin");
//	s1.reserve(20);
//	s1.resize(3, 'x');
//}
//
//void test5()
//{
//	sx::string s1("songxin");
//	sx::string s2;
//	s2 = s1;
//	cout << s1[2];
//}
//void test6()
//{
//	sx::string s1("songxin");
//	s1.insert(0, 'c');
//	s1.insert(0, "hello world");
//	for (auto e : s1)
//	{
//		cout << e;
//	}
//	s1.push_back('h');
//	s1.append("head ");
//	
//	cout << endl;
//	s1.print();
//	size_t pos = s1.find('i', 0);
//	if (pos == string::npos)
//		cout << "not fund\n" << endl;
//	cout << pos << endl;
//	pos = s1.find("hello",6);
//	if (pos == string::npos)
//		cout << "not fund\n" << endl;
//	cout << pos << endl;;
//}
// void test7()
//{
//	sx::string s1;
//	sx::string s2("test");
//	s1 += "hello";
//	s1 += ' ';
//	s1 += "world";
//	cout << (s1 += "hehe") << endl;
//	(s1 += 'c');
//	(s1 + 'c').print();
//	//(s1 + "haha").print();
//	//cout << (s1 + "haha") << endl;
//	//s1.print();
//	//cout << s1.empty() << endl;
//	//s1.clear();
//	//cout << s1.empty() << endl;
//	//s1.cc().print();
//	//const sx::string s2("haa");
//	//s2.print();
//}

//void test(sx::string& s)
//{
//	cout << "void test(std::string& s)" << endl;
//}
//const size_t sx::string::npos = -1;
//void test8()
//{
//	sx::string s1("hello");
//	s1.print();
//	const sx::string s2("haha");
//	s2.print();
//	(s1 + "hell").print();
//	cout << s1 + "hello";
//	//sx::string::const_iterator it = (s1 + 'c').cbegin();
//	//test((s1 + "world"));
//	//cout << ((s1 + "world").push_back('a'));
//	//cout << endl << &s1 << endl;
//	//std::string s2("hello");
//	//s2.push_back('a');
//	//cout << s2 + "hehe";
//	//cout << ((s2 + "world").push_back('a'));
//}