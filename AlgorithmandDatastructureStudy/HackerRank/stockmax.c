/*
 *
 *https://www.hackerrank.com/challenges/stockmax
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
int starr[250000];
int getmid(int start,int end)
{

	    int mid;
	        mid = start +(end-start)/2 ;
		    return mid;
		           
}
int max(int a ,int b)
{

	    if(a>b) return a;
	        
	        return b;
}
int constructSTforMax(int arr[], int start, int end, int *st, int stidx)
{
	int mid;
	if (start == end) {
		st[stidx] = arr[start];
		return arr[start];
	}
	mid = getmid(start, end);
	st[stidx] =
	    max(constructSTforMax
		(arr, start, mid, st, 2 * stidx + 1),
		constructSTforMax(arr, mid + 1, end, st, 2 * stidx + 2));
	return st[stidx];
}

int *constructSTForMaxUtil(int arr[], int n, int *segsize)
{
	int stsize = 2 * n - 1;
	*segsize = stsize;
	int *st=starr;
	constructSTforMax(arr, 0, n - 1, st, 0);
	return st;
}

int getMaxOnaRangeUtil(int *st, int rangest,
		       int rangeen, int strt, int end, int stidx)
{
	int max2;
	int mid;
	if (rangest <= strt && rangeen >= end) {

		return st[stidx];
	}
	if (strt > rangeen || end < rangest) {
		return INT_MIN;
	}

	mid = getmid(strt, end);
	max2 =
	    max(getMaxOnaRangeUtil
		(st, rangest, rangeen, strt, mid,
		 2 * stidx + 1), getMaxOnaRangeUtil(st,
						    rangest,
						    rangeen,
						    mid +
						    1, end,
						    2 * stidx + 2));
	return max2;
}

int getmaxbetween(int *st, int rangest, int rangeen, int size)
{

	if (rangest < 0 && rangeen >= size) {
		return INT_MIN;
	}

	return (getMaxOnaRangeUtil(st, rangest, rangeen, 0, size - 1, 0));
}

FILE* fp=NULL;
void init()
{
	fp = fopen("case.txt","r");
	
}
int readInt()
{
	int n;
	fscanf(fp,"%d",&n);
	return n;
}
int main()
{
	int nT;
	int n;
	int i, j, k, l = 0, m = 0;
	unsigned long long priceB = 0, priceS = 0, profit=0;
	int arr[50000];
	int *st, stsize;
	unsigned long long  result[10];

#ifdef DEBUG
	init();
	nT=readInt();
#else
	scanf("%d", &nT);
#endif
	for (i = 0; i < nT; i++) {
#ifdef DEBUG
		n = readInt();
#else
		scanf("%d", &n);
#endif
		for (k = 0; k < n; k++) {
#ifdef DEBUG
			arr[k]=readInt();
#else
			scanf("%d", &arr[k]);
#endif
		}
		st = constructSTForMaxUtil(arr,n,&stsize);
		for (k = 0; k < n; k++) {
			if (arr[k] < getmaxbetween(st,k+1,n,n)) {

				priceB += arr[k];
				l++;
			}
			else {
				priceS = (unsigned long long)l*arr[k];
				profit = profit+ (priceS-priceB);
				priceB =0 ;
				l = 0;
			}
		}
		result[i] =profit;
		profit = 0;
		l = 0;
		priceB = 0;
	}
	for(i=0;i<nT;i++) {
		printf("%llu\n",result[i]);
	}
}



