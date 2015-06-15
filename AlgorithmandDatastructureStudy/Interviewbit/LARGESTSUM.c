

#include <stdio.h>

/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output string. Make sure the string ends with null character
 */

 int mycomp(void* a, void* b)
 {
 	int x = *(int*)a;
 	int y = *(int*)b;
 	char str1[50]={'\0'}
 	sprintf(str1,"%d%d",x,y);
 	sprintf(str2,"%d%d",y,x);
 	if(strcmp(str1,str2)>0))
	{
		return -1;
	}
	else
	{
		return 1;
	}

 }

char* largestNumber(const int* A, int n1)
{
	char str[50];

	/*sort the numbers */
	qsort(A,n1,sizeof(A[0]),mycomp);

}
