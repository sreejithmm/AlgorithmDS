#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "basiclistops.h"

int main()


{
    
   mylist *head,*temp,*looped_head,*scndHead,*front,*back,*aRef,*bRef;
   
   int idx,num,num2,cnt=0,done,flag,id,k;
   unsigned int option;
   mylist *in_use=NULL,*in_use2=NULL;
         int val;

         mylist *node=NULL;

   while(1){
       
   printf("MENU\n");
   printf("****\n");
   printf("1.  Create list\n");
   printf("2.  Delete list\n");
   printf("3.  Print list\n");
   printf("4.  Print list in reverse order\n");
   printf("5.  Find middle node from a list\n");
   printf("6.  Add a node to the list\n");
   printf("7.  Reverse the list\n");
   printf("8.  Delete Nth Node from a list(Using index)\n");
   printf("9.  Delete Nth Node from a list(Using Node address)\n");
   printf("10. Create a list with loop\n");
   printf("11. Check if loop exist\n");
   printf("12. Push a node to list\n");
   printf("13. Pop a node from list\n");
   printf("14. Insert a node in sorted order\n");
   printf("15. Insert a node in sorted order2-without extracheck\n");
   printf("16. Sort a list\n");
   printf("17. Append one list at the end of first list\n");
   printf("18. Split one list two front and back lists\n");
   printf("19. Remove duplicates from a list\n");
   printf("20. Move a node from second lists head to first lists head\n");
   printf("21. Split one list to two lists with alternating nodes\n");
   printf("22. Merge(ShuffleMerge) two lists\n");
   printf("23. Merge(SortedMerge) two lists\n");
   printf("24. MergeSort a list\n");
   printf("25. Create a sorted intersect list from 2 sorted lists\n");
   printf("26. Reverse a list\n");
   printf("27. Reverse a list using recursion\n");
   printf("28. swap kth node from beginning with kthnode from end\n");
   printf("29. Exit\n");

   scanf("%u",&option);


   switch(option){
    
       case 1:

           printf("Enter the number of nodes\n");
           scanf("%d",&num);
           printf("Creating list with %d elements\n\n",num);
           head=create_list(num);
           in_use=head;
           break;
       case 2:
           free_my_list(&in_use);
           free_my_list(&in_use2);
           head=NULL;
           break;
       case 3:
           disp_list(in_use);
           break;
       case 4:
          print_reverse(in_use);
          break;
       case 5:
          temp = find_middle_node(in_use);
          printf("Middlenode : ");
          print_node(temp);
          break;
       case 6:
         printf("Append a node to the list 1 \n");
         scanf("%d",&id);
         num++;
         push_to_head(&in_use,id);
         printf("head:%p\n",in_use);
         break;
       case 7:
         printf("reverse\n");
         reverse_list(&in_use);
         printf("head:%p\n",in_use);
         break;
      case 8:
        printf("Enter the index you want to delete?\n");
        scanf("%d",&idx);
        done = rem_node_by_index(idx,&in_use); 
        num=(done==0)?num:(num-1);
        break;
      case 9:
        printf("Which node you want to delete out of 0 to %d number of nodes\n",(num-1));
        scanf("%d",&idx);
        temp = in_use;
        while ((cnt <idx) && temp){
           temp = temp->next;
           cnt++;
         }
        if(temp==NULL)
        {
           printf("Invalid node\n");
        }
        else{
          rem_node_by_addr(&temp);
        }
        in_use=(idx==0)?temp:in_use;
        break;
      case 10:
        looped_head=create_looped_list(num);
        in_use=looped_head;
        break;
      case 11:
        flag = checkif_loop_exist(in_use);
        (flag==1)?printf("Loop exist\n"):printf("No loop\n");
        break;
      case 12:
         /*TODO*/
         printf("Funcationality not available\n");
         break;
      case 13:
         pop(&in_use,&val);
         printf("Popped:%d\n",val);
         printf("NewList::\n");
         disp_list(in_use);
         break;
      case 14:
         push_to_head(&node,0);
         printf("Enter the new value to be inserted\n");
         scanf("%d",&idx);
         *(node->ptr) = idx;
         sortedInsert(&in_use,node);
         break;
      case 15:
         push_to_head(&node,0);
         printf("Enter the new value to be inserted\n");
         scanf("%d",&idx);
         *(node->ptr) = idx;
         sortedInsert2(&in_use,node);
         break;
      case 16:
         InsertSort(&in_use);
         break;
      case 17:
         printf("Create List 1\n");
         printf("Enter the number of nodes\n");
         scanf("%d",&num);
         printf("Creating list with %d elements\n\n",num);
         head=create_list(num);
         in_use=head;
        
         printf("Create List 2\n");
         printf("Enter the number of nodes\n");
         scanf("%d",&num2);
         printf("Creating list with %d elements\n\n",num);
         scndHead=create_list(num2);
         in_use2=scndHead;

         printf("Appending list \n");
         Append(&head,&scndHead);
         printf("Appended List::::\n");
         disp_list(head);
         break;
     case 18:
         printf("Create List 1\n");
         printf("Enter the number of nodes\n");
         scanf("%d",&num);
         printf("Creating list with %d elements\n\n",num);
         head=create_list(num);
         in_use=head;
        
         disp_list(head);
         printf("Front Back Split\n");
         FrontBackSplit(head,&front,&back);
        
         printf("Front portion\n");
         disp_list(front);
         printf("back portion\n");
         disp_list(back);
         free_my_list(&front);
         free_my_list(&back);
         break;

     case 19: 
         printf("Create List 1\n");
         printf("Enter the number of nodes\n");
         scanf("%d",&num);
         printf("Creating list with %d elements\n\n",num);
         head=create_list(num);
         in_use=head;
        
         RemoveDuplicates(head);
         printf("Duplicates removed from list and new list is\n");
         disp_list(head);
         break;

     case 20:
         printf("Create List 1\n");
         printf("Enter the number of nodes\n");
         scanf("%d",&num);
         printf("Creating list with %d elements\n\n",num);
         head=create_list(num);
         in_use=head;
        
         printf("Create List 2\n");
         printf("Enter the number of nodes\n");
         scanf("%d",&num2);
         printf("Creating list with %d elements\n\n",num);
         scndHead=create_list(num2);
         in_use2=scndHead;

         MoveNode(&head,&scndHead);

         printf("New List after moving node\n");
         printf("List1:\n");
         disp_list(head);
         printf("List2:\n");
         disp_list(scndHead);
         break;

      case 21:
         printf("Create List 1\n");
         printf("Enter the number of nodes\n");
         scanf("%d",&num);
         printf("Creating list with %d elements\n\n",num);
         head=create_list(num);
         in_use=head;
            
         AlternatingSplit(head,&aRef,&bRef);
         
         printf("Lists after Alternating split\n");
         printf("List 1\n");
         disp_list(aRef);


         printf("List 1\n");
         disp_list(bRef);
         break;
      case  22:
         printf("Create List 1\n");
         printf("Enter the number of nodes\n");
         scanf("%d",&num);
         printf("Creating list with %d elements\n\n",num);
         head=create_list(num);
         in_use=head;
        
         printf("Create List 2\n");
         printf("Enter the number of nodes\n");
         scanf("%d",&num2);
         printf("Creating list with %d elements\n\n",num);
         scndHead=create_list(num2);
         in_use2=scndHead;
         
        temp = (mylist*)ShuffleMerge(head,scndHead);
        printf("Merged list\n");
        disp_list(temp);
        free_my_list(&temp);
        break;

     case 23:
         printf("Create List 1\n");
         printf("Enter the number of nodes\n");
         scanf("%d",&num);
         printf("Creating list with %d elements\n\n",num);
         head=create_list(num);
         in_use=head;
        
         printf("Create List 2\n");
         printf("Enter the number of nodes\n");
         scanf("%d",&num2);
         printf("Creating list with %d elements\n\n",num);
         scndHead=create_list(num2);
         in_use2=scndHead;
         
        temp = (mylist*)SortedMerge(head,scndHead);
        printf("Sorted Merged list\n");
        disp_list(temp);
        free_my_list(&temp);
        break;


      case 24:
         printf("Create List \n");
         printf("Enter the number of nodes\n");
         scanf("%d",&num);
         printf("Creating list with %d elements\n\n",num);
         head=create_list(num);
         in_use=head;

         printf("Sorting this list \n");
         disp_list(head);
         MergeSort(&head);
        
         printf("Sorted list:::\n\n");
         disp_list(head);
         break;
     case 25:
         printf("Create List 1\n");
         printf("Enter the number of nodes\n");
         scanf("%d",&num);
         printf("Creating list with %d elements\n\n",num);
         head=create_list(num);
         in_use=head;
        
         printf("Create List 2\n");
         printf("Enter the number of nodes\n");
         scanf("%d",&num2);
         printf("Creating list with %d elements\n\n",num);
         scndHead=create_list(num2);
         in_use2=scndHead;
         
         temp = (mylist*)SortedIntersect(head,scndHead);
         printf("Sorted intersected list\n");
         disp_list(temp);
         free_my_list(&temp);
        break;
    
      case 26:
         printf("Create List \n");
         printf("Enter the number of nodes\n");
         scanf("%d",&num);
         printf("Creating list with %d elements\n\n",num);
         head=create_list(num);
         in_use=head;

         printf("Reversing this list \n");
         disp_list(head);
         Reverse(&head);
        
         printf("Reversed list:::\n\n");
         disp_list(head);
         break;
     case 27:
         printf("Create List \n");
         printf("Enter the number of nodes\n");
         scanf("%d",&num);
         printf("Creating list with %d elements\n\n",num);
         head=create_list(num);
         in_use=head;

         printf("Reversing this list \n");
         disp_list(head);
         ReverseRecursive(&head);
        
         printf("Reversed list___:::\n\n");
         disp_list(head);
         break;


     case 28:
         printf("Create List \n");
         printf("Enter the number of nodes\n");
         scanf("%d",&num);
         printf("Creating list with %d elements\n\n",num);
         head=create_list(num);
         in_use=head;

         printf("Enter value of k\n");
         scanf("%d",&k);
         swapKth(&head,k);

         printf("After swapping kth node from end and beginning\n");
         disp_list(head);
         break;

        
     case 29:  
         goto END_OF_LOOP;
         break;
   }
   }/*End of while*/  
END_OF_LOOP:
   printf("program exiting....\n");
   return 0;

 }
