#include <stdio.h>


int main()
{


    int nu;
    unsigned char array[256];

    char* bitops;
    int bits;
    int i;

    printf("Enter a number \n");
    scanf("%d",&nu);

    for (i=0;i<256;i++){
        array[i]=i+1;
    }

    bitops= (char*)&nu;

    bits=array[bitops[0]]+array[bitops[1]]+array[bitops[2]]+array[bitops[3]];
    printf("Number of bits set=%d\n",bits);
    return 0;
}
    
