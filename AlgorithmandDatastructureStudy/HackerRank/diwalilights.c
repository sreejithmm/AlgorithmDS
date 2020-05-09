/*
 *
 * https://www.hackerrank.com/challenges/diwali-lights
 *
 */

#include <stdio.h>
#include <math.h>

typedef unsigned long long ULL;
ULL getLightsCount(ULL lights)
{
	ULL base = 100000;
	ULL temp=1,i;
	if(lights == 0)
		return 0;
	for(i=1;i<=lights;i++)
	{
		temp = (temp)%base *2;
	}
	temp = temp %base;
	temp = temp - 1;
 	return temp;	
	
	
	
}
int main()
{
	ULL nT,nL,res;
	scanf("%llu\n",&nT);
	
	while(nT)
	{
		scanf("%llu",&nL);
		res = getLightsCount(nL);
		printf("%llu\n",res);
		nT--;
	}


	return 0;


}
