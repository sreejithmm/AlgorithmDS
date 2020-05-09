#include <stdio.h>
typedef unsigned long long ULL;

int main()
{
	ULL nT,nS;
	scanf("%lld",&nT);
	while(nT)
	{
		scanf("%lld",&nS);
		printf("%lld\n",(nS+1));
		nT--;
	}
	return 0;
}
