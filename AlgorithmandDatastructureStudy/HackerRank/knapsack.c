#include <stdio.h>

int knapsack(int arr[],int cap,int num)
{
	int** matr=(int**) malloc(sizeof(int*) * (num+1));

	for(i=0;i<num;i++)
	{
		matr[i] = (int*)malloc(sizeof(int)*(cap+1));
	}
	for(i=0;i<=num;i++)
	{
		for(j=0;j<=capa;j++)
		{
			if(j==0 || k==0)
			{
				matr[i][j] = 0;
			}
			if(arr[i] <= capa)
			{	
				matr[i][j] = 
			}

		}
	}
	
}

int main()
{
	int nT, int cap, int num,i,j,k;
	int arr[2000];
	int result[10];

	scanf("%d",&nT);
	for(i=0;i<nT;i++)
	{
		scanf("%d",&num);
		scanf("%d",&cap);
		for(j=0;j<num;j++)
		{
			scanf("%d",&arr[i]);
		}

		result[i]=knapsack(arr,cap,num);

	}
}

