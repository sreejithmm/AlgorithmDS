#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long uint64_t;
FILE * output;

//#define TEST 1
#define MEDIAN_



typedef struct graphArrnode{
	uint64_t dest;
	uint64_t len;
	uint64_t pathLen;
	struct graphArrnode* next;
}graphArrnode;

typedef struct graphArrList 
{
	graphArrnode * head;
}graphArrList;



typedef struct _graph{
	
	uint64_t num;
	graphArrList* ArrList;
	
}graph;

typedef struct {
	uint64_t *arr;
	uint64_t front;
	uint64_t rear;
	uint64_t cap;
	uint64_t size;
}myqueue;

typedef struct edge{

	uint64_t source;
	uint64_t dest;
	uint64_t length;
}edge_st;

typedef struct heap{

     edge_st* edge[100];
     uint64_t size;

}heap;

/* function definitions */
void addVertices (graph * gr, uint64_t src, uint64_t dest,uint64_t isDirected,uint64_t weight);
graph * createGraph (uint64_t nodes);
uint64_t getShortestPath(graph* gr, uint64_t origin,uint64_t destination);




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
