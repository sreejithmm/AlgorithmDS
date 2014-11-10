#include <stdio.h>

int squares(int n,int size)
{
    int i,j;
    int sum=0;


    for(i=n;i<=size;i++)
        for(j=n;j<=size;j++)
            sum++;

    return sum;

}

int recursq(int size)
{
    if(size == 1)
        return 1;
    return((size*size)+recursq(size-1));
}
int main()
{
    int i;
    int sum=0;
    int size = 2;
    scanf("%d",&size);
    for(i=1;i<=size;i++)
    {
        sum = sum+squares(i,size);
       
    }
    
    printf("%d\n",sum);
    printf("Using recursion = %d\n",recursq(size));

}




