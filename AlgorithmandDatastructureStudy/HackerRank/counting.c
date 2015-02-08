#include <stdio.h>
#include <string.h>
int main()
{
	int inarr[1000000];
	int count [100]={0};
	int newcount [100]={0};

	int num,i,n;
	char str[1000000][100]={'\0'};
	int outarr[1000000]={0};
	char outstr[1000000][100]={'\0'};

	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		scanf("%d",&inarr[i]);

		scanf("%s",str[i]);
		if(i <num/2)
			strcpy(str[i],"-");
		count[inarr[i]] = count[inarr[i]]+1;
	}
	for(i=1;i<100;i++)
	{
		newcount[i]=newcount[i-1]+count[i-1];
	}

#if 0
//	printf("Oriignal strings \n");
//	for(i=0;i<num;i++)
	{
//		printf("%s ",str[i]);
	}
	printf("\n");
	for(i=0;i<100;i++)
	{
//		while(count[i])
		{
//			printf("%d ",i);
//			--count[i];
		}	
		printf("%d ",count[i]);
	}
#endif
        
	for(i=0;i<num;i++)
	{
		int t= newcount[inarr[i] ];
		outarr[t] = inarr[i];
		strcpy(outstr[t],str[i]);
		++newcount[inarr[i]];

	}

	for(i=0;i<num;i++)
	{
	//	printf("%d ",outarr[i]);
		printf("%s ",outstr[i]);
	}

	printf("\n");
	return;

}
