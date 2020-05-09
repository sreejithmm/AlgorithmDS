#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "basicqueue.h"

myqueuear* createQueueAr(int capacity)
{
    myqueuear *q=NULL;
    q = (myqueuear*)malloc(sizeof(myqueuear));
    q->front = q->size =0;
    q->rear = capacity-1;
    q->capacity = capacity;
    q->array = (int*) malloc(sizeof(int)*capacity);
    memset(q->array,0,capacity);
    return q;
}

int isFullQar(myqueuear* q)
{

    return (q->capacity == q->size);
}
int isEmptyQar(myqueuear* q)
{

   return (q->size == 0);
}

void enqueueAr(myqueuear *q,int val)
{

    if(isFullQar(q))
    {
        printf("enqueueAr: Queue is full\n");
        return;
    }
    q->rear = (q->rear+1)%(q->capacity);
    q->array[q->rear]=val;
    q->size +=1;
    return;

}

int dequeueAr(myqueuear *q)
{
    int temp;

    if(isEmptyQar(q))
    {

        printf("dequeueAr: Queue is empty\n");
        return INT_MIN;
    }
    temp = q->array[q->front];
    q->front = (q->front +1) % (q->capacity);
    q->size -=1;
    return temp;

}
int getFrontQAr(myqueuear *q)
{

    if(isEmptyQar(q))
    {
        
        printf("getFrontQAr: Queue is empty\n");
        return INT_MIN;
    }
    return (q->array[q->front]);

}
int getRearQAr(myqueuear* q)
{
    if(isEmptyQar(q))
    {
        
        printf("getRearQAr: Queue is empty\n");
        return INT_MIN;
    }
    return (q->array[q->rear]);


}

myqueue* createQueue()
{

    myqueue* q= (myqueue*)malloc(sizeof(myqueue));
    q->rear=NULL;
    q->front = NULL;
    return q;

}

void enqueue(myqueue *q,int dat)
{

   struct queue_node *node=NULL;

   if (q==NULL)
   {
       printf("Create Q first. Q is NULL\n");
       return ;
   }
   node = (struct queue_node*)malloc(sizeof(struct queue_node));
   node->next = NULL;
   node->data = dat;
   if (q->rear == NULL)
   {

        q->rear = node;
        q->front = q->rear;
   }else
   {

        q->rear->next =  node;
        q->rear = node;
   }


}

int dequeue(myqueue *q)
{

    int temp;
    struct queue_node *node;
    if(q==NULL)
    {

        printf("Create Q first. Q is NULL\n");
        return INT_MIN;
    }
    if(q->front == NULL)
    {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    node = q->front;
    temp = node->data;

    q->front = q->front->next;
    free(node);
    node = NULL;
    if(q->front == NULL)
    {
        q->rear=NULL;
    }

    return temp;


}


void push(mystack** stack,int val)
{

    mystack *node = (mystack *)malloc(sizeof (mystack));
    node->next = *stack;
    node->val = val;
    *stack = node;

}
int pop(mystack **stack)
{
    mystack *node;
    int val;

    if(*stack == NULL)
    {
            printf("Stack is empty \n");
            return INT_MIN;
    }
    node = *stack;
    val = node->val;
    *stack = (*stack)->next;
    free(node);
    node = NULL;
    return val;


}

stackqueue *createstackqueue()
{
    stackqueue *q = (stackqueue*)malloc(sizeof(stackqueue));
    
    q->stack1 = NULL;
    q->stack2 = NULL;

    return q;
}

void enqueueSt(stackqueue *q,int val)
{
    
    if(q==NULL)
    {
            printf("Empty Q/Create Q first\n");
            return;
    }

    push(&(q->stack1),val);

}

int dequeueSt(stackqueue *q)
{
    int val;

    if(q== NULL)
    {
        printf("Empty Q/Create Q first\n");
        return INT_MIN;
    }
    if(q->stack1 == NULL)
    {
        if(q->stack2 == NULL)
        {
                printf("Queue is empty ...no elemnets to dequeue\n");
                return INT_MIN;
        }
        else{

              val = pop(&(q->stack2));
        }

    }
    else{
        if(q->stack2 == NULL)
        {
            while((q->stack1) != NULL)
                push(&(q->stack2),pop(&(q->stack1)));

        }
        val = pop(&(q->stack2));
    }

    return val;

}

int findStart(petrolst a[], int n)
{

    int start = 0;
    int end  =1;
    int currpetrol = a[start].petrol - a[start].distance;

    while(start != end || currpetrol < 0)
    {

        while(start!=end && currpetrol < 0)
        {
            currpetrol -= a[start].petrol - a[start].distance;
            start = (start+1)%n;
            if(start == 0)
            {
                return -1;
            }

        }
        currpetrol += a[end].petrol -a[end].distance;
        end = (end+1) %n;

    }
    return start;

}

mystrqueue *createStrQueue()
{

    mystrqueue* q = (mystrqueue*) malloc(sizeof(mystrqueue));
    q->rear = NULL;
    q->front = NULL;
    return q;
}
void enqueuestr(mystrqueue *q,char* dat)
{

   struct queue_node_str *node=NULL;
   int len= strlen(dat);

   if (q==NULL)
   {
       printf("Create Q first. Q is NULL\n");
       return ;
   }
   node = (struct queue_node_str*)malloc(sizeof(struct queue_node_str));
   node->next = NULL;

   node->str = (char*)malloc(len+1);
   memset(node->str,'\0',len+1);
   strncpy(node->str,dat,len);

   if (q->rear == NULL)
   {

        q->rear = node;
        q->front = q->rear;
   }else
   {

        q->rear->next =  node;
        q->rear = node;
   }


}

char* dequeuestr(mystrqueue *q)
{

    char* temp;
    struct queue_node_str *node;
    int len ;
    if(q==NULL)
    {

        printf("Create Q first. Q is NULL\n");
        return NULL;
    }
    if(q->front == NULL)
    {
        printf("Queue is empty\n");
        return NULL;
    }
    node = q->front;
    len=strlen(node->str);
    temp =  (char*)malloc(len+1);
    memset(temp,'\0',len+1);
    strncpy(temp,node->str,len);

    q->front = q->front->next;
    free(node->str);
    free(node);
    node = NULL;
    if(q->front == NULL)
    {
        q->rear=NULL;
    }

    return temp;

}



void printBinary(unsigned int n)
{


  mystrqueue *q = createStrQueue();
  
  char s[100];
  char t[100];
  memset(s,'\0',100);
  memset(t,'\0',100);

  enqueuestr(q,"1");

   while(n--)
   {
       strcpy(s,dequeuestr(q));
       strcpy(t,s);
       
       printf("%s\n",s);
        
       strcat(s,"0");
       enqueuestr(q,s);
       strcat(t,"1");
       enqueuestr(q,t);

   }


}

