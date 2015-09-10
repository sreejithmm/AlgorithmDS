#include <stdio.h>

typedef struct node
{
  int val;
  struct node* next;
}

typedef struct _queue
{
   struct node * head;
   struct node * tail;
}queue;


void print_bins(int nums)
{
  int val=0;

  queue* q = createqueue();

  enqueue(q,1);
  while(nums--)
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
