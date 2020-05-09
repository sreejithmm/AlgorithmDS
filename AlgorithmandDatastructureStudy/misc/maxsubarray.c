#include <stdio.h>
#include <stdlib.h>

int main()
{


    int arr[]={1,4,3,5,6,2,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int i,j,max=1;

    int* wtdarr = (int*)malloc(size);

    wtdarr[size-1] = arr[size-1];
    max = wtdarr[size-1];
    for(i=size-1;i>=0;i--)
    {

        wtdarr[i] = arr[i];
        for(j=i+1;j<size;j++)
        {
            if(arr[i] < arr[j])
            {
                wtdarr[i] += wtdarr[j];
                break;

            }
        }
        if(wtdarr[i] > max)
        {
            max=wtdarr[i];
        }
    }

    printf("max=%d\n",max);


}
