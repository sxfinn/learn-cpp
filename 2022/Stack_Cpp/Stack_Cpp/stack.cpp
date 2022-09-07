
#include"stack.h"

void StackInit(struct Stack* s)
{
	s->p = NULL;
	s->sz = 0;
	s->capacity = 0;
}

void StackPush(struct Stack* s, DataType x)
{
	assert(s);
	if (s->sz == s->capacity)
	{
		int newcapacity = s->capacity == 0 ? 2 : 2 * s->capacity;
		DataType* tmp = (DataType*)realloc(s->p, sizeof(DataType) * newcapacity);
		if (tmp)
		{
			s->p = tmp;
			s->capacity = newcapacity;
		}
		else
		{
			printf("realloc fail\n");
			exit(-1);
		}
	}
	s->p[(s->sz)++] = x;
}

void StackPop(struct Stack* s)
{
	assert(s);
	assert(s->p);
	if (s->sz > 0)
	{
		--s->sz;
	}
}

DataType StackTop(struct Stack* s)
{
	assert(s);
	assert(s->sz > 0);
	return s->p[s->sz - 1];
}

int StackSize(struct Stack* s)
{
	assert(s);
	return s->sz;
}

void StackDestory(struct Stack* s)
{
	assert(s);
	s->capacity = 0;
	s->sz = 0;
	free(s->p);
	s->p = NULL;
}

bool StackEmpty(struct Stack* s)
{
	assert(s);
	return s->sz == 0;
}

