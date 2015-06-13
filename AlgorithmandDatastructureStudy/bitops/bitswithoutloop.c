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
        array[i]=i&1 + array[i/2];
    }

    bitops= (char*)&nu;
    printf("array[bitops[0]]=%d  array[bitops[1]]=%d array[bitops[2]]=%d array[bitops[3]]=%d\n",
            array[bitops[0]],array[bitops[1]],array[bitops[2]],array[bitops[3]]);
    bits=array[bitops[0]]+array[bitops[1]]+array[bitops[2]]+array[bitops[3]];
    printf("Number of bits set=%d\n",bits);


    printf("Kernighans Method : \n" );

    bits =0;
    while(nu)
    {
      nu &= (nu -1);
      bits++;
    }
    printf("Number of bits set = %d \n",bits );
    return 0;
}
