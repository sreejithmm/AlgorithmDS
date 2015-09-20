#include <stdio.h>
#include <assert.h>

typedef struct node
{
  int val;
  struct node* next;
}NODE;

typedef struct _queue
{
   struct node * head;
   struct node * tail;
}queue;


queue* createqueue()
{
  queue* myq;

  myq = (queue*)malloc(sizeof(queue));
  assert(myq);
  myq->head = NULL;
  myq->tail = NULL;

  return myq;

}

int dequeue(queue* myq)
{
  queue* next;
  int val;

  assert(myq);

  assert(myq->head);

  next = myq->head;
  val = myq->head->val;

  if (myq->head->next == NULL)
  {
    myq->head = NULL;
    myq->tail = NULL;
  }

  free(next);

}


void enqueue(queue* myq, int val)
{
  NODE* node;

  assert(myq);
  node = (NODE*)malloc(sizeof(NODE));
  node->val = val;
  node->next = NULL;

  if(myq->head== NULL)
  {
    myq->head = node;
    myq->tail = node;
  } 
  else
  {
    myq->tail->next = node;
    myq->tail = node;
  } 
  return;

}

int isEmpty(queue* myq)
{
  if(myq->head == NULL)
    return 1;
  else
    return 0;
}

void print_bins(int nums)
{
  int val=0;

  queue* q = createqueue();

  enqueue(q,1);
  while(nums-- && !isEmpty(q))
  {
      val = dequeue(q);


      printf("%d\n",val);

      enqueue(q,val*10);
      enqueue(q,val*10+1);
  }
}


int main()
{
  int nums=0;
  printf("Enter the number of numbers")
  scanf("%d",&nums);

  printf("Binary numbers till Nums \n");
  print_bins(nums);
  pritnf("----------------\n")
  return 0;
}
