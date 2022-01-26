/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>>

struct list {
    int val;
    struct list* next;
};

typedef struct list LIST;

static void push(LIST**head , int value)
{
    LIST* newnode = (LIST*)malloc(sizeof(LIST));
    if(newnode){
        newnode->val = value;
        newnode->next = *head;
        *head = newnode;
    }else{
        return ;
    }
    return;
}
static void printList(LIST* head)
{
    if(head){
        while(head){
            printf("%d ",head->val);
            head = head->next;
        }
    }
    printf("\n");
}
static void reverse(LIST** head)
{
    LIST *current,*prev,*next;
    current = *head;
    next = NULL;
    prev = NULL;
    
    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    
}
int main()
{
    printf("Hello World\n");
    LIST* head = NULL;
    push(&head , 20);
    push(&head , 200);
    push(&head , 10);
    push(&head , 25);

    printf("%p\n", head);

    printList(head);
    printf("%p\n", head);
    reverse(&head);
    printList(head);

    return 0;
}
