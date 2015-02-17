
#include <stdio.h>
#include <stdlib.h>

int add(int a,int b)
{
	int carr;

	while(b)
	{
		carr=a&b;
		a=a^b;
		b=carr<<1;
	}
	return a;
}

int main()
{
	int a,b;
	int sum;
	printf("Enter 2 numbers\n");
	scanf("%d",&a);
	scanf("%d",&b);

	sum = add(a,b);
	printf("\nsum:%d\n",sum);
}
