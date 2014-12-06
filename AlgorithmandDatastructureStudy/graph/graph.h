
typedef struct graphArrnode{
	int dest;
	int len;
	int pathLen;
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
