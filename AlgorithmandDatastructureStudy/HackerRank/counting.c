#include <stdio.h>

int main()
{
	int count [100]={0};

	int num,i,n;
	char str[100];

	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		scanf("%d",&n);
		scanf("%s",str);
		count[n] = count[n]+1;
	}
	for(i=1;i<100;i++)
	{
		count[i]+=count[i-1];
	}
	for(i=0;i<100;i++)
	{
#if 0
		while(count[i])
		{
			printf("%d ",i);
			--count[i];
		}	
#endif
		printf("%d ",count[i]);
	}

	printf("\n");
	return;

}
