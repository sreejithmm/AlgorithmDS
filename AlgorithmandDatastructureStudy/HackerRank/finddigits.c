/*
 *
 *
 * https://www.hackerrank.com/challenges/find-digits
 *
 */


#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ULL;
int main()
{
	ULL nT,num,i,t,count=0;

	scanf("%llu",&nT);
	while(nT)
	{
		scanf("%llu",&num);
		t= num;
		count = 0;
		while(t) 
		{
			i = t %10;
			if(i == 0)
			{
				/* do nothing */

			}
			else if((num %i ) == 0)
			{
				count++;
			}
			t = t/10;
		}
		printf("%llu\n",count);
		nT--;
	}
	return 0;

}
