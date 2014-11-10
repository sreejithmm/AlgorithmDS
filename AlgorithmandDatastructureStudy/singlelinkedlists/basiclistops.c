#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "basiclistops.h"

mylist* create_list(int num)
{
    int dat,idx=0;
mylist *head=NULL;
mylist *node;
mylist *prev=NULL;

printf("Entry: Create_list\n");

while(idx <num)
{

    printf("Enter data\n");
    scanf("%d",&dat);
    node=(mylist*)malloc(sizeof(mylist));
    assert(node);
    printf("Created node%d:%p\n",idx,node);
    node->ptr=(int*)malloc(sizeof (int));
    assert(node->ptr);
   *(node->ptr) = dat;
    node->next=NULL;

   if(idx==0) head=node;
    if(prev) {
       
        prev->next = node;

    }
        prev=node;
    idx ++;

}

    return head;

}


mylist* create_looped_list(int num) 
{
    int dat,idx=0;
mylist *head=NULL;
mylist *node;
mylist *prev=NULL;
mylist *temp;

printf("Entry: Create_looped_list\n");

while(idx <5)
{

    printf("Enter data\n");
    scanf("%d",&dat);
    node=(mylist*)malloc(sizeof(mylist));
    assert(node);
    printf("Created node%d:%p\n",idx,node);
    node->ptr=(int*)malloc(sizeof (int));
    assert(node->ptr);
   *(node->ptr) = dat;
    node->next=NULL;

   if(idx==0) head=node;
    if(prev) {
       
        prev->next = node;

    }
       prev=node;
    if(idx==2) {

        temp = node;

    }
    if(idx==4) {

        //loop to 2
        node->next=temp;

    }
    idx ++;
}
    return head;



}
void disp_list(mylist* node) {

    if(node==NULL)
    {
        printf("Empty list\n");
        return;
    }
    while(node!=NULL)
    {
        printf("%d\n",*(node->ptr));
        node=node->next;
    }

}

int rem_node_by_index(int idx,mylist** head)
{

   mylist *temp=*head;
   mylist *prev=*head;
   int cntr=0;

   if(idx==0)
   {
       *head=(*head)->next;
       free(temp);
       goto END;
   }


   while(cntr<idx && temp!=NULL){
      
       prev=temp;
       temp=temp->next;
       cntr++;

   }
   if(temp==NULL)
   {

       printf("No such node:ERR\n");
       return 0;
   }


   prev->next=temp->next;
   free(temp);
 END:
   return 1;

}


void free_my_list(mylist** head)
{

mylist* temp=(*head);

if(*head == NULL) return;

do {
    *head=temp;
    printf("Free:%p\n",*head);
    free((*head)->ptr);
    temp=(*head)->next;
    free(*head);
    *head=NULL;
    
}while(temp);
printf("Freed:\n");
return;

}

void print_reverse(mylist* head) {


    if(head!=NULL) {
        print_reverse(head->next);
    }
    else {
       return;
    }
    printf("%d\n",*(head->ptr));

    return;
    

}

int find_length_of_list(mylist *head)
{

    int len=0;
    while(head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;



}

void rem_node_by_addr(mylist** node) {

        
    mylist* temp;

    if((*node)->next)
    {
        (*node)->ptr = (*node)->next->ptr;
        temp = (*node)->next;
        (*node)->next = ((*node)->next->next);
        free(temp);
   
    }
    else{

           printf("Last node cant be deleted from a singly linked list\n");
    }



}

mylist* find_middle_node(mylist* head) {

    mylist* ptr1=head;
    mylist* ptr2=head;


    assert(head);


    while((ptr2!=NULL) && (ptr2->next!=NULL))
    {
        ptr1=ptr1->next;
//        ptr2=(ptr2->next)?ptr2->next->next:NULL;
        ptr2=ptr2->next->next;
    }

        return ptr1;

}


void print_node(mylist* node) {

    printf("%d\n",*((node)->ptr));
    return;
}

int checkif_loop_exist(mylist* head) {

    mylist* ptr1=head;
    mylist* ptr2=head;

    assert(head);

    while(ptr2) {

    ptr1=ptr1->next;
    ptr2=(ptr2->next)?ptr2->next->next:NULL;
    if(ptr1==ptr2)
        return 1;

    }
    return 0;
}

void push_to_head(mylist **head,int val) 
{

    mylist* node;

    node= (mylist*)malloc(sizeof(mylist));
    assert(node);
    node->ptr=(int*)malloc(sizeof(int));
    assert(node->ptr);


    *(node->ptr)=val;

    if(head==NULL)
    {
        /* creating a newlist*/
        node->next=NULL;

        *head=node;
    }
    else
    {
        node->next= (*head);
        (*head)=node;
    }


}

void reverse_list(mylist** head)
{
    mylist *curr,*prev,*next;
    curr=(*head);
    prev = NULL;

    if(curr == NULL)
    {
        printf("Invalid list.Head is null\n");
        return;

    }
    while(curr != NULL){
        
        next = curr->next;
        curr->next =prev;
        prev=curr;
        curr =next;

    }
    
    (*head) = prev;
    return;
    

}

#if 0
int check_palindrome(mylist* head)
{

   
     
     
     
     
     
     






}
#endif
void pop(mylist** head,int *val)
{
    mylist* temp;
    if(*head==NULL) 
    {
            printf("Nothing to pop\n");
            *val=0;
    }
    else
    {
        *val = *((*head)->ptr);
        temp = (*head)->next;
        free((*head)->ptr);
        free((*head));
        (*head)=temp;
    }
   return;

}
/* STU -06. Write a SortedInsert() function which given a list that is sorted
*  in increasing order, and a
*  single node, inserts the node into the correct sorted position in the list.
  */

void sortedInsert(mylist** head,mylist* node)
{

    mylist* dummy=NULL;

    push_to_head(&dummy,0); /* push to head will allocate a node and
                               return , since dummy is NULl */
    dummy->next=(*head);
//    (*headref)=dummy;
    while((dummy!=NULL) && (*((dummy)->next->ptr) < *(node->ptr)))
    {
        dummy = dummy->next;


    }
    node->next= dummy->next;
    dummy->next= node;
    *head = dummy->next;
    free(dummy->ptr);
    free(dummy);
}
void sortedInsert2(mylist **head,mylist *node)
{

//Implement using double pointer to  avoid using dummy and extra condition check.
    mylist **headref=head;

    while(((*headref)!=NULL) && *((*headref)->ptr) < *(node->ptr))
    {
        headref = &((*headref)->next);
//        disp_list(*headref);
    }
    node->next= (*headref);
    (*headref)=node;

}

/* Given  a list , change it to sorted order - STU-07 */
/*Write an InsertSort() function which given a list, rearranges its nodes so
* they are sorted in
* increasing order. It should use SortedInsert().
*/

void InsertSort(mylist **head)
{


    mylist* tmp = (*head)->next;
    mylist* det_node= (*head);
    (*head)->next =NULL;
    

    while((tmp != NULL) )
    {
        
        det_node = tmp;
        tmp = tmp->next;
        det_node->next = NULL;

        sortedInsert2(head,det_node);

    }
    
        printf("Exit Insert Sort\n");

}

/*STU 08:Write an Append() function that takes two lists, 'a' and 'b', appends
* 'b' onto the end of 'a',
* and then sets 'b' to NULL (since it is now trailing off the end of 'a').
*/


void Append(mylist** listA, mylist** listB)
{

    mylist *flptr=(*listA);
    mylist *slptr=(*listB);
    mylist *node =NULL;
    if(slptr ==NULL){

        printf("Do nothing - Second list is empty\n");
        return;

    }
    if(flptr ==NULL){

        *listA = *listB;
        return;

    }
    while(flptr->next !=NULL && flptr!=NULL)
    {
        flptr = flptr->next;

    }
    while(slptr!=NULL)
    {
        push_to_head(&node,*(slptr->ptr));
        if (flptr!=NULL) 
        {
            flptr->next=node;
        }
        flptr=node;
        node = NULL;
        slptr=slptr->next;

    }

}

/* STU 09
* Split the nodes of the given list into front and back halves,
* and return the two lists using the reference parameters.
* If the length is odd, the extra node should go in the front list.
* */
void FrontBackSplit(mylist* source,
        mylist** frontRef, mylist** backRef) {


    mylist *midnode;
    mylist *temp;
    mylist *node=NULL;
    mylist *frontHead,*backHead;
    int len = 0;

    midnode = find_middle_node(source);

//    print_node(midnode);
    temp = source;
    (*frontRef) = source;
    frontHead = (*frontRef);
    
    len = find_length_of_list(source);

    midnode = (len%2)?midnode->next:midnode;
    while(temp!=midnode)
    {
        temp = temp->next;
        (frontRef)= &((*frontRef)->next);
        
    }
    *frontRef=NULL;

   *backRef = temp;

}
    


/*STU 10:Write a RemoveDuplicates() function which takes a list sorted in increasing
* order and
* deletes any duplicate nodes from the list. Ideally, the list should only be
* traversed once.
*  Remove duplicates from a sorted list.   */
void RemoveDuplicates(mylist* head) 
{

   mylist* ref= head;
   mylist *temp;

   int comp = *(head->ptr);
   while(ref!=NULL && ref->next != NULL)
   {
        
       if(comp == *(ref->next->ptr))
       {
           temp = ref->next;
           ref->next = temp->next;
           free(temp->ptr);
           free(temp);
            
       }
       else {
           ref = ref->next;
           comp = *(ref->ptr);
       }

   }


}

/*
* STU 11:
* Take the node from the front of the source, and move it to
* the front of the dest.
* It is an error to call this with the source list empty.
*/

void MoveNode(mylist** destRef, mylist** sourceRef) {


    mylist *temp;

    if(*sourceRef== NULL)
    {
        return;
    }
    else
    {
        printf("Moving Node: ");
        print_node(*sourceRef);
        printf("\n");
        temp = (*sourceRef)->next;
        (*sourceRef)->next = (*destRef);
        (*destRef) = (*sourceRef);
        (*sourceRef) = temp;

    }
    return;

}
/*STU 12:
*Write a function AlternatingSplit() that takes one list and divides up its nodes to make
two smaller lists. The sublists should be made from alternating elements in the original
list. So if the original list is {a, b, a, b, a}, then one sublist should be {a, a, a} and the
other should be {b, b}. You may want to use MoveNode() as a helper. The elements in
the new lists may be in any order (for some implementations, it turns out to be convenient
if they are in the reverse order from the original list.)
*/
void AlternatingSplit(mylist* source,
        mylist** aRef, mylist** bRef)
{

    mylist *temp = source;
    mylist *tepaRef,*tempBref;
    int flag=-1;
    /* I expect it to be null, if it is not, I force it to become null */
  *aRef = NULL;
  *bRef = NULL;
   

   if(source == NULL){
        return;
        printf("Source is null.Unexpected\n");

   }
   while(temp !=NULL)
   {

    if(flag<0) {
        MoveNode(aRef,&temp);
    }
    else{
        MoveNode(bRef,&temp);
    }
         
       flag = flag*-1;

   }

}

/*STU13:
*Merge the nodes of the two lists into a single list taking a node
alternately from each list, and return the new list.
*/
mylist* ShuffleMerge(mylist* a, mylist* b) 
{

     /*
     mylist **newl=NULL,*temp;
     mylist *node=NULL, *try1=NULL;

     push_to_head(temp,0);
     *newl = temp;


    while( (a != NULL) || (b!=NULL))
    {
        
             push_to_head(node,*(a->ptr));
             temp->next = node;
             temp = temp->next;
             node = NULL;
             push_to_head(node,*(b->ptr));
             temp->next = node;
             temp = temp->next;
             node = NULL;
             a = a->next;
             b= b->next;

    }
    if(b==NULL) {
      try1 = a;
    
    }
    else if (a==NULL){
        try1=b;
    }
    while(try1 !=NULL){

              push_to_head(node,*(try1->ptr));
             temp->next = node;
             temp = temp->next;
             node = NULL;
             try1 = try1->next;

    }
   return ((*newl)->next)
   */

   mylist *head=NULL,*temp,*tempb;
   mylist **newl = &head;
    
   tempb=b;
   if(a == NULL)
        return b;
   else if(b == NULL)
       return a;
   else {
    
       head = a;
       while((a!=NULL)|| (b!=NULL)){
            
                temp = a->next;
                if(tempb == NULL)
                {
                    return head;
                }
                a->next = b;
                tempb= b->next;
                if (temp==NULL)
                {
                   return head;
                }
                b->next = temp;

                a= temp;
                b=tempb;
       } 


   }
   return head;


}



/*
* STU 14:
* Takes two lists sorted in increasing order, and
* splices their nodes together to make one big
* sorted list which is returned.
* */
mylist* SortedMerge(mylist* a, mylist* b) 
{
    /*

  mylist **newl=NULL,temp;
  mylist *node=NULL, *try1=NULL;

  push_to_head(temp,0);
  *newl = temp;


  while( (a != NULL) || (b!=NULL))
  {

      if( *(a->ptr)  < *(b->ptr)) 
      {

           push_to_head(node,*(a->ptr));
           temp->next = node;
           temp = temp->next;
           node = NULL;
           a = a->next;
      }else {
        push_to_head(node,*(b->ptr));
        temp->next = node;
        temp = temp->next;
        node = NULL;
        b= b->next;
      }

 }
 if(b==NULL) {
     try1 = a;
   }
else if (a==NULL){
   try1=b;
}
while(try1 !=NULL){

         push_to_head(node,*(try1->ptr));
        temp->next = node;
        temp = temp->next;
        node = NULL;
        try1 = try1->next;

}
return ((*newl)->next)
*/

   mylist *head=NULL,*temp;
   mylist dummy;
    
   if(a == NULL)
        return b;
   else if(b == NULL)
       return a;
   else {
       if(*(a->ptr) < (*b->ptr))
        {
           head = a;
           a= a->next;
        }
       else

       {
           head = b;
           b=b->next;

       }
   dummy.next = head;
       while((a!=NULL) && (b!=NULL)){
            
           if(*(a->ptr) <= *(b->ptr)){

            temp = a->next;
            head->next = a;
            a=temp;
                

           }
           else
           {

            temp = b->next;
            head->next = b;
            b=temp;

           }
        head= head->next;     
       } 
       if(a==NULL){
           head->next= b;
       }
       if(b==NULL){
           head->next =a;
        }

   }
   return (dummy.next);

}
/*STU 15 */

void MergeSort(mylist** headRef) 
{


mylist *a;
mylist *b;
mylist *head=*headRef;

//printf("%p\n",headRef);
//printf("%p\n",*headRef);

if((head == NULL) || (head->next == NULL))
    return;

FrontBackSplit(head,&a,&b);
MergeSort(&a);
MergeSort(&b);
*headRef = SortedMerge(a,b);

}  


/*STU 16
* Given two lists sorted in increasing order, create and return a new list
* representing the
* intersection of the two lists. The new list should be made with its own
* memory . the
* original lists should not be changed. In other words, this should be Push()
* list building,
* not MoveNode(). Ideally, each list should only be traversed once
*/


mylist* SortedIntersect(mylist* a, mylist* b) 
{

    

    mylist dummy;

    mylist *tail = &dummy;
    dummy.next=NULL;

    while(a!=NULL && b!=NULL){

        if(*(a->ptr) == *(b->ptr))
        {

            push_to_head(&(tail->next),*(a->ptr));
            tail = tail->next;
            a= a->next;
            b= b->next;


        }
        else if( *(a->ptr) < *(b->ptr))
        {
            a= a->next;
        
        }
        else
        {
            b=b->next;
        }


    }


    return dummy.next;
}
    
    
/* STU17
*  Write an iterative Reverse() function that reverses a list by rearranging
*  all the .next
*  pointers and the head pointer. Ideally, Reverse() should only need to make
*  one pass of the
*  list.
*/


void Reverse(mylist **head)
{

    mylist **headref= &((*head)->next);
    mylist *temp =((*headref)->next);

    while(*(headref)!=NULL)
    {
       temp = (*headref)->next;
       MoveNode(head,headref);
       *headref= temp;

    }
    
}
     

/*STU 18
* Recursive Revers
*/
    
void ReverseRecursive(mylist **head)
{

    mylist *first;
    mylist *rest ;

    if((*head) == NULL)
        return;

    first = *head;
    rest = (*head)->next;
    if(rest == NULL) 
        return;
    ReverseRecursive(&rest);
    first->next->next= first;
    first->next=NULL;
    *head= rest;

}




void swapKth(mylist **head,int k)
{

  int n = find_length_of_list(*head);
  int hop ;
  //int before = 0;
  int cnt=1;
  mylist **headref = head;
  mylist **prev,*curr;
  mylist **prev2,*curr2;
  mylist *t;

  if (k > n)
  {
        printf("Error..Given position is outside the list\n");
        return;
  }
  if((2*k -1) <= 0) return; /*nodes are same from both ends*/

  hop = n-k+1;

  while( *headref !=NULL)
  {

      if( (cnt == hop) )
      {

        prev = headref;
        curr = *headref;

      }
      if(cnt == k)
      {

    
        prev2 = headref;
        curr2 = *headref;

      }
      cnt++;
      headref = &((*headref)->next);


  }

  *(prev) = curr2;
   *prev2 =curr;
 
   /*TODO*/

   t = curr2->next;
   curr2->next = curr->next;
   /*TODO*/
   curr->next = t;

  
}

