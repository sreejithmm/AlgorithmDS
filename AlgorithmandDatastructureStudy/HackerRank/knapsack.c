#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int knapsack(int arr[],int capa,int num)
{
	int i,j;
	int** matr=(int**) malloc(sizeof(int*) * (num+1));

	for(i=0;i<=num;i++)
	{
		matr[i] = (int*)malloc(sizeof(int)*(capa+1));
	}
	for(i=0;i<=num;i++)
	{
		for(j=0;j<=capa;j++)
		{
			if(j==0 || i==0)
			{
				matr[i][j] = 0;
			}
			else if(arr[i-1] <= capa)
			{	
				matr[i][j] = max(arr[i-1] + matr[i][capa-arr[i-1]],matr[i-1][capa]);
			}
			else if(arr[i-1] > capa)
			{
				matr[i][j] = matr[i-1][capa];
			}

		}
	}
	return matr[num][capa];
}

int main()
{
	int nT,  cap,  num,i,j,k;
	int arr[2000];
	int result[10];

	scanf("%d",&nT);
	for(i=0;i<nT;i++)
	{
		scanf("%d",&num);
		scanf("%d",&cap);
		for(j=0;j<num;j++)
		{
			scanf("%d",&arr[j]);
		}

		result[i]=knapsack(arr,cap,num);

	}
	for(i=0;i<nT;i++)
	{
		printf("%d ",result[i]);
	}
	printf("\n");
}

