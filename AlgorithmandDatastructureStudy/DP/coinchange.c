#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <strings.h>

int min(int a,int b)
{
	if (a>b)
		return b;
	else
		return a;
}
int getMinCoinsUtil(int a[],int n,int s, int sumarr[])
{
	int i;
	int temp=INT_MAX;
	if(s<=0)
		return 0;
	if(sumarr[s-1] !=0)
	{
		return sumarr[s-1] ;
	}
	for(i=0;i<n;i++)
	{
			temp= min(temp,getMinCoinsUtil(a,n,s-a[i],sumarr));
		
	}
	sumarr[s-1]=temp+1;
	return sumarr[s-1];

}

int getMinCoins(int a[],int n,int s)
{
	int leastCoins;
	int* sumarr = (int*)calloc(sizeof(int),s);
	bzero(sumarr,sizeof(int)*s);
	leastCoins= getMinCoinsUtil(a,n,s,sumarr);
	return leastCoins;

}

int main()
{
	int n,i,s;
	int a[100]={0};
	printf("Enter the number of coins\n");
	scanf("%d",&n);
	printf("Enter coins\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the sum for which change is required\n");
	scanf("%d",&s);
	printf("Minimum number of coins required for this change is:%d\n",
			getMinCoins(a,n,s));
	return 0;



}
