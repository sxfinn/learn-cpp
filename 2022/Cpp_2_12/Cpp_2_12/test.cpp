#include"date.h"

int main()
{
	Date a(2001, 7, 28);
	/*a.print();
	a += 10;
	a.print();
	Date b;
	b = (a + 7);
	b.print();*/
	/*a.print();
	a -= -30;
	a.print();
	Date b = a - (-1);
	a.print();
	b.print();*/
	Date b = a++;
	b = ++a;
	b.print();
	a.print();
	return 0;
}