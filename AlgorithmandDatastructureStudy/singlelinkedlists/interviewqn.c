// Interview - nS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// To execute C, please define "int main()"
#if 0 // stack with push,pop, max

struct _stack {
  unsigned int max[10];
  unsigned int maxn;
  unsigned int size;
  unsigned int array[10];
  
};

#define SUCCESS 0
#define FAILURE -1

typedef struct _stack st;

int push(st* stack , int value) {
  
  if(!stack || stack->size == 10) {
    
    return FAILURE;
  }
  
  stack->array[stack->size] = value;
  if((stack->size == 0)  || (value > stack->max[stack->maxn-1])) {
      stack->max[stack->maxn] = value;
       stack->maxn = stack->maxn +1 ;
  }

  stack->size ++;
  
  
  
  return SUCCESS;
  
}


unsigned int pop(st * stack ) {
  
  if(stack && (stack->size != 0)) {
    
      if(stack->array[stack->size - 1] == stack->max[stack->maxn - 1]) {
          stack->maxn -- ;
      }
      
      stack->size-- ;
    
      return (stack->array[stack->size]);
    
  }
  return FAILURE;
  
}


unsigned int get_max(st* stack, int *ret) {
  
    if(stack) {
      *ret = SUCCESS;
      return stack->max[stack->maxn -1];
      
      
    }
  *ret = FAILURE;
    return 0;
  
}

int main() {
  
  unsigned int max ;
  int ret = -1;
  st* stack  = (st*) malloc(sizeof(st));
  
  stack->size = 0;
  stack->maxn = 0;
  
  memset(stack->array,0,10*sizeof(int));
  memset(stack->max,0,10*sizeof(int));

  push(stack,10);
  push(stack,9);
  push(stack,8);
  push(stack,5);
  push(stack,15);
    push(stack,7);

  max = get_max(stack, &ret);
  if(ret == SUCCESS)
   printf("max = %u\n",max);
  
  printf("%u\n",pop(stack));
  
  max = get_max(stack, &ret);
  if(ret == SUCCESS)
   printf("max = %u\n",max);

  printf("%u\n",pop(stack));
  
  max = get_max(stack, &ret);
  if(ret == SUCCESS)
   printf("max = %u\n",max);

  
  
  return 0;
}


#endif

//rearrage ll so that always even comes first and odd comes last but order is maintained

//ll.  1 10 2 8 3 4
//ll   10 2 8 1 3 4




typedef struct ll {
  
  int val;
  struct ll *next;
  

} list;


list* create_node(list * head, int val){
  
      list * node = malloc(sizeof(list));
  
  
      if( node) {
        
        node->next = head;
        node->val = val;
        
      }
      
      return node;
  
}

list * rearrange(list * head) {
  
  list * odd =NULL;
  list * even = NULL;
  list * laste = NULL;
  list * lasto = NULL;

  while(head) {
    
    if(head->val % 2 == 0) {
       
       if(even == NULL)  {
           even = head;
           laste = even;
       }
       else {
         laste->next = head;
         laste = head;
       }
      
    }else {
      
      if(odd == NULL)  {
           odd = head;
           lasto = odd;
       }
       else {
         lasto->next = head;
         lasto = head;
       }
      
    }
    head = head->next;
    
  }
  
  laste ->next = odd;
  lasto -> next = NULL;

  return even;

  
}

int main() {
  
    list *head = NULL;
  
    list *temp ;
    
    head = create_node(head,4);

    head = create_node(head,3);
    head = create_node(head,8);
    head = create_node(head,2);
    head = create_node(head,10);
    head = create_node(head,1);

      temp = head;
    while(temp) {
      
      printf("%d -> ",temp->val);
      temp = temp->next;
      
    }
  
    printf("\nout\n");

    head = rearrange(head);
  
    temp = head;
    while(temp) {
      
      printf("%d -> ",temp->val);
      temp = temp->next;
      
    }
    
  
  return 0;
}





/* 
Your previous Plain Text content is preserved below:

This is just a simple shared plaintext pad, with no execution capabilities.

When you know what language you'd like to use for your interview,
simply choose it from the dropdown in the top bar.

You can also change the default language your pads are created with
in your account settings: https://app.coderpad.io/settings

Enjoy your interview!


//stack with push , pop and max


 */
