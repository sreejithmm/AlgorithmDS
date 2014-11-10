#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"


int main(){


     int i,j,k,x;
     tree_int *intTree,*intTree1;
     tree_threaded_int *intTreeThr;
     tree_int* temp;
     tree_int* tree;
     tree_int* intTree2;
     tree_sp_int* intTree3;
     tree_int_liss* intTreeLiss=NULL;
     myqueue *qu;
     tst* terTree=NULL;
     char buf[100]={'\0'};
     mylist* list;

     int inor[]={1,2,3,4,5};
     int preor[]={4,2,1,3,5};
     int inorMax[]={1,5,10,40,30,15,28,20};
     int preorsp[]={10,30,20,5,15};
     char propsp[]={'N','N','L','L','L'};

     int preorder[]={1,2,4,8,9,5,3,6,7};
     int postorder[]={8,9,4,5,2,6,7,3,1};
     int sizein=0;

     int num[100]={0};
     int weight[100]={0};

    while(1){
        printf("\nMENU\n");
        printf("****\n");
        printf("1. Traverse tree \n");
        printf("2. Traverse a threaded tree(inorder) \n");
        printf("3. Check if trees are identical\n");
        printf("4. Print spiral\n");
        printf("5. Check if sume of childern equals node value\n");
        printf("6. Adjust a tree to sum of children\n");
        printf("7. Diameter of a tree\n");
        printf("8. Check if a tree is balanced or not\n");
        printf("9. Convert arrays to tree\n");
        printf("10. Create a double tree\n");
        printf("11. Check foldability\n");
        printf("12. Check levle of a tree member\n");
        printf("13. Print ancestors\n");
        printf("14. Check if a tree is sum tree or not\n");
        printf("15. Chck if a subtree is present in another tree\n");
        printf("16. Connect a tree to next right\n");
        printf("17. Connect a tree to next right without using Queue(for a complete binary tree\n");
        printf("18. Connect a tree to next right without using Queue and recursion(for a complete binary tree\n");
        printf("19. Convert to sum tree\n");
        printf("20. Calculate vertical sum\n");
        printf("21. Convert Inorder array(max properties) to tree\n");
        printf("22. Convert preor array(and properties array) to tree\n");
        printf("23. Check if  a tree is complete binary tree or not\n");
        printf("24. Print boundaries of a tree\n");
        printf("25. Create a tree from preorder and post order array\n");
        printf("26. make a complete binary tree and print its level order\n");
        printf("27. Create a ternary search tree and traverse\n");
        printf("28. Create a segment tree with sum of array\n");
        printf("29. Find largest independent subset of a tree (LISS)\n");
        printf("30. Convert a list to tree\n");
        printf("31. Find max weight of increasing subarry\n");

        scanf("%d",&k);
        switch(k)
        {
            case 1:
                     intTree = (tree_int*)newNode(4);
                     intTree->left =  (tree_int*)newNode(2);
                     intTree->right =(tree_int*)newNode(5);
                     intTree->left->left = (tree_int*)newNode(1);
                     intTree->left->right = (tree_int*)newNode(3);
                     
                     printf("Preorder Traversal\n");
                     preorderTraverseInt(intTree);
                     printf("\n");

                     printf("Preorder Iterative Traversal\n");
                     preorderIterative(intTree);
                     printf("\n");
                     printf("Preorder Morris Traversal\n");
                     preOrderMorrisTraversal(intTree);
                     printf("\n");



                     printf("Postorder Traversal\n");
                     postorderTraverseInt(intTree);
                       
                     printf("\n");
                     printf("Post order iterative\n");
                     postOrderIterativeTraversal(intTree);

                     printf("\n");
                     printf("Inorder Traversal\n");
                     inorderTraverseInt(intTree);
                     printf("\n");
                     printf("Inorder Traversal without recursion\n");
                     inorderTraverseIntwoRecursion(intTree);

                     printf("\nInorder traversal without stack and recursion\n");
                     inorderMorrisTraversal(intTree);
                     printf("\n");

                     printf("\n");
                     printf("Size of a tree =%d\n",sizeofTree(intTree));
                     printf("Depth of a tree =%d\n",depth(intTree));

                     printf("paths of array\n");
                     printPaths(intTree);

                      printf("Level order traversal of a tree\n");
                     printLevelTraversal(intTree);  
                     printf("\n");
                     printf("Level order traversal of a tree using queue\n");
                     printLevelwithQueue(intTree);  
                     printf("\n");
                     printf("Reverse level order\n");
                     reverseLevelOrderTraversal(intTree);
                     printf("\n");

                    printf("Checking sum of path\n");
                     printf("Enter a value you want to check\n");
                     scanf("%d",&k);
                     checkSumofPathisNumber(intTree,k);

#if 0
                    printf("Converitng tree to Doubly linked list\n");
                    temp = (tree_int*)convertTreeToList( intTree);
                    printf("Converted to Doubly linked list\n");
                    print_list(temp);
#else
                    printf("Converitng tree to Circular D list\n");
                    temp = (tree_int*)convertTreeToDlist( intTree);
                    printf("Converted to Circular D list\n");
                    print_dlist(temp);
#endif

                    break;
             case 2:
                    intTreeThr = (tree_threaded_int*)newThreadedTreeNode(1,NULL);
                    intTreeThr->left =  (tree_threaded_int*)newThreadedTreeNode(2,NULL);
                    intTreeThr->right =(tree_threaded_int*)newThreadedTreeNode(3,NULL);
                    intTreeThr->left->left = (tree_threaded_int*)newThreadedTreeNode(4,intTreeThr->left);
                    intTreeThr->left->right = (tree_threaded_int*)newThreadedTreeNode(5,intTreeThr);
                    printf("inorder Threded tree traversal\n");
                    inorderThreadedTree(intTreeThr);
                    printf("\n");
                    break;

              case 3:

                     
                     intTree = (tree_int*)newNode(1);
                     intTree->left =  (tree_int*)newNode(2);
                     intTree->right =(tree_int*)newNode(3);
                     intTree->left->left = (tree_int*)newNode(4);
                     intTree->left->right = (tree_int*)newNode(5);
 
                     intTree1 = (tree_int*)newNode(1);
                     intTree1->left =  (tree_int*)newNode(2);
                     intTree1->right =(tree_int*)newNode(3);
                     intTree1->left->left = (tree_int*)newNode(4);
                     intTree1->left->right = (tree_int*)newNode(5);


                     (identicalTrees(intTree1,intTree))?printf("Identical\n"):printf("Not identical\n");
                      break; 
    
             case 4:
                     intTree = (tree_int*)newNode(1);
                     intTree->left =  (tree_int*)newNode(2);
                     intTree->right =(tree_int*)newNode(3);
                     intTree->left->left = (tree_int*)newNode(7);
                     intTree->left->right = (tree_int*)newNode(6);
 
                     intTree->right->left = (tree_int*)newNode(5);
                     intTree->right->right = (tree_int*)newNode(4);
                     printf("Printin spiral\n");                      
                     printSpiral(intTree);
                     printf("\n");
                     break;

             case 5:

                     intTree = (tree_int*)newNode(10);
                     intTree->left =  (tree_int*)newNode(8);
                     intTree->right =(tree_int*)newNode(2);
                     intTree->left->left = (tree_int*)newNode(5);
                     intTree->left->right = (tree_int*)newNode(3);
 
                     intTree->right->left = (tree_int*)newNode(2);
                     if(checkSumOfChildren(intTree))
                         printf("True\n");
                     else
                         printf("false\n");
                     break;

             case 6:
                     intTree = (tree_int*)newNode(50);
                     intTree->left =  (tree_int*)newNode(7);
                     intTree->right =(tree_int*)newNode(2);
                     intTree->left->left = (tree_int*)newNode(3);
                     intTree->left->right = (tree_int*)newNode(5);
 
                     intTree->right->left = (tree_int*)newNode(1);
                     intTree->right->right = (tree_int*)newNode(30);
                    
                     printf("Original tree\n");
                     inorderTraverseInt(intTree);
                     printf("\nTree adjusted to sum of children\n");
                     adjustTreetoSumofChildres(intTree);
                     inorderTraverseInt(intTree);
                     break;
             case 7:
                     intTree = (tree_int*)newNode(50);
                     intTree->left =  (tree_int*)newNode(7);
                     intTree->right =(tree_int*)newNode(2);
                     intTree->left->left = (tree_int*)newNode(3);
                     intTree->left->right = (tree_int*)newNode(5);
 
                     intTree->right->left = (tree_int*)newNode(1);
                     intTree->right->right = (tree_int*)newNode(30);
                    
                     printf("Original tree\n");
                     inorderTraverseInt(intTree);
                     printf("\nDiameter of tree\n");
//                     adjustTreetoSumofChildres(intTree);
                     printf("Diameter of tree = %d\n",diameterofTree(intTree,&k));
                     inorderTraverseInt(intTree);
                     break;
              case 8:
                     intTree = (tree_int*)newNode(50);
                     intTree->left =  (tree_int*)newNode(7);
                     intTree->right =(tree_int*)newNode(2);
                     intTree->left->left = (tree_int*)newNode(3);
                     intTree->left->right = (tree_int*)newNode(5);
                     intTree->left->left->left = (tree_int*)newNode(10);
                     intTree->left->left->left->left = (tree_int*)newNode(12);
 
                     intTree->right->left = (tree_int*)newNode(1);
                     intTree->right->right = (tree_int*)newNode(30);
                    
                     printf("Original tree\n");
                     inorderTraverseInt(intTree);
                     k = isBalanced(intTree);
                     (k==1)?printf("\nbalanced tree\n"):printf("\nNot balanced\n");
                     inorderTraverseInt(intTree);
                     break;

             case 9:
                     sizein = sizeof(inor)/sizeof(inor[0]);
                     printf("Converting arrays to tree\n");
                     int prestart = 0;
                     tree = (tree_int*)convertArrayToTree(inor,preor,0,sizein,&prestart);
                     printf("Converted arary to tree: Its inorder values are\n");
                     inorderTraverseInt(tree);
                     printf("\nPreorder values are:\n");
                     preorderTraverseInt(tree);
                     printf("\n");
                     break;


             case 10:
                     intTree = (tree_int*)newNode(1);
                     intTree->left =  (tree_int*)newNode(2);
                     intTree->right =(tree_int*)newNode(3);

                     intTree->left->left = (tree_int*)newNode(4);
                     intTree->left->right = (tree_int*)newNode(5);
                     printf("preorder traversal of original tree\n");
                     preorderTraverseInt(intTree);
                     intTree = (tree_int*)doubleTree(intTree);
                     printf("preorder traversal of double tree\n");
                     preorderTraverseInt(intTree);
                     break;


             case 11:
                     printf("Checking first tree\n");
                     intTree = (tree_int*)newNode(10);
                     intTree->left =  (tree_int*)newNode(7);
                     intTree->left->right = (tree_int*)newNode(9);
                     intTree->right =(tree_int*)newNode(3);
                     intTree->right->left = (tree_int*)newNode(4);


                     checkFoldable(intTree);
                     printf("Checking second tree\n");

                     intTree2 = (tree_int*)newNode(1);
                     intTree->left =  (tree_int*)newNode(7);
                     intTree->left->left = (tree_int*)newNode(9);

                     intTree2->right =(tree_int*)newNode(3);
                     intTree2->right->left = (tree_int*)newNode(4);

                     checkFoldable(intTree);
                        break;

              case 12:

                     intTree = (tree_int*)newNode(50);
                     intTree->left =  (tree_int*)newNode(7);
                     intTree->right =(tree_int*)newNode(2);
                     intTree->left->left = (tree_int*)newNode(3);
                     intTree->left->right = (tree_int*)newNode(5);
                     intTree->right->left = (tree_int*)newNode(1);
                     intTree->right->right = (tree_int*)newNode(30);
                    
                     inorderTraverseInt(intTree);
                     printf("\nEnter a number you want to check the level\n");
                     scanf("%d",&k);
                     printf("Level is:%d\n",getLevel(intTree,k,1));
                     break;

             case 13: 
                     intTree = (tree_int*)newNode(50);
                     intTree->left =  (tree_int*)newNode(7);
                     intTree->right =(tree_int*)newNode(2);
                     intTree->left->left = (tree_int*)newNode(3);
                     intTree->left->right = (tree_int*)newNode(5);
                     intTree->right->left = (tree_int*)newNode(1);
                     intTree->right->right = (tree_int*)newNode(30);
                    
                     inorderTraverseInt(intTree);
                     printf("\nEnter a number you want to check the ancestors\n");
                     scanf("%d",&k);
                     printf("ancestors::::\n");
                     printAncestors(intTree,k);
                     printf("\n");
                     break;
              case 14:
                     intTree = (tree_int*)newNode(26);
                     intTree->left =  (tree_int*)newNode(10);
                     intTree->right =(tree_int*)newNode(3);
                     intTree->left->left = (tree_int*)newNode(4);
                     intTree->left->right = (tree_int*)newNode(6);
                     intTree->right->right = (tree_int*)newNode(3);
                    
                     inorderTraverseInt(intTree);
//                     CheckSumOfChildren(intTree);
                     i = isSumTree(intTree);
                     (i==0)?printf("Not a sumtree\n"):printf("Sum Tree\n");
                     printf("\n");
                     break;

              case 15:
                     intTree = (tree_int*)newNode(26);
                     intTree->left =  (tree_int*)newNode(10);
                     intTree->right =(tree_int*)newNode(3);
                     intTree->left->left = (tree_int*)newNode(4);
                     intTree->left->right = (tree_int*)newNode(6);
                     intTree->right->right = (tree_int*)newNode(3);
                     printf("Original tree\n");
                     preorderTraverseInt(intTree);
                     printf("\n");
                     intTree2 =  (tree_int*)newNode(10);
                     intTree2->left = (tree_int*)newNode(4);
                     intTree2->right = (tree_int*)newNode(6);

                     printf("Subtree candidate tree\n");
                     preorderTraverseInt(intTree2);
                     printf("\n");
 
                     i =  isSubTreePresent(intTree,intTree2);
                     if(i==0)
                         printf("Subtree is not present\n");
                     else
                         printf("Subtree present\n");
                     break;
                case 16:
                      intTree3 = (tree_sp_int*)newNodeConn(10);
                      intTree3->left        = (tree_sp_int*)newNodeConn(8);
                      intTree3->right       = (tree_sp_int*)newNodeConn(2);
                      intTree3->left->left  = (tree_sp_int*)newNodeConn(3);
                      intTree3->left->right  = (tree_sp_int*)newNodeConn(4);
                      intTree3->right->left  = (tree_sp_int*)newNodeConn(5);
                      intTree3->right->right  = (tree_sp_int*)newNodeConn(6);
                              
                     // Populates conn pointer in all nodes
                      ConnectToNext(intTree3);
                      // Let us check the values of conn pointers
                      printf("Following are populated conn pointers in the tree "
                                    "(-1 is printed if there is no conn) \n");
                      printf("conn of %d is %d \n", intTree3->data,
                                     intTree3->conn? intTree3->conn->data: -1);
                      printf("conn of %d is %d \n", intTree3->left->data,
                                      intTree3->left->conn? intTree3->left->conn->data: -1);
                      printf("conn of %d is %d \n", intTree3->right->data,
                                       intTree3->right->conn? intTree3->right->conn->data: -1);
                      printf("conn of %d is %d \n", intTree3->left->left->data,
                                          intTree3->left->left->conn? intTree3->left->left->conn->data: -1);
                      printf("conn of %d is %d\n",intTree3->left->right->data,intTree3->left->right->conn?intTree3->left->right->conn->data:-1);
                      printf("conn of %d is %d\n",intTree3->right->left->data,intTree3->right->left->conn?intTree3->right->left->conn->data:-1);
                      printf("conn of %d is %d\n",intTree3->right->right->data,intTree3->right->right->conn?intTree3->right->right->conn->data:-1);
                      break;
                case 17:
                      intTree3 = (tree_sp_int*)newNodeConn(10);
                      intTree3->left        = (tree_sp_int*)newNodeConn(8);
                      intTree3->right       = (tree_sp_int*)newNodeConn(2);
                      intTree3->left->left  = (tree_sp_int*)newNodeConn(3);
                      intTree3->left->right  = (tree_sp_int*)newNodeConn(4);
                      intTree3->right->left  = (tree_sp_int*)newNodeConn(5);
                      intTree3->right->right  = (tree_sp_int*)newNodeConn(6);

                      intTree3->left->left->left = (tree_sp_int*)newNodeConn(7);
                      intTree3->left->left->right = (tree_sp_int*)newNodeConn(9);

                      intTree3->right->right->left = (tree_sp_int*)newNodeConn(10);
                      intTree3->right->right->right = (tree_sp_int*)newNodeConn(11);

                     // Populates conn pointer in all nodes
                      ConnectToNextPreOrder(intTree3);
                      // Let us check the values of conn pointers
                      printf("Following are populated conn pointers in the tree "
                                    "(-1 is printed if there is no conn) \n");
                      printf("conn of %d is %d \n", intTree3->data,
                                     intTree3->conn? intTree3->conn->data: -1);
                      printf("conn of %d is %d \n", intTree3->left->data,
                                      intTree3->left->conn? intTree3->left->conn->data: -1);
                      printf("conn of %d is %d \n", intTree3->right->data,
                                       intTree3->right->conn? intTree3->right->conn->data: -1);
                      printf("conn of %d is %d \n", intTree3->left->left->data,
                                          intTree3->left->left->conn? intTree3->left->left->conn->data: -1);
                      printf("conn of %d is %d\n",intTree3->left->right->data,intTree3->left->right->conn?intTree3->left->right->conn->data:-1);
                      printf("conn of %d is %d\n",intTree3->right->left->data,intTree3->right->left->conn?intTree3->right->left->conn->data:-1);
                      printf("conn of %d is %d\n",intTree3->right->right->data,intTree3->right->right->conn?intTree3->right->right->conn->data:-1);
                      
                      printf("conn of %d is %d\n",intTree3->left->left->left->data,intTree3->left->left->left->conn?intTree3->left->left->left->conn->data:-1);
                      printf("conn of %d is %d\n",intTree3->left->left->right->data,intTree3->left->left->right->conn?intTree3->left->left->right->conn->data:-1);
                      printf("conn of %d is %d\n",intTree3->right->right->left->data,intTree3->right->right->left->conn?intTree3->right->right->left->conn->data:-1);
                      printf("conn of %d is %d\n",intTree3->right->right->right->data,intTree3->right->right->right->conn?intTree3->right->right->right->conn->data:-1);
                      break;
                case 18:
                      intTree3 = (tree_sp_int*)newNodeConn(10);
                      intTree3->left        = (tree_sp_int*)newNodeConn(8);
                      intTree3->right       = (tree_sp_int*)newNodeConn(2);
                      intTree3->left->left  = (tree_sp_int*)newNodeConn(3);
                      intTree3->left->right  = (tree_sp_int*)newNodeConn(4);
                      intTree3->right->left  = (tree_sp_int*)newNodeConn(5);
                      intTree3->right->right  = (tree_sp_int*)newNodeConn(6);

                      intTree3->left->left->left = (tree_sp_int*)newNodeConn(7);
                      intTree3->left->left->right = (tree_sp_int*)newNodeConn(9);

                      intTree3->right->right->left = (tree_sp_int*)newNodeConn(10);
                      intTree3->right->right->right = (tree_sp_int*)newNodeConn(11);

                     // Populates conn pointer in all nodes
                      ConnectNextPreorderLoop(intTree3);
                      // Let us check the values of conn pointers
                      printf("Following are populated conn pointers in the tree "
                                    "(-1 is printed if there is no conn) \n");
                      printf("conn of %d is %d \n", intTree3->data,
                                     intTree3->conn? intTree3->conn->data: -1);
                      printf("conn of %d is %d \n", intTree3->left->data,
                                      intTree3->left->conn? intTree3->left->conn->data: -1);
                      printf("conn of %d is %d \n", intTree3->right->data,
                                       intTree3->right->conn? intTree3->right->conn->data: -1);
                      printf("conn of %d is %d \n", intTree3->left->left->data,
                                          intTree3->left->left->conn? intTree3->left->left->conn->data: -1);
                      printf("conn of %d is %d\n",intTree3->left->right->data,intTree3->left->right->conn?intTree3->left->right->conn->data:-1);
                      printf("conn of %d is %d\n",intTree3->right->left->data,intTree3->right->left->conn?intTree3->right->left->conn->data:-1);
                      printf("conn of %d is %d\n",intTree3->right->right->data,intTree3->right->right->conn?intTree3->right->right->conn->data:-1);
                      
                      printf("conn of %d is %d\n",intTree3->left->left->left->data,intTree3->left->left->left->conn?intTree3->left->left->left->conn->data:-1);
                      printf("conn of %d is %d\n",intTree3->left->left->right->data,intTree3->left->left->right->conn?intTree3->left->left->right->conn->data:-1);
                      printf("conn of %d is %d\n",intTree3->right->right->left->data,intTree3->right->right->left->conn?intTree3->right->right->left->conn->data:-1);
                      printf("conn of %d is %d\n",intTree3->right->right->right->data,intTree3->right->right->right->conn?intTree3->right->right->right->conn->data:-1);
                      break;
                 case 19:
                     intTree = (tree_int*)newNode(10);
                     intTree->left =  (tree_int*)newNode(-2);
                     intTree->right =(tree_int*)newNode(6);
                     intTree->left->left = (tree_int*)newNode(8);
                     intTree->left->right = (tree_int*)newNode(-4);
                     intTree->right->right = (tree_int*)newNode(5);
                     intTree->right->left = (tree_int*)newNode(7);
                     printf("Original tree\n");
                     preorderTraverseInt(intTree);
                     printf("\n");
                     ConvertToSumTree(intTree);
                     printf("Converted tree\n");
                     preorderTraverseInt(intTree);
                     printf("\n");
                     break;
                case 20:
                     intTree = (tree_int*)newNode(1);
                     intTree->left =  (tree_int*)newNode(2);
                     intTree->right =(tree_int*)newNode(3);
                     intTree->left->left = (tree_int*)newNode(4);
                     intTree->left->right = (tree_int*)newNode(5);
                     intTree->right->right = (tree_int*)newNode(7);
                     intTree->right->left = (tree_int*)newNode(6);
                     printf("Original tree\n");
                     preorderTraverseInt(intTree);
                     printf("\n");
                     CalculateVerticalSum(intTree);
                     printf("\n");
                     break;
                case 21:
                     sizein = sizeof(inorMax)/sizeof(inorMax[0]);
                     temp = (tree_int*)makeTreeFromInorderArray(inorMax,0,sizein);

                     printf("in order traversal of created tre\n");
                     inorderTraverseInt(temp);
                     printf("\n");
                     break;
               case 22:
                    sizein = sizeof(preorsp)/sizeof(preorsp[0]);
                    k = -1;
                    temp=(tree_int*)makeTreeFromSpecialPreorderArrays(preorsp,&k,sizein,propsp);
                    printf("Pre order traversal of the special tree created\n");
                    preorderTraverseInt(temp);
                    printf("\n");
                    break;
              case 23:
                     intTree = (tree_int*)newNode(1);
                     intTree->left =  (tree_int*)newNode(2);
                  //   intTree->right =(tree_int*)newNode(3);
                   //  intTree->left->left = (tree_int*)newNode(4);
                    // intTree->left->right = (tree_int*)newNode(5);
                 //    intTree->right->right = (tree_int*)newNode(7);
                //     intTree->right->left = (tree_int*)newNode(6);
                     k = isCompleteTree(intTree);
                     (k==1)?printf("Complete binary tree\n"):printf("Not a complete binary tree\n");
                     break;

              case 24:
                     intTree = (tree_int*)newNode(1);
                     intTree->left =  (tree_int*)newNode(2);
                     intTree->right =(tree_int*)newNode(3);
                     intTree->left->left = (tree_int*)newNode(4);
                     intTree->left->right = (tree_int*)newNode(5);
                     intTree->right->right = (tree_int*)newNode(7);
                     intTree->right->left = (tree_int*)newNode(6);
                     printBoundary(intTree);
                     break;

              case 25:
                    sizein=sizeof(postorder)/sizeof(postorder[0]);
                    k=0;
                    temp = (tree_int*)ConvertPrePostArraysToTree(preorder,postorder,0,sizein,&k);
                    printf("Pre order of created tree\n");
                    preorderTraverseInt(temp);
                    printf("\n");
                    printf("Post order of created tree\n");
                    postorderTraverseInt(temp);
                    printf("\n");
                    break;

                case 26:

                    qu = (myqueue*)createQueue();
                    temp = NULL;
                    for(i=0;i<7;i++)
                    {
                        makeCompleteBinaryTree(&temp,i,qu);
                    }
                    printf("level order traversal of new created tree\n");
                    printLevelTraversal(temp);                    
                    printf("\n");
                    break;

                case 27:
                    printf("Inserting\n");
                    insertTST(&terTree,"cat");
                    insertTST(&terTree,"cats");
                    insertTST(&terTree,"up");
                    insertTST(&terTree,"bug");
                    printf("Printing\n");
                    TraverseTST(terTree,buf,0);
                    printf("\n");
                    k=SearchTST(terTree,"cats");
                    printf("cats is ");
                    (k==1)?printf("found\n"):printf("not found \n");
                    k=SearchTST(terTree,"bugs");
                    printf("bugs is ");
                    (k==1)?printf("found\n"):printf("not found \n");
                    k=SearchTST(terTree,"bug");
                    printf("bug is ");
                    (k==1)?printf("found\n"):printf("not found \n");
                    break;
              case 28:
                    printf("segment Tree ops\n");
                    API_makeSegmentTree();
                    break;
              case 29:
                    printf("LISS\n");
                    intTreeLiss = (tree_int_liss*)newNodeLiss(1);
                    intTreeLiss->left =  (tree_int_liss*)newNodeLiss(2);
                    intTreeLiss->right =(tree_int_liss*)newNodeLiss(3);
                    intTreeLiss->left->left = (tree_int_liss*)newNodeLiss(4);
                    intTreeLiss->left->right = (tree_int_liss*)newNodeLiss(5);
                    intTreeLiss->right->right = (tree_int_liss*)newNodeLiss(7);
                    intTreeLiss->right->left = (tree_int_liss*)newNodeLiss(6);
                    k = LargestIndSet(intTreeLiss);
                    printf("Largest independent subset contains %d\n",k);

                    break;
              case 30:
                    printf("ENter number of nodes:\n");
                    scanf("%d",&k);
                    list = (mylist*)create_list(k);
                    temp = (tree_int*)treeFromLinkedList(list);
                    printf("Level order traversal of newly created tree\n");
                    printLevelTraversal(temp);
                    printf("\n");
                    break;

             case 31:
                    printf("Enter the number of elements\n");
                    scanf("%d",&k);
                    printf("Enter the values\n");
                    for(i=0;i<k;i++)
                    {
                        scanf("%d",&num[i]);
                    }
                    printf("Enter the weights\n");
                    for(j=0;j<k;j++)
                    {
                        scanf("%d",&weight[j]);

                    }
                    i= 0;
                    i= findMaxWeight(num,weight,k);
                    printf("maximum weight = %d\n",i);
                    break;
                    
    

                   


       }

   }
   return 0;
}


