#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "heap.h"

#define PRINT

int my_heap[1000] = {INT_MIN};

unsigned int getParent(unsigned int idx)
{
	return ((idx -1) / 2);

}

unsigned int getLchildidx( unsigned int idx)
{
	return (2*idx) + 1;

}
unsigned int getRchildidx(unsigned int idx)
{
	return (2*idx) + 2;

}

int insert(int heap[],int val,unsigned int * size)
{
	unsigned int pos = 0;
	unsigned int parentPos = 0;
	pos = *size ;

        PRINT("inset Val = %d \n",val);
	while(pos > 0)
	{
		parentPos = getParent(pos);
		if(heap[parentPos] < val)
		{
			heap[pos] = val;
			*size = *size + 1;

			return 0;
		}
		else
		{
			heap[pos] = heap[parentPos];
			pos = parentPos;
		}


	}

	heap[0] = val ;
	*size = *size + 1;
        return 0;

}

int getMin(int heap[])
{
    return heap[0];
}


void swap(int * a ,int * b)
{
    int temp = *a;
    *a = *b ;
    *b = temp;

}
unsigned int getMinvalidx(int heap[],unsigned int lidx,unsigned int ridx )
{
      if(heap[lidx] > heap[ridx])
	      return ridx;
      else
	      return lidx;

}

void heapify(int heap[],unsigned int idx,unsigned int *size)
{
     unsigned int ridx = 0;
     unsigned int lidx = 0;
     unsigned int smallidx = 0;
     
     ridx = getRchildidx(idx);
     lidx = getLchildidx(idx);


     if(ridx < *size && lidx < *size)
     {    
         smallidx = getMinvalidx(heap,lidx,ridx);
     }
     else if(ridx < *size)
     {
         smallidx = ridx;
     }
     else
     {
         smallidx = lidx;
     }
     if(ridx >= *size && lidx >= *size )
	     return ;

     PRINT("ridx = %d lidx = %d smallidx = %d \n",ridx,lidx,smallidx);
     if(heap[smallidx] > heap[idx])
     {
         return ;
     
     }
     else
     {
          swap(&heap[idx],&heap[smallidx]);
	  idx = smallidx;
	  heapify(heap,idx,size);
     }
}

void delMin(int heap[],unsigned int * size)
{
    unsigned int lastidx = *size-1 ;
        
    PRINT("Del Val = %d \n",heap[0]);
    PRINT("heap[lastidx]  = %d \n",heap[lastidx]);
    swap(&heap[0],&heap[lastidx]);
    *size = *size - 1;
    PRINT("Afer Del heap[0] = %d size = %d \n",heap[0],*size);
    heapify(heap,0,size);
    return;

}

void printHeap(int heap[],unsigned int size)
{
    unsigned int i = 0;

    printf("size of heap = %d\n",size);
    for(i = 0 ; i < size ; i++)
    {
        printf("%d ",heap[i]);
    }
    printf("\n");
    return ;
}

void heapSort(int heap[],unsigned int size)
{
    PRINT("Heap Sort\n");
    while(size > 1)
    {
        swap(&heap[0],&heap[size-1]);
	size--;
	heapify(heap,0,&size);
    }

}

int main()
{
        unsigned int n = 10;
        unsigned int size = 0;
        unsigned int i = 0;
	for(i = 0 ; i < n  ; i++)
	{
	      PRINT("val i = %d\n",n-i);
	      PRINT("size = %d\n",size);
	      insert(my_heap,n-i,&size);
              printHeap(my_heap,size);
	}
	
	for(i = 0 ; i < n  ; i++)
	{
//	      delMin(my_heap,&size);
//              printHeap(my_heap,size);
	}
#if 1
        printHeap(my_heap,size);
        delMin(my_heap,&size);
        printHeap(my_heap,size);

        delMin(my_heap,&size);
        printHeap(my_heap,size);

	insert(my_heap,0,&size);
        printHeap(my_heap,size);

	insert(my_heap,2,&size);
        printHeap(my_heap,size);

        delMin(my_heap,&size);
        printHeap(my_heap,size);
#endif
	heapSort(my_heap,size);
        printHeap(my_heap,size);

	return 0;
}

