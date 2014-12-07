
typedef struct graphArrnode{
	int dest;
	float len;
	float pathLen;
	struct graphArrnode* next;
}graphArrnode;

typedef struct graphArrList 
{
	graphArrnode * head;
}graphArrList;



typedef struct _graph{
	
	int num;
	graphArrList* ArrList;
	
}graph;

typedef struct {
	int *arr;
	int front;
	int rear;
	int cap;
	int size;
}myqueue;

typedef struct edge{

	int source;
	int dest;
	int length;
}edge_st;

typedef struct heap{

     edge_st* edge[100];
     int size;

}heap;

/* function definitions */
void
addVertices (graph * gr, int src, int dest,int isDirected,float weight);graph * createGraph (int nodes);
float getShortestPath(graph* gr, int origin,int destination);



