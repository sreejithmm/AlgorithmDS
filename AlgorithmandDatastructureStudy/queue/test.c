#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "basicqueue.h"


int
main ()
{

  int i, x, j, n;
  int choice;
  myqueuear *qar;
  myqueue *q;
  stackqueue *qst;

  while (1)
  {
      printf ("MENU \n");
      printf ("*****\n");
      printf ("1.Perform Queue operations(implemented using array\n");
      printf ("2.Perform Queue operations(implemented using linkedlist\n");
      printf ("3.Perform Queue operations(implemented using stacks\n");
      printf ("4.Petrol problem\n");
      printf ("5.Print binary numbers before a number\n");
      scanf ("%d", &choice);
      i=0;
      j=0;
      x=0;
      n=0;
      switch (choice)
	  {
	  case 1:
	      printf ("Enter the capacity of queue\n");
    	  scanf ("%d", &n);
    	  qar = (myqueuear*)createQueueAr (n);
	      printf ("Enter the number of elements to be queued\n");
    	  scanf ("%d", &n);
	      for (i = 0; i < n; i++)
          {
	          printf ("enter the value %d:", i);
    	      scanf ("%d", &x);
	          enqueueAr (qar, x);
          }
    
	      printf ("Front of queue:%d\n", getFrontQAr (qar));
    	  printf ("Rear of queue:%d\n", getRearQAr (qar));
    
	      printf ("Enter the number of elements to be queued\n");
    	  scanf ("%d", &n);
    	  for (i = 0; i < n; i++)
	      {
              j = dequeueAr (qar);
              if (j!=INT_MIN)
    	          printf ("[%d]: %d\n", i, j);
    	  }
	      break;
       case 2:
    	  q = (myqueue*)createQueue();
	      printf ("Enter the number of elements to be queued\n");
    	  scanf ("%d", &n);
	      for (i = 0; i < n; i++)
          {
	          printf ("enter the value %d:", i);
    	      scanf ("%d", &x);
	          enqueue (q, x);
          }
    
    
	      printf ("Enter the number of elements to be dequeued\n");
    	  scanf ("%d", &n);
    	  for (i = 0; i < n; i++)
	      {
              j = dequeue (q);
              if (j!=INT_MIN)
    	          printf ("[%d]: %d\n", i, j);
    	  }
	      break;
        
      case 3:
          qst = (stackqueue*)createstackqueue();
	      printf ("Enter the number of elements to be queued\n");
    	  scanf ("%d", &n);
	      for (i = 0; i < n; i++)
          {
	          printf ("enter the value %d:", i);
    	      scanf ("%d", &x);
	          enqueueSt (qst, x);
          }
    
    
	      printf ("Enter the number of elements to be dequeued\n");
    	  scanf ("%d", &n);
    	  for (i = 0; i < n; i++)
	      {
              j = dequeueSt (qst);
              if (j!=INT_MIN)
    	          printf ("[%d]: %d\n", i, j);
    	  }
	      break;
      case 4:
          printf("Petrol pump problem\n");
          petrolst ptrol[] = {{6, 4}, {3, 6}, {7, 3}};
          int n = sizeof(ptrol)/sizeof(ptrol[0]);
          i=findStart(ptrol,n);
          (i==-1)?printf("No solution\n"):printf("Solution = %d\n",i);
          break;

     case 5:
          printf("Enter the number\n");
          scanf("%d",&n);
          printBinary(n);
          break;

          




	 }
  }

}
