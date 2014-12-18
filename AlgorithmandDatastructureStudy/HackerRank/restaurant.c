/*
 *
 * https://www.hackerrank.com/challenges/restaurant
 */
#include <math.h>
#include<stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int main()
{
	int nT,i,k,j,l,b,m,sq;
	int result[1000]={0};
	scanf("%d",&nT);


	for(i=0;i<nT;i++)
	{

		scanf("%d %d",&l,&b);
		k=l*b;
		m=sqrt(k);
		while(m)
		{
			
			if((k)%(m*m) == 0 &&( l%m == 0) && (b%m == 0))
			{
				break;
			}
			m--;
		}
		if(m==0)
		{
			result[i]=k;
		}
		else
		{
			result[i]=k/(m*m);
		}
	}
	for(i=0;i<nT;i++)
	{
		printf("%d\n",result[i]);

	}

}
