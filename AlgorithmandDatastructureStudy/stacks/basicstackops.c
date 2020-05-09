#include <stdio.h>
#include "basicstackops.h"
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

mystackArray* createStackArray(unsigned int capacity)
{


    mystackArray *stack = (mystackArray*)malloc(sizeof(mystackArray));
    stack->array = (int*)malloc(sizeof(int)*capacity);
    stack->capacity = capacity;
    stack->top = -1;


    return stack;


}

int isEmptyArray(mystackArray* stack)
{

    return (stack->top == -1);
}
int isFullArray(mystackArray* stack)
{

    return (stack->top == ((stack->capacity)-1));
}
void pushArray(mystackArray *stack,int dat)
{

    if(isFullArray(stack)) {
        printf("stack is full\n");
    }
    else{
        (stack->top)++;
        stack->array[stack->top] = dat;
    }

}

int popArray(mystackArray* stack)
{
    int val;
    if(isEmptyArray(stack)){
        printf("stack is empty\n");
        return INT_MIN;
    }
    else
    {
        val = stack->array[stack->top];
        (stack->top)--;
        return val;

    }



}

int peekArray(mystackArray* stack)
{

    if(isEmptyArray(stack)){
        printf("stack is empty\n");
        return INT_MIN;
    }
    else
    {
        return stack->array[stack->top];

    }

}



void push(mystack** head,int dat)
{


    mystack *newnode = (mystack*)malloc(sizeof(mystack));
    newnode->val = dat;
    newnode->next = *head;
    *head = newnode;


}
int pop(mystack **head)
{

    int dat;
    mystack *tmp;
    if(isEmpty(*head))
    {
        printf("stack is empty. \n");
        return INT_MIN;
    }
    dat = (*head)->val;
    tmp = (*head)->next;
    free(*head);
    *head = tmp;
    return dat; 
}
int peek(mystack *head)
{

    int dat;
    if(isEmpty(head))
    {
        printf("stack is empty\n");
        return INT_MIN;
    }

    dat = head->val;
    return dat;


}
int isEmpty(mystack *head)
{

    return (head == NULL) ;


}
int prec(char ch)
{

    switch(ch)
    {

        case '+':
        case '-':
            return 1;
            break;
        case '*':
        case '/':
            return 2;
            break;
        case '^':
            return 3;
            break;

    }

 return -1;
}

int isOperand(char ch)
{

    int val;
    val= (ch>='a' && ch<='z') || (ch>='A' && ch<='Z');
    return val;

}

void inFixtoPostFix(char *exp)
{


    mystack *stack=NULL;

    int len,i;

    len = strlen(exp);
    

    for(i=0;i<len;i++)
    {


        if(isOperand(exp[i]))
        {
            
            printf("%c",exp[i]);

        }
        else
        {
            if(isEmpty(stack))
            {
                
                push(&stack,exp[i]);

            }
            else if(exp[i] == '(')
            {
                push(&stack,exp[i]);

            }
            else if(exp[i] == ')')
            {
                while(!isEmpty(stack) && peek(stack) != '(')
                {
                        
                    printf("%c",pop(&stack));

                }
                /*pop ( without printing it*/
                pop(&stack);
            }

            else if (prec(exp[i]) >= prec(peek(stack)))
            {

                push(&stack,exp[i]);

            }
                else{


                while((!isEmpty(stack)) && ( prec(exp[i])<= prec(peek(stack))))
                {
                    printf("%c",pop(&stack));
                }
                push(&stack,exp[i]);

            }

        }

    }

    while(!(isEmpty(stack)))
    {
        printf("%c",pop(&stack));
    }

    printf("\n");
}

int eval(int a,int b,char ch)
{

    switch(ch)
    {
        case '+':
            return a+b;
            break;
        case '-':
            return a-b;
         case '/':
            return a/b;
         case '*':
            return a*b;
         case '^':
            return a^b;
    }

}

postFixEval(char *exp)
{


    int len=0;
    int i=0;
    mystack *stack=NULL;
    int val1=0,val2;
    int result=0;

    len = strlen(exp);
    
    for(i=0;i<len;i++)
    {
        
        if(isdigit(exp[i]))
        {
            
            push(&stack,(exp[i]-'0'));

        }
        else {
            
            val2=(stack!=NULL)?(pop(&stack)):0;
            val1=(stack!=NULL)?(pop(&stack)):0;
            result = eval(val1,val2,exp[i]);
            push(&stack,result);
            

        }


    }
    printf("Final result of expression %s is %d\n",exp,pop(&stack));


}

mydstack* createDualStack(int capacity)
{


    mydstack *stacks = (mydstack *) malloc(sizeof(mydstack));
    stacks->array = (int*) malloc(sizeof(int) * capacity);

    stacks->size = capacity;
    stacks->top1 = -1;
    stacks->top2 = capacity;

}

int isFull1(mydstack* stack)
{

    if(stack->top1 >= (stack->top2-1))
    {
        return 1;
    }
    return 0;


}

int isFull2(mydstack* stack)
{

  if (stack->top2 <= stack->top1+1)
      return 1;
  
  return 0;

}

void push1(mydstack* stack,int val)
{
    
    
    if(isFull1(stack))
    {
            printf("Stack1 is full\n");
            return ;
    }
    stack->array[++stack->top1] = val;
    return;
    
}

void push2(mydstack* stack,int val)
{
    
    
    if(isFull2(stack))
    {
            printf("Stack2 is full\n");
            return ;
    }
    stack->array[--stack->top2] = val;
    return;
    
}

int isEmpty1(mydstack* stack)
{

    return (stack->top1 == -1);
}

int isEmpty2(mydstack* stack)
{

    return (stack->top2 == stack->size);

}
int pop1(mydstack *stack)
{

    int ret_val;
    if(isEmpty1(stack))
    {
            printf("stack1 is empty\n");
            return INT_MIN;
    }
    ret_val = stack->array[stack->top1];
    stack->top1--;

    return ret_val;

}

int pop2(mydstack *stack)
{

    int ret_val;
    if(isEmpty2(stack))
    {
            printf("stack1 is empty\n");
            return INT_MIN;
    }
    ret_val = stack->array[stack->top2];
    stack->top2++;

    return ret_val;

}
char matchof(char ch)
{

    switch (ch)
    {
        case '}':
            return '{';
        case ')':
            return '(';
         case ']':
            return '[';
         default:
            return '0';
    }

}
void checkifbalanced(char *expr)
{

    int len=0,i=0,x=0;
    mystack *stack=NULL;
    char ch;

    len = strlen(expr);
    for(i=0;i<len;i++)
    {

       
       switch(expr[i])
       {
           case '{':
           case '(':
           case '[':
               push(&stack,expr[i]);
               break;
           case '}':
           case ']':
           case ')':
                ch = pop(&stack);
               if(ch != matchof(expr[i]))
               {
                   printf("Not balanced\n");
                   return;
               }
               break;

       }
    }
       if( isEmpty(stack))
            printf("%s is balanced expression\n",expr);
       else
           printf("Not balanced:\n");
       return;

}

void checkNGE(int a[],int n)
{

    int i=0;
    mystack *stack=NULL;

    push(&stack,a[0]);
    for(i=1;i<n;i++)
    {
        if(a[i] <= peek(stack)|| isEmpty(stack))
        {
            push(&stack,a[i]);
        }
        else
        {
            
            while(!isEmpty(stack))
            {
            
                printf("NGE for %d is %d\n",pop(&stack),a[i]);

            }
            push(&stack,a[i]);
        }
        
    }
    while(!isEmpty(stack))
        printf(":NGE for %d is -1 \n",pop(&stack));

}

void printStack(mystack* stack)
{

    while(!isEmpty(stack))
    {

        printf("%d\n",stack->val);
        stack=stack->next;

    }



}
void insertatBottom(mystack **stack, int val)
{
    int temp;
    
    if(isEmpty(*stack))
     {
         push(stack,val);
         return;
     }
    else
    {

        temp = pop(stack);
        insertatBottom(stack,val);
        push(stack,temp);


    }



}

void reverseStack(mystack **stack)
{

    int temp;
    
    if(!isEmpty(*stack))
    {

        
        temp = pop(stack);
        reverseStack(stack);
        insertatBottom(stack,temp);


    }


}

void calculateSpan(int price[],int size,int span[])
{

    int i;
    mystack *stack=NULL;

    span[0] = 1;
    push(&stack,0);
    for(i=1;i<size;i++)
    {

        while((!isEmpty(stack)) && (price[peek(stack)] <= price[i]))
            pop(&stack);

        span[i] = isEmpty(stack)?i+1:(i-peek(stack));
        push(&stack,i);

    }




}



void pushSp(myspStack** spStack,int val)
{

    if(!(*spStack))
    {
            
            *spStack = (myspStack*)malloc(sizeof(myspStack));
            (*spStack)->Orgstack =NULL;
            (*spStack)->minstack=NULL;

            push(&((*spStack)->Orgstack),val);
            push(&((*spStack)->minstack),val);

    }
    else
    {
            push(&((*spStack)->Orgstack),val);
            if(val < peek(((*spStack)->minstack)))
            {
                push(&((*spStack)->minstack),val);
                
            }

    }

}

int popSp(myspStack *spStack)
{
    int val = -1;
    
    if(spStack)
    {

        if(isEmpty(spStack->Orgstack))
        {

            printf("Empty stack1\n");

        }
        else
        {

            val = pop(&(spStack->Orgstack));
            if (val == peek(spStack->minstack))
            {
                pop(&(spStack->minstack));
            }

         }

    }
    else
    {
        printf("Special stack is empty\n");
    }
    return val;

}

int getMinSp(myspStack *spStack)
{
    
    int val = -1;
    if(spStack)
    {


        if(isEmpty(spStack->Orgstack))
        {

            printf("Empty stack2\n");
        }
        else
        {
            val = peek((spStack->minstack));

        }
    }
    else
    {
            printf("Special stack is empty\n");
    }

     return val;

}



void push_to_setofstacks(setofstacks** stack,int value,int threshold)
{
	if(stack == NULL)
	{
		*stack = (setofstack*)malloc(sizeof(setofstack));
		(*stack)->threshold = threshold;

		(*stack)->head = (platestack*)malloc(sizeof(playstack));
		(*stack)->head->stack =(mystack*)malloc(sizeof(mystack));

		(*stack)->head->noofstacks =1
		(*stack)->head->stack->val = value;

		(*stack)->head->stack->next = NULL;
		(*stack)->curStack = head->stack;
		(*stack)->curstackItems = 1;
		

	}
	else
	{
		if((*stack)->curstackItems < (*stack)-
				>threshold)
		{
			
			mystack * temp = (mystack*)malloc(sizeof(mystack));
			temp->next = (*stack)->curStack;
			temp->val = value;
			(*stack)->curStack = temp;
			(*stack)->curstackItems += 1;


			
		}
		else
		{
			(*stack)->curstackItems = 1;
			mystack* temp =(mystack*)malloc(sizeof(mystack));
			

		}


	}





}

