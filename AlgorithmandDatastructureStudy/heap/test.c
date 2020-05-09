#include <stdio.h>
#include <limits.h>

int main()
{
    int heap[1000]={INT_MIN};
    int k,j,t,l,m,n;
    int size = 0;

    printf("Inserting to the heap\n");
    printf("Enter the number of numbers to be inserted to the heap\n");
    scanf("%d",&n);
    printf("Enter %d numbers to heap\n",n);
    for(j=0;j<n;j++)
    {
        scanf("%d",&k);
        insert(heap,k,&size);

    }
    printf("Print heap\n");
    printHeap(heap,size);
    printf("Minimum value in heap:%d\n",getMin(heap));
    printf("Deleting the minimum value\n");
    deleteMin(heap,&size);
    printf("Minimum value in heap:%d\n",getMin(heap));
    printHeap(heap,size);
    heapSort(heap,size);
    printf("After heap sort\n");
    printHeap(heap,size);
    return 0;



}
