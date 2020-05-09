/*
 *https://www.hackerrank.com/challenges/bday-gift
 */
#include <stdio.h>

int main()
{
	unsigned int nS;
	unsigned int arr[40]={0};
	double sum=0.0;
	unsigned int i;

	scanf("%u",&nS);
	for(i=0;i<nS;i++)
	{
		scanf("%u",&arr[i]);
		sum = sum + (0.5* arr[i]);
	}
	printf("%.1lf\n",sum);


}
