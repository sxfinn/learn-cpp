//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//#include<errno.h>
//


//每个文件打开都会自动产生相应的文件缓冲区用来临时存放需要传递的数据，从而达到提高传输效率的目的。
//int main()
//{
//	char* p= "heelo\n";
//	FILE* pf = fopen("test.txt", "w");
//	if (!pf)
//	{
//		perror("pf");
//		return 0;
//	}
//	printf("计时10s");
//	fputs(p, pf);
//	Sleep(10000);
//	fclose(pf);
//	return 0;
//}


//int main()
//{
//	int num = 0;
//	int a[2] = { 0 };
//	FILE* pf = fopen("test.txt", "rb");
//	int ret = fread(&a, 4, 2, pf);
//	num = feof(pf);
//	printf("%d", a);
//	ret = fread(&a, 4, 2, pf);
//	
//	num = feof(pf);
//	printf("%d", a);
//	ret = fread(&a, 4, 2, pf);
//	num = feof(pf);
//	printf("%d", a);
//	ret = fread(&a, 4, 1, pf);
//	num = feof(pf);
//	printf("%d", a);
//	ret = fread(&a, 4, 1, pf);
//	num = feof(pf);
//	printf("%d", a);
//	return 0;
//}
//int main()
//{
//	int a = 1;
//	int* p = &a;
//	FILE* pf = fopen("test.txt", "wb");
//	fwrite(p, 4, 1, pf);
//	a++;
//	fwrite(p, 4, 1, pf);
//	a++;
//	fwrite(p, 4, 1, pf);
//	fclose(pf);
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("cpp.txt", "r");
//	perror("");
//	char* p = "";
//	printf("%p\n", p);
//	//printf("%p", NULL);	
//	p = NULL;
//	return 0;
//}
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	for (int ch = 'a'; ch <= 'z'; ch++)
//	{
//		fputc(ch, pf);
//	}
//	fseek(pf, 2, SEEK_SET);
//	fputc('w', pf);
//	fclose(pf);
//	/*pf = NULL;
//	pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	fseek(pf, -1, SEEK_END);
//	fputc('w', pf);
//	fclose(pf);*/
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	fseek(pf, 1, SEEK_SET);
//	char ch = fgetc(pf);
//	printf("%c", ch);
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	return 0;
//}