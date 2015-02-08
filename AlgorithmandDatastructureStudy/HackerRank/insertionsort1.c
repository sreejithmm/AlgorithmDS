#include <stdio.h>

void printArr(int arr[],int len)
{
	int i;
	for(i=0;i<len;i++)
		printf("%d ",arr[i]);
	printf("\n");
			
}
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
			}
			else
			{
				printArr(arr,len);
				break;

			}


		}
	}
}
int main()
{
	int arr[1000];
	int len,i;
	int temp;

	scanf("%d",&len);
	for(i=0;i<len;i++)
	{
		scanf("%d",&arr[i]);
	}
	insertionSort(arr,len);
#if 0
	temp = arr[len-1];

	for(i=len-1;i>0;i--)
	{
		if(arr[i-1] < temp)
		{
			arr[i] = temp;
			printArr(arr,len);
			break;
		}
		else
		{
			arr[i] = arr[i-1];
			printArr(arr,len);
		}
	}
	if(i==0 && arr[i] > temp) {
		arr[i]=temp;
		printArr(arr,len);
	}
#endif
}
