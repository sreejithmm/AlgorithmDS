#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int* inarr;
	int count [100]={0};
	int newcount [100]={0};

	int num,i,n;
	char**  str;
	int* outarr;
	char** outstr;

	scanf("%d",&num);
	
	inarr = (int*)malloc(num * sizeof(int));
	outarr =(int*)malloc(num*sizeof(int));
	outstr = (char**)malloc(num * sizeof(char*));
	str = (char**)malloc(num * sizeof(char*));

	for(i=0;i<num;i++)
	{
		outstr[i]=(char*) malloc(sizeof(char)*10);
		str[i]=(char*) malloc(sizeof(char)*10);
	}
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
