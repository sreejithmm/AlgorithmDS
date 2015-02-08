#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef  long long LL;
void swap(LL *a, LL *b)
{
	int t= *a;
	*a = *b;
	*b =t;
	return ;
}
void printArr(LL a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%lld ",a[i]);
	}
	printf("\n");
	return;

}
int partition(LL arr[],int s, int e)
{
	int j;
	LL p = arr[e];
	int i=s;

	for( j=s;j<e;j++)
	{
		if(arr[j] < p)
		{
			swap(&arr[j],&arr[i]);
			i++;
		}
	}
	swap(&arr[e],&arr[i]);
	return i;

}
void quicksort(LL arr[],int start,int end)
{
	int p ;
	int i=0;
	int j;

	if(start >= 0 && end >= 0 && (start < end))
      	{ 
		p = partition(arr,start,end);
//		printArr(arr,num);
		quicksort(arr,start,p-1);
		quicksort(arr,p+1,end);

	}
}

int findMinPairs(LL arr[],int len, LL pairs[])
{
	int i=0,p=0;
	LL min=arr[1]-arr[0]+1;
	LL temp=arr[1]-arr[0];

	for(i=1;i<len;i++)
	{
		temp = arr[i]-arr[i-1];
		if(temp < min)
		{
			p = 0;
			pairs[p] = arr[i-1];
			pairs[++p] = arr[i];
			min = temp;
			
		}
		else if(temp == min)
		{
			pairs[++p] = arr[i-1];
			pairs[++p] = arr[i];
		}
		

	}
	return p;

}

int main()
{
	int i,j,temp,num;
	LL *arr;
	LL* pairs;

	scanf("%d",&num);

	arr=(LL*)malloc(sizeof(LL) * num);
	pairs=(LL*)malloc(sizeof(LL) * num);

	for(i=0;i<num;i++)
	{
		scanf("%lld",&arr[i]);
	}

	quicksort(arr,0,num-1);
//	printArr(arr,num);
	temp = findMinPairs(arr,num,pairs);
	
	for(i=0;i<=temp;i++)
	{
		printf("%lld ",pairs[i]);
	}
	printf("\n");
		
}
