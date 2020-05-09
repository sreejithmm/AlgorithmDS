#include <stdio.h>

int main()
{
    int n;
    int highbit;
    int leftbit;
    int seqofones;

    printf("Enter a number\n");
    scanf("%d",&n);

    highbit =n & -n;
    leftbit = n+highbit;
    seqofones = leftbit + n;

    /*correction */
    seqofones >>= seqofones;
    seqofones >>= 2;

    printf("next number = %d\n",seqofones+leftbit);


}
