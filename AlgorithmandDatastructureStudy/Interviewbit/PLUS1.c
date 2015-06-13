#include <stdio.h>

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 *
 * @Output Integer array. You need to malloc memory for result array, and fill result's length in length_of_array
 */

 int getlen(int sum)
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
         int len = *length_of_array;
         int *result;
         int sum =0;
         int i=1;
         int leading_zero = A[0];
         int newlen=0;

         for(indx =0; indx <len; indx++)
         {
            if(!leading_zero){
              continue;
              leading_zero = (A[indx++])?1:0;
            }
             sum = A[indx]+ sum*i;
             i=i*10;
         }
         sum = sum+1;
         newlen = getlen(sum);
         result = (int*)malloc(sizeof(int)*newlen);
         for(i=newlen-1; i>=0;i--)
         {
           result[i]=sum%10;
           sum = sum/10;
         }
         *length_of_array = newlen;
         return result;
}
