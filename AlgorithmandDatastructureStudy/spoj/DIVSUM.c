#include <stdio.h>
#include <math.h>

int main()
{
    unsigned int k,j,i,n,sum=1;
    unsigned int sq;
    scanf("%d",&j);

    for(i=0;i<j;i++)
    {
        scanf("%d",&n);
        sq=sqrt(n);
        k=2;
        while(k <= sq)
        {
            if(n%k == 0)
            {
                sum+=k;
                if(k!= (n/k))
                    sum+=(n/k);
            }
            k++;
        }
        printf("%d\n",sum);
        sum=1;
    }
        
}
