#include <stdio.h>

int getParent(int index)
{

    return((index-1)/2);

}
int getleftChild(int index)
{
    return((2*index)+1);
}
int getRightChild(int index)
{
    return((2*index)+2);
}

int insert(int heap[],int num,int* size)
{
    int location = *size;
    int parentnode=getParent(location);

    while(location >0)
    {
        if(heap[parentnode] < num)
        {
    
            heap[location] = num;
            *size = *size + 1;
            return 0;
        }
        heap[location]=heap[parentnode];
        location = parentnode;
        parentnode = getParent(location);
    }
    heap[0]=num;
    *size = *size + 1;
    return 0;
}

int getMin(int heap[])
{
    return heap[0];
}

int getMinValueIdx(int heap[],int lidx, int ridx)
{
    if(heap[lidx] > heap[ridx])
    {
        return ridx;
    }
    return lidx;
}
void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
    return ;
}

void heapify(int heap[],int index,int size)
{

    int lidx = getleftChild(index);
    int ridx = getRightChild(index);
    int smallestidx;

    while(lidx <size && ridx < size)
    {
        smallestidx = getMinValueIdx(heap,lidx,ridx);
        if(heap[smallestidx] > heap[index])
        {
            return ;
        }
        swap(&heap[smallestidx],&heap[index]);
        index = smallestidx;
        lidx = getleftChild(index);
        ridx = getRightChild(index);

    }

}


void deleteMin(int heap[], int *size)
{
    int len = *size;
    
    swap(&heap[0],&heap[len-1]);
    (*size)--;
    heapify(heap,0,*size);
    return;
}


void heapSort(int heap[], int size)
{
    while(size>1)
    {
        swap(&heap[0],&heap[size-1]);
        size--;
        heapify(heap,0,size);
    }
    
}

void printHeap(int heap[],int size)
{
    int i;

    for(i=0;i<size;i++)
    {
        printf("%d ",heap[i]);
    }
    printf("\n");
}

