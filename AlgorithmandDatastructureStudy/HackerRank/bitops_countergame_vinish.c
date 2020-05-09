#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define PRINT

typedef int bool;
#define true 1
#define false 0

int main() {

    unsigned int T = 0;
    unsigned long long int * N = NULL;
    unsigned long long int num = 0x0ULL;
    unsigned long long int pw2 = 0x0ULL;
    int i = 0;
    int j = 0;
    bool flag = 0;

    char * p1 = "Louise";
    char * p2 = "Richard";


    N = (unsigned long long int *)malloc(T * sizeof(unsigned long long int *));

    scanf("%d",&T);

    for(i = 0 ; i < T ; i++)
    {
         scanf("%llu",&N[i]);

    }
    for(i = 0 ; i < T ; i++)
    {
         flag = 0;
         num = N[i];
         while(num != 0x1ULL)
         {
             PRINT("Flag = %d NUM = 0x%llx \n",flag,num);
             if((unsigned long long int )(num & (num -1)) != 0x0ULL)/*not a power of 2*/
             {

  //               PRINT("NUM not pow2= 0x%llx \n",num);
                 for(j = 63 ; j >=0 ; j-- )
                 {

                     if((unsigned long long int )(num & ((unsigned long long int )0x1ULL << j)) != 0x0ULL)
                     {
                          pw2 = (unsigned long long int ) 0x1ULL << j;
                          PRINT("%d ",j);
                          break;
                     }
                 }
                 PRINT("\n");

                 num = (unsigned long long int )(num - pw2)  ;
                 PRINT("pw2 = 0x%llx NUM = 0x%llx \n",pw2,num);


             }
             else/*power of 2*/
             {
 //                PRINT("NUM pow2= 0x%llx \n",num);
                 num = (unsigned long long int )num >> 1 ;


             }
             flag = !flag ;
         }
        (flag) ? printf("%s\n",p1) : printf("%s\n",p2);

    }

    return 0;
}

