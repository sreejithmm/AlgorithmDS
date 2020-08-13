

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


