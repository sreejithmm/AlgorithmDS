#include <stdio.h>

#define BIT_OPS(x)  (1<<x)

int main()
{

    int num;
    int bit;
    int temp;

    printf("Enter a number\n");
    scanf("%d",&num);

    temp=num;

    printf("Enter the bit to be set and unset\n");
    scanf("%d",&bit);

    printf("bit set::\n");
    temp |= BIT_OPS(bit);

    printf("%d\n",temp);
    temp=num;
    
    temp &= ~BIT_OPS(bit);
    printf("bit unset:%d\n",temp);

    return;

}
