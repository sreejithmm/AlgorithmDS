#include <stdio.h>

void fact(int n)
{
	unsigned long long fact=1;
	while(n)
	{
		fact*=n;
		n--;
	}
	printf("%llu\n",fact);
	return;
}
int main()
{

	int i,j,k,l,m,n;
	int arr[100];
	scanf("%d",&i);
	for(j=0;j<i;j++)
	{
	   scanf("%d",&arr[j]);

	}
	for(j=0;j<i;j++)
	{
          fact(arr[j]);
	}
	return 0;

}
