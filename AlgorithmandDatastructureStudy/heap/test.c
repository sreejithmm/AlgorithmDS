#include <stdio.h>
#include <limits.h>


#include <strings.h>
#include <stdlib.h>


int getleftChild(int index)
{
    return((2*index)+1);
}
int getRightChild(int index)
{
    return((2*index)+2);
}


int getMin(int heap[])
{
    return heap[0];
}

int getMaxValueIdx(int heap[],int lidx, int ridx)
{
    if(heap[lidx] < heap[ridx])
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
    int highestidx;

    while(lidx <size && ridx < size)
    {
        highestidx = getMaxValueIdx(heap,lidx,ridx);
        if(heap[highestidx] < heap[index])
        {
            return ;
        }
        swap(&heap[highestidx],&heap[index]);
        index = highestidx;
        lidx = getleftChild(index);
        ridx = getRightChild(index);

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


int getParent(int index)
{

    return((index-1)/2);

}
int insert(int heap[],int num,int* size)
{
    int location = *size;
    int parentnode=getParent(location);

    while(location >0)
    {
        if(heap[parentnode] >num)
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



int* generate(int* input , int size)
{
	int *heap;
	int i,k=0;
	heap = (int *) malloc(sizeof(int)* size);
	memset(heap,0,size);

	for (i=0;i<size ;i++)
	{
		printf("Input = %d loc = %d\n",input[i],k);
		insert(heap,input[i],&k);

	}
	heapify(heap,0,size);
	return heap;

}


int main()
{
    int heap[1000]={INT_MIN};
    int k,j,t,l,m,n;
    int size = 0;
    int input[100] = {0};
    int *output;

    printf("Inserting to the heap\n");
    printf("Enter the number of numbers to be inserted to the heap\n");
    scanf("%d",&n);
    output = (int*) malloc(sizeof(int)*n);
    printf("Enter %d numbers to heap\n",n);
    for(j=0;j<n;j++)
    {
        scanf("%d",&input[j]);

    }

   output = generate(input,n);

   printHeap(output,n);
    return 0;

}
