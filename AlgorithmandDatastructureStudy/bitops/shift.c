#include <stdio.h>

int main()
{

    int num = -1;
    num >>= 1 ;
   if( num <0) {
       printf("Arithmetic Shift\n");
   }
   else {
       printf("Logical shift\n");
   }
    printf("%d\n",num);
   return 0;
}
