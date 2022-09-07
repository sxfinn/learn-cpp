#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int DataType;

struct Stack
{
	DataType* p;
	int capacity;
	int sz;
};

//#ifdef __cplusplus
//extern "C"
//{
//#endif
void StackInit(struct Stack* s);
void StackPush(struct Stack* s, DataType x);
void StackPop(struct Stack* s);
DataType StackTop(struct Stack* s);
int StackSize(struct Stack* s);
void StackDestory(struct Stack* s);
bool StackEmpty(struct Stack* s);
//#ifdef __cplusplus
//}
//#endif