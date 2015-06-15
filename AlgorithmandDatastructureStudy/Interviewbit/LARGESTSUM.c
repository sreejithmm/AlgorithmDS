

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

 	char str1[50]={'\0'};
  char str2[50]={'\0'};

 	sprintf(str1,"%d%d",x,y);
 	sprintf(str2,"%d%d",y,x);
 	if(strcmp(str1,str2)>0)
	{
		return -1;
	}
	else
	{
		return 1;
	}

 }

 void print_arr(int a[],int len)
 {
   int i;
   for(i=0;i<len;i++)
   {
     printf("%d ",a[i]);
   }
   printf("\n");
 }

 void make_string(int* arr, char* str,int len)
 {
   int i;
   for(i=0;i<len;i++)
   {
     sprintf(str,"%d",arr[i]);
   }

 }

char* largestNumber( int* A, int n1)
{
	char str[50]={'\0'};

	/*sort the numbers */
	qsort(A,n1,sizeof(A[0]),mycomp);

//  print_arr(A,n1);

	make_string(A,str,n1);

  //printf("String = %s",str);
  return str;
}

int main()
{
  int array={8,89};
  int len = sizeof(array)/sizeof(array[0]);

  printf("output = %s",largestNumber(array,));

}
