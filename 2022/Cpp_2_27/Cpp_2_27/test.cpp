#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
namespace sx
{
	class string
	{
	public:
		string(const char* p = "")
			:
			_str(new char[strlen(p) + 1])
		{
			strcpy(_str, p);
		}
		string(string& s)
			:
			_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}
		~string()
		{
			free(_str);
			_str = NULL;
		}
		size_t size()
		{
			return strlen(_str);
		}
		char &operator[](size_t pos)
		{
			return _str[pos];
		}
		void print()
		{
			cout << _str << endl;
		}
		string& operator=(string& s)
		{
			free(_str);
			_str = new char[s.size() + 1];
			strcpy(_str, s._str);
			return *this;
		}
	private:
		char* _str;
	};
}
int main()
{
	sx::string s1("hello world");
	sx::string s2(s1);
	sx::string s3;
	s1.print();
	s2.print();
	s3 = s1;
	s3.print();
	cout << s1.size() << endl;
	cout << s1[3];
	return 0;
}
//class S
//{
//public:
//	S()
//	{}
//	S(S& a)
//		
//	{
//
//	}
//	int* _str;
//	int a;
//	
//};
//int main()
//{
//	S s;
//	S s1(s);
//	return 0;
//}

//Ĭ�Ϲ��캯�� ���б��ʼ��������û��Ĭ�Ϲ��캯���ĳ�Ա������˵��ֻ��ʹ���б��ʼ�������졣
//��������Ҳ���б��ʼ�������Կ���һЩֻ�ܸ�ֵһ�ε�����
//class S
//{
//public:
//	S(int a = 10, int b = 0)
//		:
//		_a(a),
//		_b(b)
//	{}
//	S(S& a)
//		:
//		_b(a._b),
//		_a(a._a)
//		
//	{
//		/*_a = a._a;
//		_b = a._b;*/
//	}
//	void print()
//	{
//		cout << _a << _b << endl;
//	}
//private:
//	const int _a;
//	int _b;
//};
//
//int main()
//{
//	S s1;
//	S s2(s1);
//	//S s3(10, 10);
//	S s4 = s1;
//	//s3 = s1;
//	s1.print();
//	s2.print();
//	return 0;
//}

//class B
//{
//public:
//	B(int t = 1)
//		:
//		b(t)
//	{}
//	int b;
//};
//class S
//{
//public:
//	S(int a = 1)
//		:
//		_p(),
//		_b(),
//		_a()
//	{
//		/*_a = 3;
//		_b = 4;*/
//		//_a = 10;
//		cout << "func";
//	}
//	
//	B _b;
//	int _a;
//	int* _p;
//	
//};
//
//int main()
//{
//	S s;
//	//cout << s._a << s._b;
//	/*int* ret = new int(2);
//	*ret = 1;
//	cout << *ret << endl;*/
//	return 0;
//}

//template<class T,class K>
//class so
//{
//public:
//	so()
//		:
//		a(0),
//		b(1)
//	{}
//	void print();
//	T a;
//	int b;
//};
//template<class T, class S>
//void so<T, S>::print()
//{
//	cout << a << b << endl;
//}
//int main()
//{
//	so<double, int>s;
//	s.print();
//	return 0;
//}

//������������ģ������Ͷ����ģ������б�Ҫһ�£�����
//������ģ������ĺ���������ģ������б�����ģ������б�һ�£���ˣ�
//�����ⶨ��ĳ�Աģ�庯���Ĳ����б�Ҫ�������ڵ����ģ������б�һ�£�����
//template <class T>
//
//int add(T a, T b);
//
////template <class T, class K>
////
////int add(T a, K b)
////{
////	return a + b;
////}
//
//int main()
//{
//	double a = 1.2;
//	double b = 2.4;
//	add(a,b);
//	return 0;
//}
//
//template <class T>
//
//int add(T a,T b)
//{
//	return a;
//}



//template<class T,class K>
//class S
//{
//public:
//	S()
//		:
//		_a(1),
//		_b(1.2)
//	{}
//	template<class T,class K>
//	int add(T a);
//	int _a;
//	double _b;
//};
//template<class T,class K>
//int S::add(T a)
//{
//	return a;
//}
//int main()
//{
//	S s;
//	//s.add(1.2, 2.4);
//	return 0;
//}
//template <class T,class K>
//T add(T a, K b)
//{
//	return a + b;
//}
//int main()
//{
//	int ret = add<double,float>(1, 1);
//	return 0;
//}
//int main()
//{
//	int& b = 2;
//	int a = 0;
//	short* p = &((short)a);
//	return 0;
//}
//template<class T, class K>
//void mswap(int* a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//int main()
//{
//	int c = 1;
//	//float d = 9.0;
//	int d = 9;
//	mswap(&((int)d), c);//���õ�����ת���ǽ����ַȡ����Ȼ�����������õ����ͽ�����
//	return 0;
//}

//class S
//{
//	int a;
//};
//class S
//{
//	double b;
//};
//int main()
//{
//	S s;
//	return 0;
//}
// ��ģ�����Ա�����������ⲿʱ������Ҫд��ģ������б������ڳ�Աģ�庯��ʵ����ʱ������ʽ��ʵ������ָ��
// ��ģ�������Ҫʵ���������͡�
// ��ʾ��ʵ������һ������һ���Ѿ�ʵ��������࣬�������֮��������е����ˡ�
// ģ�����ʵ����Ҳ����ʾ�ģ��뺯��ģ���б���ƥ��
// ʵ���������ĸ�ʽ ����+ <ʵ������ģ������б�>
// ���Ժ���ģ��Ҳ����д��������
//namespace sx
//{
//	template<class T,class K>
//	class vector
//	{
//	public:
//		vector()
//			:
//			_a(nullptr),
//			sz(0)
//		{}
//		void push(T a);
//		
//		void print();
//	private:
//		T* _a;
//		int sz;
//		K* _k;
//	};
//	template<class T,class K,class S>
//	void vector<T,K>::print()
//	{
//		cout << *_a;
//	}
//	template<class T1,class K>
//	void vector<T1,K>::push(T1 a)
//	{
//		T1* tmp = new T1;
//		_a = tmp;
//		_a[sz] = a;
//		sz++;
//	}
//}
//
//int main()
//{
//	int a = 10;
//
//	sx::vector<int,double> v1;
//	sx::vector<double,int>v2;
//	//v1.push(2.0);
//	//v1.print();
//	v2.push(a);
//	v2.print();
//	
//	
//	return 0;
//}