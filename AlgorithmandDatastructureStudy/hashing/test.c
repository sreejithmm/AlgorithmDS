#include <stdio.h>
int main()
{
    int i,k,j,l,m;
    int arr[100];
    printf("Options\n");
    printf("*******\n");
    printf("1. Print pairs which adds to a sum\n");
    scanf("%d",&k);
    switch(k)
    {
        case 1:
            printf("Enter the number of elements\n");
            scanf("%d",&m);
            printf("Enter elements to an array\n");
            for(i=0;i<m;i++)
            {
                scanf("%d",&arr[i]);
            }
            printf("Enter the sum value to be evaluated to\n");
            scanf("%d",&l);
            printPairsToCalcSum(arr,m,l);
            break;

    }
}
