/*
 *
 * Author:Sreejith M M
 * https://www.hackerrank.com/challenges/substring-diff
 */

#include <stdio.h>
#include <string.h>

int max(int i,int j)
{
	if (i>j)
		return i;
	else
		return j;
}
int bestof(int a, int b, int c)
{
	if(a > b)
	{
		if(a>c)
			return a;
		else
			return c;
	}
	else if( b > c)
	{
		return b;
		
	}
	else
	{
		return c;
	}
}
int getLength(int i, int j, int k,char* str1, char* str2)
{

	int best=0,bad=0;
	int iT,jT;
	int l =0;

	iT=i;
	jT=j;


	while(1)
	{
		if( ((iT+l) > strlen(str1)) || ((jT+l) > strlen(str2)))
		{
			best = max(best,l);
			break;
		}
		if(str1[iT+l] != str2[jT+l])
		{
			bad++;
		}
		if(bad > k)
		{
			best = max(best,l);

			while(str1[iT] == str2[jT])
			{
				iT++;
				jT++;
				l--;

			}
			bad--;
			iT++;
			jT++;
		}
		else
		{
			l++;
		}


	}
	return best;
}

int main()
{
	char str1[1500]={'\0'};
	char str2[1500]={'\0'};

	int nT, nD,i,j,result[10];
	int maxL = 0;
	int strl=0;

	scanf("%d",&nT);

	for(i=0;i<nT;i++)
	{
		scanf("%d",&nD);
		scanf("%s",str1);
		scanf("%s",str2);
		
		strl = strlen(str1);
		printf("stringlength[%d]=%d\n",	i,strl);	
		for(j=0;j<strl;j++){
			
			maxL= bestof(maxL,getLength(0,j,nD,str1,str2),getLength(j,0,nD,str1,str2));
		}
		result[i]=maxL;
		memset(str1,'\0',1500);
		memset(str2,'\0',1500);

	}
	for(i=0;i<nT;i++)
	{
		printf("%d\n",result[i]);
	}

}
