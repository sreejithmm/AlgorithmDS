


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
   char buf[50]={'\0'};

   for(i=0;i<len;i++)
   {
     sprintf(buf,"%d",arr[i]);
     strcat(str,buf);
     memset(buf,'\0',50);
   }

 }

char* largestNumber( const int* A, int n1)
{
	char* str=(char*)malloc(sizeof(char)*50);

	/*sort the numbers */
	int i;
	int * array = (int*)malloc(sizeof(int)*n1);
	for(i=0;i<n1;i++)
	{
	    array[i]=A[i];
	}
	qsort(array,n1,sizeof(A[0]),mycomp);

//  print_arr(array,n1);

	make_string(array,str,n1);

  //printf("String = %s",str);
  return str;

}

int main()
{
  int array[]={8,89};
  int len = sizeof(array)/sizeof(array[0]);

  printf("output = %s",largestNumber(array,len));

}
