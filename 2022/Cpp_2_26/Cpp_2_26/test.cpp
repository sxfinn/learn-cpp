#include<iostream>
using namespace std;
#define SZ 2
//class S
//{
//public:
//	S(int c = 0, int d = 0)
//		:
//		a(1),
//		b(2)
//	{
//		cout << n++ << endl;
//	}
//	int a;
//	int b;
//	static int n;
//};
//int S::n = 1;
//int main()
//{
//	/*S* p = (S*)malloc(sizeof(S));
//	new(p)S;*/
//	S* p = new S[1]{ 1 };
//	return 0;
//}
class S
{
public:
	S()
		:
		_a(1),
		_b(2)
	{

	}
	int _a;
	int _b;
};
int main()
{
	S* p = new S[2];
	delete[]p;
	//int* tmp;
	//tmp = new int[10];
	/*int* tmp1 = (int*)malloc(sizeof(int) * 1);
	memset(tmp1, 1, sizeof(int) * 1);
	free(tmp1);*/
	//delete[]tmp;
	//tmp = NULL;
	return 0;
}

//namespace sx
//{
//	template<typename T>
//	class vecto
//	{
//	public:
//		vecto()
//			:
//			_data(nullptr),
//			_size(0),
//			_capacity(0)
//		{}
//		void pushback(T a);
//		T& operator[](int pos)
//		{
//			return _data[pos];
//		}
//	private:
//		T* _data;
//		size_t _size;
//		size_t _capacity;
//	};
//	template<typename T>
//	void vecto<T>::pushback(T a)
//	{
//		if (_capacity == _size)
//		{
//			int newcapacity = _capacity == 0 ? SZ : 2 * _capacity;
//			T* tmp = new T[newcapacity];
//			if (_data)
//			{
//				memcpy(tmp, _data, sizeof(T) * newcapacity);
//			}
//			_data = tmp;
//		}
//		_data[_size] = a;
//		_size++;
//	}
//}
//int main()
//{
//	sx::vecto<int> v1;
//	v1.pushback(1);
//	v1.pushback(2);
//	v1.pushback(3);
//	for (int i = 0; i < 3; i++)
//	{
//		v1[i] *= 2;
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		cout << v1[i] << " ";
//	}
//	return 0;
//}
//class S
//{
//public:
//	S()
//		:
//		ret(0)
//	{}
//	int& getdata()
//	{
//		return ret;
//	}
//	void print()
//	{
//		cout << ret << endl;
//	}
//private:
//	int ret;
//};
//int main()
//{
//	S s;
//	int& t = s.getdata();
//	t = 1;
//	s.print();
//	t = 2;
//	s.print();
//	return 0;
//}
//namespace sx
//{
//	template<typename T>
//	class vector
//	{
//	public:
//		vector()
//			:
//			_data(nullptr),
//			_size(0),
//			_capacity(0)
//		{}
//		void pushback(T a)
//		{
//			size_t newcapacity = 0;
//			if (_size == _capacity)
//			{
//				newcapacity = _capacity == 0 ? SZ : 2 * _capacity;
//				T* tmp = new T[newcapacity];
//				if (_data)
//				{
//					memcpy(tmp, _data, sizeof(T) * _capacity);
//				}
//				_data = tmp;
//			}
//			_data[_size] = a;
//			_size++;
//		}
//		T& operator[](size_t pos)
//		{
//			return _data[pos];
//		}
//	private:
//		T* _data;
//		size_t _size;
//		size_t _capacity;
//	};
//}
//int main()
//{
//	sx::vector<double>v1;
//	v1.pushback(1.0);
//	v1.pushback(2.2);
//	v1.pushback(3.3);
//	v1.pushback(4.4);
//	for (int i = 0; i < 4; i++)
//	{
//		v1[i] *= 2;
//	}
//	for (int i = 0; i < 4; i++)
//	{
//		cout << v1[i] << " ";
//	}
//	//cout << v1[0];
//	return 0;
//}
//int main()
//{
//	double a = 1.1;
//	cout << a;
//	return 0;
//}

//void swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//int main()
//{
//	int a = 1;
//	int b = 2;
//	int& tmp = (int&)a;
//	int& t = b;
//	int& t1 = t;
//	swap((int&)a, (int&)b);
//	cout << (int)a << (int)b << endl;
//	return 0;
//}
//模板参数
//template<class T,class Y>
////template<class D>
//Y add(T a, Y b)
//{
//	return a + b;
//}
//int main()
//{
//	double ret = add(2, 3.1);
//	cout << ret;
//	return 0;
//}
//利用模板参数和编译器区推导类型，只给出大体逻辑，不必管参数类型。
//#include<iostream>;
//
//using namespace std;
//
//int main()
//{
//	//int* ret = (int*)calloc(10, 4);
//	//cout << sizeof(int*) << endl;
//	return 0;
//}
//int s = 0;
//class S
//{
//	/*S(int b, int a)
//		:
//		_a(a),
//		_b(b)
//
//	{
//
//	}*/
//public:
//	int _b;
//	static int _a;
//};
//
//int S::_a = 1;