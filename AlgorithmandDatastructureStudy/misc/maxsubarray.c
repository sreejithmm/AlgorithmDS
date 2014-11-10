#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main()
{


    int n;
    int i,j,max=1;
	int *arr;
	int *wtdarr;
	
	scanf("%d",&n);
	while(n)	
	{
		scanf("%d",&size);
		a = (int*)malloc(sizeof(int)*size);
		wtdarr=(int*)malloc(sizeof(int)*size);
		for(i=0;i<size;i++)
		{
			scanf("%d",&arr[i]);
		}
		for(i=0;i<size;i++)
		{
			scanf("%d",&wtdarr[i]);
		}
		
		max = wtdarr[size-1];
		for(i=size-1;i>=0;i--)
		{
			
			/*implement seg tree here */
			if(wtdarr[i] > max)
			{
				max=wtdarr[i];
			}
		}
		n--;
	}
		printf("max=%d\n",max);

    return 0;
}
