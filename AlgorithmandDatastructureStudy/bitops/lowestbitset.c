#include <stdio.h>
#include <stdlib.h>


int main(){


    int num,lb;
    printf("Enter a number\n");
    scanf("%d",&num);
    lb = (num) & -(num);
    printf("Lowest bit set:%d\n",lb);
    printf("Lowest bit set:%d\n",-num);
    return 0;
}
