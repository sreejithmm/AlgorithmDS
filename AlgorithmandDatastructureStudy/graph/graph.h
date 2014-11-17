
typedef struct graphArrnode{
	int dest;
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
	int strtidx;
	int endidx;
	int cap;
	int size;
}myqueue;
