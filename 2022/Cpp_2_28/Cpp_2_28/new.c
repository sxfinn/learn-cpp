#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int pre = 0;
	int cur = 1;
	int next = 0;
	int n = 0;
	int min = 0;
	scanf("%d", &n);
	while (cur < n)
	{
		next = pre + cur;
		pre = cur;
		cur = next;
	}
	min = cur - n > n - pre ? n - pre : cur - n;
	printf("%d", min);
	return 0;
}