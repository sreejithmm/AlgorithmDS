/*
 *
 *https://www.hackerrank.com/challenges/longest-increasing-subsequent
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef unsigned long long ULL;

typedef struct node {
	ULL count;
	ULL largestVal;
}list;


ULL max(ULL a, ULL b)
{
	if(a>b)
		return a;
	else 
		return b;
}
ULL getCountForLongestSequence(ULL arr[], ULL num)
{
	ULL lastIdx=0,i,j,idx,maxcount=0,count=0;
	list* l = (list*)calloc(num,sizeof(list));

	list *temp;
	for(i=0;i<num;i++)
	{
		for(j=0;j<i  ;j++)
		{
			if(arr[i] > l[j].largestVal && l[j].count >=maxcount)
			{
				lastIdx = j;
				maxcount = l[j].count;

			}
		}

		l[j].largestVal = arr[i];
		l[j].count = l[j].count + 1;
	}
	for(i=0;i<num;i++)
	{
		count = max(count,l[i].count);
	}
	return count;
	


}

int main()
{
	ULL num,i;
	ULL *arr;
	ULL count;

	scanf("%llu",&num);
	
	arr=(ULL*)calloc(num,sizeof(ULL));

	for(i=0;i<num;i++)
	{
		scanf("%llu",&arr[i]);
	}
	count = getCountForLongestSequence(arr,num);
	printf("%llu\n",count);

}
