#include <stdio.h>

void printPairsToCalcSum(int arr[],int size,int sum)
{
    int dataMap[10000]={0};
    int i=0;
    int temp;
    for(i<0;i<size;i++)
    {
        temp = sum-arr[i];
        if(temp >0 &&  dataMap[temp]!=0 )
        {
            printf("%d %d\n",arr[i],temp);
        }
        dataMap[arr[i]]=1;
    }
}
