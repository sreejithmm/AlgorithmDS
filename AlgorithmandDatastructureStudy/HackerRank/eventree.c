/*
 *
 * https://www.hackerrank.com/challenges/even-tree
 * 
 */

#include <stdio.h>
#include <limits.h>
#include <strings.h>
#include <stdlib.h>
#include <assert.h>

typedef unsigned long long ULL;

typedef struct graphArrnode{
	int dest;
	int len;
	int back;
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

enum {
	false ,
	true
};

int maxevenchildren=0;
FILE* fd;

graph * createGraph (int nodes)
{
  int i = 0;
  graph *gr = (graph *) malloc (sizeof (graph));
  gr->num = nodes+1;
  gr->ArrList = (graphArrList *) malloc ((nodes+1) * sizeof (graphArrList));
  for (i = 0; i < nodes+1; i++)
    {
      gr->ArrList[i].head = NULL;
    }
	return gr;
}

void addVertices (graph * gr, int src, int dest,int isDirected,float weight)
{
  graphArrnode *node = NULL;

  if (gr == NULL)
    {
      return;
    }

  if (gr->num == 0)
    {
      return;
    }
  if (gr->ArrList == NULL)
    {
      gr->ArrList = (graphArrList *) malloc (gr->num * sizeof (graphArrList));
    }

  node = (graphArrnode *) malloc (sizeof (graphArrnode));
  node->dest = dest;
  node->len = (int)weight;
  node->back=0;
  node->next = gr->ArrList[src].head;
  gr->ArrList[src].head = node;

  if(!isDirected) 
  {
  	node = (graphArrnode *) malloc (sizeof (graphArrnode));
	node->dest = src;
        node->len = (int)weight;
	node->back=0;
        node->next = gr->ArrList[dest].head;
        gr->ArrList[dest].head = node;
  }


}
void init()
{
	fd = fopen("case.txt","r");

}
int readInt()
{
	int a;
	fscanf(fd,"%d",&a);

	return a;
}
void printGraph (graph * gr)
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

int doDFS(graph* gr, int vert, int arr[])
{
	int forwardlen=0;
	graphArrnode* node;
	arr[vert] = 1;
	int evenchildren=0;
	int children;
	int numnodes = 0;
	node = gr->ArrList[vert].head;
	while(node !=NULL)
	{
		if(arr[node->dest] ==0)
		{
			forwardlen=doDFS(gr,node->dest,arr);
			if((forwardlen) !=0 && (forwardlen%2)==0)
			{
				maxevenchildren++;
			}
			else
			{
				numnodes+=forwardlen;
			}
		}
		node = node->next;
	}
	
	return (numnodes+1);
        
}


void graph_doDFS(graph* gr, int origin)
{
   
	int *arr = (int*)calloc(gr->num,sizeof(int));
	bzero(arr,gr->num*sizeof(int));
	doDFS(gr,origin,arr);
#ifdef DEBUG
	printf("\n");
#endif


}



int findNoOfEdgesToRemove(graph* g)
{
	
	if(g==NULL)
		return 0;

	graph_doDFS( g, 1);

	return maxevenchildren;


		
		
}

int main()
{
	int nV, nE;
	int v1,v2;
	int ed;
	int i;

	graph* g;
#ifdef FILE_INPUT
	init();
	nV = readInt();
	nE = readInt();
#else
	scanf("%d",&nV);
	scanf("%d",&nE);
#endif
	g= createGraph(nV);
	
	assert(g!=NULL);

	for(i=0;i<nE;i++){
#ifdef FILE_INPUT
		v1=readInt();
		v2 = readInt();
#else
		scanf("%d %d",&v1,&v2);
#endif
		addVertices(g,v1,v2,0,0.0);
	}

#ifdef DEBUG
	printGraph(g);
#endif

	ed = findNoOfEdgesToRemove(g);
	printf("%d\n",ed);

}
