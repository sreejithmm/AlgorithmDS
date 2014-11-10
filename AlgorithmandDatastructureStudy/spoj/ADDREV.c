#include <stdio.h>
#include "template.h"

ULL64 reverse(ULL64 a)
{
    ULL64 num=0;
    while(a!=0)
    {
        num = num*10 + (a%10);
        a=a/10;

    }
    return num;
}
int main()
{
    UI32 n;
    ULL64 a,b;
    int i;
    ULL64 sum;

    scanf("%u\n",&n);
    for(i=0;i<n;i++)
    {
        scanf("%llu",&a);
        a = reverse(a);
        scanf("%llu",&b);
        b=reverse(b);
        sum = a+b;
        sum = reverse(sum);
        printf("%llu\n",sum);
    }
    return 0;
    
}
