/*
 *
 *
 * https://www.hackerrank.com/challenges/sherlock-and-array
 */

#include <stdio.h>
#include <stdlib.h>


typedef unsigned long long ULL;

int main()
{
	ULL nT,nC,i,t=0,tl,tr;
	ULL arr[100000]={0};
	ULL sumarr[100000]={0};

	scanf("%llu",&nT);
	while(nT)
	{
		scanf("%llu",&nC);
		for(i=0;i<nC;i++)
		{
			scanf("%llu",&arr[i]);
			t= t+arr[i];
			sumarr[i]=t;

		}

		for(i=0;i<nC;i++)
		{
				if(i == 0)
				{
					tl = 0;
				}
				else
				{
					tl = sumarr[i-1];
				}
				tr = sumarr[nC-1]-sumarr[i];
				if(tl == tr)
				{
					printf("YES\n");
					goto label;
				}

		}
		printf("NO\n");

label:
		t=0;
		nT--;
	}
	return 0;

}
