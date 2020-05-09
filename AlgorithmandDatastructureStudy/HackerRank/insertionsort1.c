#include <stdio.h>
#include <stdlib.h>
void printArr(int arr[],int len)
{
	int i;
	for(i=0;i<len;i++)
		printf("%d ",arr[i]);
	printf("\n");
			
}
unsigned long long shiftArr[10];
unsigned long long insertionSort(unsigned long long arr[],unsigned long long len)
{
	unsigned long long i,j,temp;
	unsigned long long shift=0;
	for(i=1;i<len;i++)
	{
		temp = arr[i];

		for(j=i-1;j>=0;j--)
		{
			if(arr[j] > temp)
			{
				arr[j+1] = arr[j];
				arr[j]= temp;
				shift++;
			}
			else
			{
				break;

			}


		}
	}
	return shift;	
}
int main()
{
	unsigned long long arr[100000];
	unsigned long long len,i,j;
	int temp;
	int nT,t;
	scanf("%d",&nT);
	t=nT;
	for(j=0;j<nT;j++)
	{
		scanf("%llu",&len);
		for(i=0;i<len;i++)
		{
			scanf("%llu",&arr[i]);
		}
	
		shiftArr[j]=insertionSort(arr,len);
		

	}
	for(i=0;i<t;i++)
		printf("%llu\n",shiftArr[i]);
}
