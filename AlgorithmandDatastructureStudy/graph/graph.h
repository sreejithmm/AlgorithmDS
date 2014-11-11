
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
