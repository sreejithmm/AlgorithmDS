/*
 *https://www.hackerrank.com/challenges/anagram
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

FILE* fd;
void init()
{
	fd = fopen("case_anagram.txt","r");

}

int main()
{
	int alpharr[26]={0};
	int nT,i=-1,j,k,len,cnt=0;
	char string[10000]={'\0'};
	int resultarr[10000];
#ifdef FILE_INPUT
	init();
	fscanf(fd,"%d",&nT);
#else
	scanf("%d",&nT);
#endif
	for(j=0;j<nT;j++)
	{
		memset(string,'\0',10000);
#ifdef FILE_INPUT
		fscanf(fd,"%s",string);
#else
		scanf("%s",string);
#endif

		len = strlen(string);
		if(len %2 !=0)
		{
			resultarr[j]=-1;
			continue;
		}
		for(k=0;k<len/2;k++)
		{
			alpharr[string[k]-'a'] += 1;
		}
		for(k=len/2;k<len;k++)
		{
			if(alpharr[string[k]-'a'] == 0)
			{
				cnt++;
			}
			else
			{
				alpharr[string[k]-'a'] -=1;
			}
		}
		resultarr[j]=cnt;
		bzero(alpharr,26*sizeof(int));
		cnt = 0;
		

	}
	for(i=0;i<nT;i++)
	{
		printf("%d\n",resultarr[i]);
	}

}

