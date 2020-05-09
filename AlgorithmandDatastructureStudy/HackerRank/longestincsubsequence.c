/*
 *
 *https://www.hackerrank.com/challenges/longest-increasing-subsequent
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define DEBUG
#define FILE_INPUT

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
#ifdef DEBUG
		printf("i:%llu \n",i);
#endif
			lastIdx=i;
		for(j=0;j<i  ;j++)
		{
#ifdef DEBUG
			printf("arr[i]:%llu j:%llu l[j].largestVal:%llu l[j].count:%llu maxcount=%llu\n",
					arr[i],j,l[j].largestVal,l[j].count,maxcount);
#endif

			if(arr[i] > l[j].largestVal && l[j].count >=maxcount)
			{
#ifdef DEBUG
			printf("arr[%llu]:%llu j:%llu l[j].largestVal:%llu l[j].count:%llu maxcount=%llu\n",
					i,arr[i],j,l[j].largestVal,l[j].count,maxcount);
#endif		
				lastIdx = j;

				maxcount = l[j].count;

			}
		}

		maxcount = 0;
		l[lastIdx].largestVal = arr[i];
		l[lastIdx].count = l[lastIdx].count + 1;
		count = max(count,l[lastIdx].count);
#ifdef DEBUG
		printf("l[%llu].count=%llu l[%llu].largestVal = %llu lastIdx=%llu \n",lastIdx,l[lastIdx].count,lastIdx,l[lastIdx].largestVal,lastIdx);
#endif

	}
//	for(i=0;i<num;i++)
//	{
//		count = max(count,l[i].count);
//	}
	return count;
	


}

void readInput(ULL* num, ULL* arr)
{
	ULL i;

#ifdef FILE_INPUT
	FILE* fd=fopen("case.txt","rw");
	fscanf(fd,"%llu",num);
	arr=(ULL*)calloc(*num,sizeof(ULL));

	for(i=0;i<*num;i++)
	{
		fscanf(fd,"%llu",&arr[i]);
	}
	fclose(fd);
	return;
#endif
	scanf("%llu",num);
	
	arr=(ULL*)calloc(*num,sizeof(ULL));

	for(i=0;i<*num;i++)
	{
		scanf("%llu",&arr[i]);
	}

}

int main()
{
	ULL num,i;
	ULL *arr;
	ULL count;

	readInput(&num, arr);
	count = getCountForLongestSequence(arr,num);
	printf("%llu\n",count);

}
