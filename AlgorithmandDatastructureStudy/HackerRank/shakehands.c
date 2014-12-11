/*
 *
 *
 * https://www.hackerrank.com/challenges/handshake
 */
#include <stdio.h>

typedef unsigned long long ULL;

int main()
{
	ULL nT, nS,temp;
	scanf("%llu",&nT);

	while(nT)
	{
		scanf("%llu",&nS);
		if((nS & 0x1) == 0){
			temp = nS/2;
			temp = temp*(nS-1);
		}
		else
		{
			temp = (nS-1)/2;
			temp = temp * nS;
		}
		printf("%llu\n",temp);
		nT--;
	}
	return 0;
	
	
}
