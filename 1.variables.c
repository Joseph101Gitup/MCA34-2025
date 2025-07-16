#include<stdio.h>
int a=5;//global
void display()
{
	int b=5;//local
	static int c=5;//static
	register int d=5;//register
	printf("global=%d local=%d static=%d register=%d \n",a++,b++,c++,d++);
}
int main()
{
	display();
	display();
	display();
	return 0;
}
