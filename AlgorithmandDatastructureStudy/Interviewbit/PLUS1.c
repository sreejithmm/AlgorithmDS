#include <stdio.h>

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 *
 * @Output Integer array. You need to malloc memory for result array, and fill result's length in length_of_array
 */

 int getlen(unsigned long long sum)
 {
   int count=1;
   if(sum == 0)
    return 1;
   while(sum/10)
   {
      count++;
       sum = sum/10;
   }
   return count;
 }
int* plusOne(int* A, int n1, int *length_of_array) {

        /*
         * *length_of_array = n1 + 1; // length of result array
         * int *result = (int *) malloc(*length_of_array * sizeof(int));
         * // DO STUFF HERE. NOTE : length_of_array can be n1 OR n1 + 1.
         * return result;
         */

         int indx=0;
         int len = n1;
         int *result;
         unsigned  long long sum =0;
         int i=1;
         int leading_zero = A[0];
         int newlen=0;

         for(indx =0; indx <len; indx++)
         {
            if(!leading_zero){

              leading_zero = (A[indx+1]!=0)?1:0;
              printf("leading_zero val = %d\n",leading_zero);
              continue;
            }
             sum = A[indx]+ sum*i;
             printf("index=%d sum=%llu\n",indx,sum);
            i= 10;
         }
         printf("original nubmer = %llu\n",sum);
         sum = sum+1;
         newlen = getlen(sum);
         printf("Newlen=%d\n",newlen);
         result = (int*)malloc(sizeof(int)*newlen);
         for(i=newlen-1; i>=0;i--)
         {
           result[i]=sum%10;
           printf("result[%d]=%d",i,result[i]);
           sum = sum/10;
         }
         *length_of_array = newlen;
         return result;
}
int main()
{
  int array[]={0, 3, 7, 6, 4, 0, 5, 5, 5};
  int len = sizeof(array)/sizeof(array[0]);

  int newlen,i;
  int *result;

  result = plusOne(array,len,&newlen);
  for(i=0;i<newlen;i++)
  {
    printf("%d ",result[i]);
  }
  printf("\n");
  return 0;
}
