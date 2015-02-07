#include <stdio.h>

int max(int a, int b)
{
	if(a>b)
		return a;
	else 
		return b;
}
int knapsack(int matr[][6],int weight[], int value[], int capa,int num)
{

	if(capa <= 0)
		return 0;

	if(matr[num][capa] != 0)
		return matr[num][capa];

	matr[num][capa] =  max(value[num]+knapsack(matr,weight,value,capa-weight[num],num-1),knapsack(matr,weight,value,capa,num-1));
	return matr[num][capa];



}
int main()
{

	int weight[5];
	int value[5];

	int matr[6][6]={0};
	int capa;

	int i,j,k;

	printf("Enter weights of objects\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&weight[i]);
	}
	printf("Enter benefits of objects\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&value[i]);
	}
	printf("What is the capacity of knapsack?\n");
	scanf("%d\n",&capa);

	printf("Maximum values tht can be carried in the knapsack:%d\n",knapsack(matr,weight,value,capa,5));


}
