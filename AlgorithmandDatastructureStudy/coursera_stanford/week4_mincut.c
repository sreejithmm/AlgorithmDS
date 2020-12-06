#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <errno.h>
#include <string.h>

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
void
addVertices (graph * gr, int src, int dest,int isDirected,float weight)
{
  graphArrnode *node = NULL;

  if (gr == NULL){
      return;
   }

  if (gr->ArrList == NULL) {
      gr->ArrList = (graphArrList *) malloc (gr->num * sizeof (graphArrList));
   }

  node = (graphArrnode *) malloc (sizeof (graphArrnode));
  node->dest = dest;
  node->len = weight;
  node->pathLen=0;
  node->next = gr->ArrList[src].head;
  gr->ArrList[src].head = node;

  if(!isDirected) 
  {
  	node = (graphArrnode *) malloc (sizeof (graphArrnode));
	node->dest = src;
        node->len = weight;
	node->pathLen=0;
        node->next = gr->ArrList[dest].head;
        gr->ArrList[dest].head = node;
  }


}

void
printGraph (graph * gr)
{
  int i;
  graphArrnode *temp;

  if (gr == NULL)
    {
      return;
    }
  if (gr->num == 0)
    {
      printf ("Nothing to print\n");
    }
  if (gr->ArrList == NULL)
    {
      printf ("ERR..No adjacency list found\n");
      return;
    }
  for (i = 0; i < gr->num; i++)
    {
      temp = gr->ArrList[i].head;
      printf ("\n");
      printf ("%d :", i);
      while (temp != NULL)
	{

	  printf ("%d ", temp->dest);
	  temp = temp->next;
	}
    }
  return;

}

graph* create_graph(graph*gr , int num_size, FILE* fd){

    char *buffer = NULL;
    int i ;
    unsigned int line = 0;
    char strnum[4] = {'\0'};
    int l = 0;
    size_t size = 1000;
    int lsize = 0;
    


    unsigned long index = 0;
    char* endptr;

    if(gr == NULL) {
        fprintf(output,"NULL graph sent\n")
        return NULL;
    }
    
    gr->num = num_size; 
    buffer = (char*) malloc(1000 * sizeof(char));
    do{
        lsize = getline(&buffer,&size,fd);

        fprintf(output,"%s\n",buffer);

    
        for(i=0; 1==sscanf(buffer + i, "%s%n", strnum, &l); i = i + l){
            fprintf(output,"%s ",strnum);
            index  = strtol(strnum,&endptr,10);
        }

        fprintf(output,"\n");
    } while(lsize > 0) ;



    return NULL;
}








int main(){
    FILE * fd;
    int i = 0;
    graph * gr = NULL;
#ifndef TEST
    uint64_t num_array[10000];
#else
    uint64_t num_array[10000];
#endif
    uint64_t comparisons = 0;

    output = fopen("out.txt","w");
#ifndef TEST
    fd = fopen("week4_mincut.txt","r");
#else
    fd = fopen("test.txt","r");
#endif


    /* read mincut.txt to graph*/
    /* first node is going to be 
        free in this case */

    gr = (graph*)malloc(sizeof(graph)*201);

    gr = create_graph(gr,201,fd);

    fprintf(output,"\n");
    /* close input file */
    fclose(fd);
    fclose(output);


    return 0;
}
