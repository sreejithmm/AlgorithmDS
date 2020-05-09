#include <stdio.h>
#include <stdlib.h>


#define size_of(type,val)  ({ \
                                  ((type*)0)+1; \
                                })

int main(){

 unsigned int num1;
  int num2;

 printf("Sizoe of unsigned int = %d\n",size_of(unsigned int,num1));
 printf("Suzie of          int = %d\n",size_of(int, num2));
 return 0;


}

