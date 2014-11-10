#include <stdio.h>
#include "header.h"


int  main()
{

    int choice;
    int num,idx=0,n,i=0,a[10];
    mylist *head=NULL;
    mylist* in_use;
    mylist* temp=NULL;

    while(1)
    {
            printf("MENU-Doubly Linked List\n");
            printf("***********************\n");
            printf("1. Create a list\n");
            printf("2. Delete a list\n");
            printf("3. Print a list\n");
            printf("4. Delete a node\n");
            printf("5. Reverse a list\n");
            printf("6. Copy a list with arbitrary prev pointers\n");
            printf("7. Quicksort an array-trial\n");
            printf("8. Quicksort an doubly linkedlist\n");

            scanf("%d",&choice);
            switch(choice)
            {
              case 1: 
                 printf("Enter number of nodes\n");
                 scanf("%d",&num);
                 head=(mylist*)create_list(num);
                 in_use=head;
                 break;
             case 2:
                // delete_list(&head);
                 break;
             case 3:
                 print_list(in_use);
                 break;
             case 4:
                 printf("Enter index of the node you want to delete\n");
                 scanf("%d",&choice);
                 idx=0;
                 temp=in_use;
                 while((idx != choice) && temp)
                 {
                        temp = temp->next;
                        idx++;
                 }
                 if(temp != NULL)
                 {
                        
                     deleteNode(&in_use,temp);
                     printf("Deleted List\n");
                     print_list(in_use);
                 }
                 else{

                    printf("ERROR! Index does not exist\n");
                 }
                 break;
             case 5:
                 reverse(&in_use);
                 print_list(in_use);
                 break;
             case 6:
                 printCopyArbitList();
                 break;
             case 7:
                 printf("Enter the number of elements in the array\n");
                 scanf("%d",&n);
                 for(i=0; i<n;i++)
                 {
                        printf("Enter value[%d]",i);
                        scanf("%d",&a[i]);
                 }
                 printf("Original array\n");
                 for(i=0;i<n;i++)
                 {
                        
                        printf("%d ",a[i]);
                    
                 }
 
                 QuickSort(a,0,n-1);
                 printf("\nSorted array\n");
                 for(i=0;i<n;i++)
                 {
                        printf("%d ",a[i]);
                    
                 }
                 printf("\n");
                 break;
             case 8:
                 printf("Enter number of nodes\n");
                 scanf("%d",&num);
                 head=(mylist*)create_list(num);
                 in_use=head;
                 temp = head;
                 while(temp->next !=NULL){
                     temp = temp->next;
                 }
   //              head->prev = temp;
     //            temp->next=head;
                 listQuickSort(head,temp);
                 printf("QuickSorted List\n");
                 print_list(head);
                 break;
          } 
    }

 EOP:
    printf("Program exiting\n");

}
