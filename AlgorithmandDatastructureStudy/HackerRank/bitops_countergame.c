#include <stdio.h>
#include <math.h>


unsigned long long power(unsigned long long base, unsigned int exp)
{
     unsigned  long long result = 1;
     
     while (exp)
     {
          if (exp & 1)
                 result *= base;
          exp >>= 1;
          base *= base;
     }

     return result;

}
unsigned int maxbitset(unsigned long long n)
{
    const unsigned long long  b[] = {0x2, 0xC, 0xF0, 0xFF00, 0xFFFF0000,0xFFFFFFFF00000000};
    const unsigned int S[] = {1, 2, 4, 8, 16,32};
    int i;

    register unsigned int r = 0; // result of log2(v) will go here
    for (i = 5; i >= 0; i--) // unroll for speed...
    {
          if (n & b[i])
          {
             n >>= S[i];
             n |= S[i];
          } 
    }
}
int getWinner(unsigned long long n,unsigned int w)
{

        unsigned int b;
        unsigned long long p;

        if((n&(n-1)) == 0)
        {
            n=n/2;
        }
        else{
            b=log2(n);
            p = power(2,b);
            n = n-p;
        }
        if(n==1)
        {
            return w;
        }
        return (getWinner(n,~w));


}
int main()
{
    unsigned int t,i,j,b;
    unsigned long long n,p;

    int res;

    scanf("%d",&t);
    for(i=0;i<n;i++)
    {
        scanf("%llu",&n);
        if(n==1)
        {
            printf("Louise\n");
        }
        res = getWinner(n,0xFFFFFFFF);
        if(res==0xFFFFFFFF)
        {
            printf("Louise\n");
        }
        else
        {
            printf("Richard\n");
        }


    }
}
