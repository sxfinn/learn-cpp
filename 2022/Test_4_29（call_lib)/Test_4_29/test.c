
#include"..\..\Stack_C\Stack_C\stack.h"
bool isValid(char* s)
{
	struct Stack t;
	StackInit(&t);
	while (*s)
	{
		if (*s == '(' || *s == '[' || *s == '{')
		{
			StackPush(&t, *s);
		}
		else
		{
			if (StackEmpty(&t))
				return false;
			char tmp = StackTop(&t);
			if (*s == '}' && tmp != '{' || *s == ')' && tmp != '(' || *s == ']' && tmp != '[')
				return false;
			else
				StackPop(&t);
		}
		++s;
	}
	return StackEmpty(&t);
}

int main()
{
	char arr[] = "{{()}";
	bool ret = isValid(arr);
	printf("%d \n", ret);
	return 0;
}