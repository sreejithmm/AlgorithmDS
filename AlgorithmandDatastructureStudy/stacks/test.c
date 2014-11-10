#include <stdio.h>
#include "basicstackops.h"
#include <limits.h>
#include <stdlib.h>
#include <string.h>



int main()
{


    int choice,n=0,i=0,x=0;
    mystackArray* stack;
    mystack *Stack=NULL;
    mydstack *dstack;
    myspStack *spStack=NULL;
    char exp[100]={'\0'};
    int a[100];
    int s[100];
   do {
    printf("MENU\n");
    printf("****\n");
    printf("1.Create a stack using array\n");
    printf("2.push to array stack\n");
    printf("3.Pop from array stack\n");
    printf("4.Peek to array stack\n");
    printf("5.Create a stack\n");
    printf("6.Pop from stack\n");
    printf("7.Peek into a stack\n");
    printf("8.Infix to postfix conversion of an expression\n");
    printf("9.Postfix evaluation\n");
    printf("10.Create a dstack and do pop and push\n");
    printf("11.Check if an expression is balanced or not\n");
    printf("12.Check next greatest element in an array\n");
    printf("13.Reverse a stack\n");
    printf("14.Calculate span of a stock\n");
    printf("15.Create special stack which supports getMin\n");
    scanf("%d",&choice);
    memset(exp,'\0',100);
    switch(choice)
    {
            case 1:
                stack=(mystackArray*)createStackArray(5);
                pushArray(stack,1);
                pushArray(stack,2);
                pushArray(stack,3);
                pushArray(stack,4);
                pushArray(stack,5);
                pushArray(stack,6); /*should give error print*/
                break;
            case 2:
                printf("Not implemented\n");
                break;
            case 3:
                printf("Popping 3 items, Expecting 5 4 3\n");
                printf("%d\n",popArray(stack));
                printf("%d\n",popArray(stack));
                printf("%d\n",popArray(stack));
                break;
            case 4:
                printf("Peeking item\n");
                printf("%d\n",peekArray(stack));
                break;
            case 5:
               printf("Enter number of elements you want to push to stack\n");
               scanf("%d",&n);
               for(i=0;i<n;i++)
               {
                   printf("Enter value : ");
                   scanf("%d",&x);
                   push(&Stack,x);


               }
               break;
            case 6:
               printf("Pop top of stack\n");
               printf("%d\n",pop(&Stack));
               break;
            case 7:
               printf("Peeking top of stack\n");
               printf("%d\n",peek(Stack));
               break;
            case 8:
               printf("Enter the expression\n");
               scanf("%s",exp);
               inFixtoPostFix(exp);
               break;
            case 9:
               printf("Enter the expression\n");
               scanf("%s",exp);
               postFixEval(exp);
               break;
            case 10:
               printf("Enter the total size Dual stack you want to create\n");
               scanf("%d",&n);
               dstack = (mydstack* )createDualStack(n);
               printf("How many elements you want to push to stack1\n");
               scanf("%d",&n);
               for(i=0;i<n;i++)
               {
                   printf("Enter value:");
                   scanf("%d",&x);
                   push1(dstack,x);
                     
               }
               printf("How many elements you want to push to stack2\n");
               scanf("%d",&n);
               for(i=0;i<n;i++)
               {

                   printf("Enter value:");
                   scanf("%d",&x);
                   push2(dstack,x);
                     
               }
               printf("How many elements you want to pop out of stack1\n");
               scanf("%d",&n);
               for(i=0;i<n;i++)
               {
                
                   printf("Stack1:%d\n",pop1(dstack));
                    
               }
               printf("How many elements you want to pop out of stack2\n");
               scanf("%d",&n);
               for(i=0;i<n;i++)
               {
                
                   printf("Stack2:%d\n",pop2(dstack));
                    
               }
               break;


         case 11:
              printf("Enter the expression\n");
              scanf("%s",exp);
              checkifbalanced(exp);
              break;
         case 12:
              printf("Enter the number of elements in the array\n");
              scanf("%d",&n);
              for(i=0;i<n;i++)
              {

                printf("Enter value %d:",i);
                scanf("%d",&a[i]);
                   printf("\n");
              }
              checkNGE(a,n);
              break;
         case 13:
               printf("Enter number of elements you want to push to stack\n");
               scanf("%d",&n);
               Stack=NULL;
               for(i=0;i<n;i++)
               {
                   printf("Enter value : ");
                   scanf("%d",&x);
                   push(&Stack,x);


               }

               printf("\nOriginal Stack\n");
               printStack(Stack);
               reverseStack(&Stack);
               printf("Reversed Stack\n");
               printStack(Stack);
                break;

        case 14:
               printf("Enter the number of days\n");
               scanf("%d",&n);
               for(i=0;i<n;i++)
               {
                    
                   printf("Enter stock price for day%d\n",i);
                   scanf("%d",&a[i]);


               }

              printf("Calculating span...\n");
              calculateSpan(a,n,s);
              for(i=0;i<n;i++)
              {
                  printf("%d ",s[i]);
              }
              printf("\n");
              break;
        case 15:
               printf("Enter number of elements you want to push to stack\n");
               scanf("%d",&n);
               for(i=0;i<n;i++)
               {
                   printf("Enter value : ");
                   scanf("%d",&x);
                   pushSp(&spStack,x);

               }
               printf("Minimum of stack:%d\n",getMinSp(spStack));

               printf("Pop stack twice\n");
               printf("%d\n",popSp(spStack));
               printf("%d\n",popSp(spStack));

               printf("Minimum of stack:%d\n",getMinSp(spStack));
               break;

               

        
      }
    }while(1);


}
