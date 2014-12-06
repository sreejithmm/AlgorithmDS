
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

struct edge{

	int source;
	int dest;
	int length;
}edge_st;

struct heap{

    struct edge_st* edge;

}heap;
