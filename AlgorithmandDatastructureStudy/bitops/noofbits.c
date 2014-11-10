#include <stdio.h>

int soln1(int );
int soln2(int );

int main()
{

    int num;
    int bits;

    printf("Enter a number\n");
    scanf("%d",&num);

    bits=soln1(num);
    printf("Number of bits set using soln1=%d\n",bits);



    bits=soln2(num);
    printf("Number of bits set using soln2=%d\n",bits);
    
    return 0;

}

int soln1( int num)
{
    int cnt=0;
    while(num) {
        
        if( num& 0x01)
        {
            cnt++;
            
        }
        num>>=1;


    }

    return cnt;

}

int soln2(int num)
{
    int cnt=0;
    while(num) {
        num&=(num-1);
        cnt ++;
    }
    return cnt;

}
