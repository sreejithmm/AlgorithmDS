#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long uint64_t;
FILE * output;

//#define TEST 1
#define MEDIAN_
void dump_array(uint64_t arr[]) {

    uint64_t index ;
    for (index = 0; index <10 ;index++) {
        fprintf(output,"%llu ",arr[index]);
    }
    fprintf(output,"\n");


}
void swap(uint64_t arr[],uint64_t start, uint64_t pivot) {

    uint64_t temp;
    temp = arr[pivot];
    arr[pivot] = arr[start];
    arr[start]  = temp;


}




uint64_t get_median(uint64_t arr[],uint64_t start,uint64_t mid, uint64_t end) {
  
      uint64_t median = 0;
      uint64_t a = arr[start];
      uint64_t b = arr[mid];
      uint64_t c = arr[end];
  
  
      if ((a<b && a>c) || (a<c && a>b)) median = start;
      else if ((b<a && b >c ) || (b<c && b>a)) median = mid;
      else median = end;;
  
      fprintf(output,"median of %llu %llu %llu is %llu::median index = %llu\n",arr[start],arr[mid],arr[end],arr[median],median);
      return median;
}

uint64_t choose_pivot(uint64_t arr[],uint64_t length, uint64_t start,uint64_t end, uint64_t* pivot) {

    uint64_t partition = start;;
    uint64_t i = 0;
    uint64_t temp;
    uint64_t num_comparison = length-1;
#ifdef END_
    *pivot = end;
#endif
#ifdef MEDIAN_
     uint64_t middle =  (end-start)/2;
     uint64_t median = get_median(arr,start,middle,end);
     *pivot = median;
#endif
#ifdef START_
	*pivot = start;

#endif
    fprintf(output,"Swapping between start = %llu and pivot = %llu\n",start,*pivot);
    swap(arr,start,*pivot);
    uint64_t swapper  = arr[start];
    *pivot = start;
#ifdef TEST
    dump_array(arr);
#endif
    fprintf(output,"pivot = %llu arr[*pivot] = %llu partition=%llu  start = %llu end = %llu \n",*pivot,arr[*pivot],partition,start,end);
    /* choose pivot also does partitioning */
    if (start < end ) {
        for (i = start; i<=end ; i++ ) {
            if (i == *pivot) {
                continue;
            }
            if(swapper > arr[i]) {

                /*swap*/
                partition++;
                fprintf(output,"PartitionIndex = %llu value at partition = %llu, swapping with arr[%llu] = %lu\n",partition,arr[partition],i,arr[i]);
                temp = arr[partition];    
                arr[partition] = arr[i];
                arr[i] = temp;

            }
        }
        temp = arr[partition];
        arr[partition] = arr[*pivot];
        arr[*pivot]  = temp;
    }
    fprintf(output,"num_comparison = %llu current_partition = %d \n",num_comparison,partition);
#ifdef TEST
    dump_array(arr);
#endif
    *pivot = partition;
    return num_comparison;

}
uint64_t quicksort(uint64_t arr[], uint64_t length,uint64_t start, uint64_t end) {

    uint64_t num_comp = 0;
    uint64_t pivot = 0;
    if (start < end ) {
        num_comp += choose_pivot(arr,length,start,end,&pivot);
        fprintf(output,"After choose_pivot, pivot = %llu and value of arr at pivot = %llu \n",pivot,arr[pivot]);
        if (pivot!=start) {
            num_comp += quicksort(arr,pivot-start,start,pivot-1);
        }
        num_comp += quicksort(arr,end-pivot,pivot+1,end);
    }
    return num_comp;

}

int main(){
    FILE * fd;
    int i = 0;
#ifndef TEST
    uint64_t num_array[10000];
#else
    uint64_t num_array[10000];
#endif
    uint64_t comparisons = 0;

    output = fopen("out.txt","w");
#ifndef TEST
    fd = fopen("QuickSort.txt","r");
#else
    fd = fopen("test.txt","r");
#endif

#ifndef TEST
    for(i=0;i<10000;i++){
#else
    for(i=0;i<10;i++){
#endif
        fscanf(fd,"%llu\n",&num_array[i]);
#ifdef TEST
        fprintf(output,"%llu ",num_array[i]);
        
#endif
    }
    fprintf(output,"\n");
    /* close input file */
    fclose(fd);
#ifndef TEST
    comparisons = quicksort(num_array,10000,0,9999);
#else
    comparisons = quicksort(num_array,10,0,9);
#endif
    printf("Total comparisons = %llu\n",comparisons);
#ifdef TEST
    for(i=0;i<10;i++) {
        fprintf(output,"%llu ",num_array[i]);

    }
    fprintf(output,"\n");
#endif
    /*close debug file */
    fclose(output);


    return 0;
}
