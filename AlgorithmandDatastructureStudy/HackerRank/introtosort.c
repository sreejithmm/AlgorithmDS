#include <stdio.h>

int main()
{
	int num;
	int n,i;
	int arr[1002]={0};

	scanf("%d",&num);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		if(arr[i] == num)
			break;
	}
	printf("%d\n",i);
	
}
