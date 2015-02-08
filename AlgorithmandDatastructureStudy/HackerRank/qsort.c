#include <stdio.h>

	int num;
	int swapcnt=0;
void swap(int *a, int *b)
{
	int t= *a;
	*a = *b;
	*b =t;
	swapcnt++;
	return ;
}
void printArr(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return;

}
int partition(int arr[],int s, int e)
{
	int j;
	int p = arr[e];
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
void quicksort(int arr[],int start,int end)
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
int insetcnt=0;
void insertionSort(int arr[],int len)
{
	int i,j,temp;
	for(i=1;i<len;i++)
	{
		temp = arr[i];

		for(j=i-1;j>=0;j--)
		{
			if(arr[j] > temp)
			{
				arr[j+1] = arr[j];
				arr[j]= temp;
				insetcnt++;
			}
			else
			{
			//	printArr(arr,len);
				break;

			}


		}
	}
}

int main()
{
	int i,j,p;
	
	int arr[2000];
	int dummy[2000];

	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		scanf("%d",&arr[i]);
		dummy[i]=arr[i];
	}

	quicksort(arr,0,num-1);
	insertionSort(dummy,num);
	printf("%d\n",insetcnt-swapcnt);
}
