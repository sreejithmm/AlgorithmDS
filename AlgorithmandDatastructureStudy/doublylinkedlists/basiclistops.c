#include <stdio.h>
#include "header.h"
#include <stdlib.h>

static mylist* ListPivotandSwap(mylist* l,mylist* h);

void push(mylist **head,int dat)
{


    mylist *node = (mylist*) malloc(sizeof(mylist));

    node->data =dat;
    node->next = (*head);

    if( *head != NULL)
    {
      node->prev= (*head)->prev;
     (*head)->prev = NULL;
    }
    else
    {
      node->prev = NULL;
    }

    *head = node;

}
void print_node(mylist *node)
{

    if(node == NULL)
    {
        printf("Empty list\n");
    }
    else
    {
       printf("%p:%d\n",node,node->data); 
    }
    return;
}

void InsertAfter(mylist **head, int dat)
{

    mylist *node =(mylist*) malloc(sizeof(mylist));

    node->data=dat;
    node->prev = (*head);

    if(head != NULL)
    {
        node->next = (*head)->next;
        if(node->next != NULL)
             node->next->prev = node;
       (*head)->next = node;
    }
    else
    {
        node->next = NULL;
        *head = node;
    }

}

void print_list(mylist *head)
{
    mylist *temp = head;
    mylist *prev;
    if (head == NULL)
        return;

    printf("List in Forward Direction\n");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    
    while(temp!=NULL)
    {
           print_node(temp);
           prev=temp;
           temp=temp->next;
    }

    printf("List in Reverse\n");
    printf("^^^^^^^^^^^^^^^\n");
    while(prev!=NULL)
    {
        print_node(prev);
        prev=prev->prev;

    }

}

mylist* create_list(int num)
{
    mylist *head=NULL;
    mylist **headref=&head;
    int val;
    
    if (num == 0)
        return NULL;

    printf("Enter the member value\n");
    scanf("%d",&val);
    push(&head,val);
    printf("%p\n",head);
    printf("%p\n",*headref);
    num--;

    while(num != 0)
    {
        
        printf("Enter the member value\n");
        scanf("%d",&val);
        InsertAfter(headref,val);
        printf("%p\n",head);
        printf("%p\n",*headref);
        headref=&((*headref)->next);
        num--;
    }
    printf("%p\n",*headref);

    return head;

}


void deleteNode(mylist **head,mylist *node)
{


    mylist *temp = *head;
    mylist *prev = NULL;
    mylist **headref = head;

    while((*headref) != node)
    {
        prev=(*headref);
        headref = &((*headref)->next);

    }

    if((*headref)->next != NULL)
    {
       (*headref)->next->prev = prev;
    }
    if((*headref)->prev != NULL)
    {
         free((*headref));
         prev->next = (*headref)->next;  
    }
    else
    {
        *head = (*headref)->next;
    }
    
}


void reverse(mylist **head)
{


    mylist *temp=NULL;
    mylist *current = *head;


    while(current != NULL)
    {
        
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;

    }
    if(temp != NULL)
        *head = temp->prev;


}

void printCopyArbitList()
{



    mylist *head=NULL,*temp, *copyhead=NULL,*temp2;
    int count;
    mylist* arr[5]={NULL};
    int i;

    head = create_list(5);
    printf("Original List\n");
    print_list(head);


    head->next->next->next->prev = head->next;
    head->next->prev = head->next->next;
    head->next->next->prev = head;

    printf("Tweaked arbitrary list\n");
    print_list(head);
   
    temp = head;

    /*create a copy list, store the next links, and establish relation 
    * between original and copied list thorugh copied lists prev pointer
    */

    push(&copyhead,head->data);
    temp2=copyhead;
    arr[0] = temp->next;
    temp2->prev = temp;
    temp->next = temp2;
    temp=arr[0];
    i = 1;
    while(temp!= NULL)
    {
        InsertAfter(&temp2,temp->data);        

        temp2=temp2->next;
        temp2->prev = temp;
        arr[i] = temp->next;
        temp->next = temp2;
        temp=arr[i];
        i++;
        
    }
    /*restore the heads back to temp variable*/
    temp2=copyhead;
    temp=head;

    /*go through the list again to establish arbitrary pointer 
    * for the copied list
    */
    while(temp2!=NULL)
    {
        /* handling the first node */
        if(temp2->prev->prev == NULL){
            temp2->prev = NULL;
        }
        else{
        temp2->prev = temp2->prev->prev->next;
        }
        temp2=temp2->next;

    }
    /*restore next pointers of original list */
    i= 0;
    while(temp!=NULL)
    {

        temp->next = arr[i];
        temp = temp->next;
        i++;

    }

    /* print original and copied list */
    printf("ORIGINAL\n");
    print_list(head);
    printf("COPIED\n");
    print_list(copyhead);


    return;
}

void QuickSort(int arr[],int l,int h)
{

    int p;
    if (l>=h)
        return;
    p =findPivotandSwap(arr,l,h);
    QuickSort(arr,l,p-1);
    QuickSort(arr,p+1,h);
    return;
}

int findPivotandSwap(int a[],int l,int h)
{

    int pivot = a[l];
    int i= l;
    int j = h;
    int t;
    int k;
    printf("\ninput arg: l=%d h=%d\n",l,h);
    for(;;)
    {

        while(a[i] <= pivot && i < h)
        {
            i++;
        }
        while(a[j] > pivot   )
        {
            j--;
        }
        if (i >=j)
        {
            printf("i = %d j= %d\n",i,j);
            break;
        }
        
        printf("\nSwapping %d and %d\n",a[j],a[i]);
        t= a[j];
        a[j] = a[i];
        a[i] = t;

    }
    t= a[j];
    a[j] = a[l];
    a[l] = t;
    printf("\nfindPivotandSwap:return %d\n",j);
    for(k=l;k<=h;k++)
    {
        printf("%d ",a[k]);

    }
    printf("\n-----\n");
    return j;

}

void listQuickSort(mylist* l, mylist *h)
{

    mylist *p;

    if ((h==NULL) || (l==h) ||(l == h->next))
        return;
    
    p = ListPivotandSwap(l,h);
    listQuickSort(l,p->prev);
    listQuickSort(p->next,h);
    return;
}


static mylist* ListPivotandSwap(mylist* l,mylist* h)
{

    mylist* pivot = h;
    mylist* i = l->prev;
    mylist* j= l;
    int t;

    for(j=l;j!=h;j=j->next)
    {

        if(j->data<=pivot->data)
        {
            
            i=(i==NULL)?l: i->next;
            t=j->data;
            j->data=i->data;
            i->data = t;
            
        }


    }

    i = (i==NULL)?l:i->next;
    t = i->data ;
    i->data = pivot->data;
    pivot->data = t;
    
    return i;

}

/*swap kth node from beginning with kth node from end*/

void swapKth(mylist** head,int k)
{




}


