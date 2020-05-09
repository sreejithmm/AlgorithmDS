
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i,j,n,k;
    int *a;
    int max=0;
    int oldcount=0;
    int sum=0;
        printf("Enter the number of elements in the array\n");
        scanf("%d",&k);
        
        a = (int*)calloc(k,sizeof(int));

        for(i=0;i<k;i++)
        {
            scanf("%d",(a+i));
            (*(a+i))?oldcount++:oldcount;

        }
        printf("Input: with number of ones:%d \n",oldcount);
#if 0        
        for(i=0;i<k;i++)
        {
            printf("%d",*(a+i));
        }
#endif
        for(i=0;i<k;i++)
        {
            if(*(a+i) == 0)
            {
                *(a+i) = 1;
            }
            else
            {
                *(a+i) = -1;
            }

            sum = sum+*(a+i);
            if(sum <= 0)
            {
                max=0;
                sum=0;
            }
            else
            {
                if(max < sum)
                {
                    max=sum;
                }
            }

        }

        printf("\nMax count of 1s is %d\n",max+oldcount);

    
}
