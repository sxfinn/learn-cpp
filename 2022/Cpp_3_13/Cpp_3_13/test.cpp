#include"test.h"
//顺序表模拟
typedef int DataType;
typedef struct SeqList
{
	DataType* head;
	int size;
	int capacity;
}SeqList;

void SeqListInit(SeqList* slt)
{
	assert(slt);
	slt->capacity = 0;
	slt->size = 0;
	slt->head = NULL;
}

void SeqListPrint(SeqList* slt)
{
	assert(slt);
	for (int i = 0; i < slt->size; i++)
	{
		printf("%d ", slt->head[i]);
	}
	printf("\n");
}

void SeqListCheckCapacity(SeqList* slt)
{
	assert(slt);
	int newcapacity = 0;
	if ((slt)->size == (slt)->capacity)
	{
		newcapacity = (slt)->capacity == 0 ? 4 : 2 * (slt)->capacity;
		(slt)->capacity = newcapacity;
		DataType* tmp = (DataType*)realloc((slt)->head, sizeof(DataType) * newcapacity);
		if (tmp)
			(slt)->head = tmp;
	}
}

void SeqListInsert(SeqList* slt, int pos, DataType x)
{
	assert(pos >= 0 && pos <= slt->size && slt);
	SeqListCheckCapacity(slt);
	for (int i = slt->size - 1; i >= pos; --i)
	{
		slt->head[i + 1] = slt->head[i];
	}
	slt->head[pos] = x;
	slt->size++;
}

void SeqListPushBack(SeqList* slt, DataType x)
{
	assert(slt);
	SeqListInsert(slt, slt->size, x);
}

void PopBack(SeqList* slt)
{
	assert(slt);
	--slt->size;
}

void SeqListErase(SeqList* slt, int pos)
{
	assert(slt && pos < slt->size);
	if (slt->size > 0)
	{
		for (int i = pos; i < slt->size - 1; ++i)
		{
			slt->head[i] = slt->head[i + 1];
		}
		--slt->size;
	}
}

void SeqListPushFront(SeqList* slt, DataType x)
{
	assert(slt);
	SeqListInsert(slt, 0, x);
}

void SeqListPopFront(SeqList* slt)
{
	assert(slt);
	SeqListErase(slt, 0);
}

void SeqListPopBack(SeqList* slt)
{
	assert(slt);
	SeqListErase(slt, slt->size - 1);
}

void SeqListDestory(SeqList* slt)
{
	assert(slt);
	free(slt->head);
	slt->capacity = slt->size = 0;
}

void SeqListModify(SeqList* slt, int pos, DataType x)
{
	assert(slt);
	if(pos < slt->size)
		slt->head[pos] = x;
}
void test1()
{
	SeqList slt;
	SeqListInit(&slt);
	SeqListPushBack(&slt, 1);
	SeqListPushBack(&slt, 2);
	SeqListPushBack(&slt, 3);
	SeqListPushBack(&slt, 5);
	SeqListPushBack(&slt, 6);
	SeqListInsert(&slt, 3, 4);
	SeqListPopFront(&slt);
	SeqListPushFront(&slt, 0);
	//SeqListInsert(&slt, 0, 3);
	//SeqListInsert(&slt, 0, 2);
	//SeqListInsert(&slt, 0, 1);
	//SeqListPushBack(&slt, 4);
	//SeqListPopFront(&slt);
	//SeqListPopBack(&slt);
	SeqListPrint(&slt);
	SeqListModify(&slt, 2, 10);
	SeqListPrint(&slt);
	SeqListDestory(&slt);
}
int main()
{
	test1();
	return 0;
}

//#include"test.h"
//
//int main()
//{
//	cout << func(1, 2) << endl;
//	cout << add(3.0, 4.0) << endl;
//	return 0;
//}
//class S
//{
//public:
//	S(int a = 9, int b = 10)
//		:
//		_a(a),
//		_b(b)
//	{}
//	int _a;
//	int _b;
//};
//class Test
//{
//public:
//	Test()
//		:
//		_i(1),
//		_s(),
//		_s1(_s)
//	{}
//	int _i;
//	S _s;
//	S _s1;
//};
//void test1()
//{
//	Test t1;
//	cout << t1._s._a << t1._s._b << endl;
//	cout << t1._s1._a << t1._s1._b << endl;
//}
//int main()
//{
//
//	//test1();
//}
//类的特化
//template<class T, class Y>
//class S
//{
//public:
//	S()
//	{
//
//	}
//	T t;
//	Y y;
//};
//template<>
//class S<int, int>
//{
//public:
//	S()
//	{
//
//	}
//	int t;
//	int y;
//};
//int main()
//{
//	S<double, int> s1;
//	S<int, int>s2;
//	return 0;
//}