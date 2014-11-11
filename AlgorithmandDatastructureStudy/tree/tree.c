#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include <limits.h>
#include <math.h>

char* lookup[27]={'\0',"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

tree_int* newNode(int val)
{


    tree_int* node = (tree_int*)malloc(sizeof(tree_int));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    printf("newNode: [%x] val[%d]\n",node,val);
    return node;

}
tree_int_liss* newNodeLiss(int val)
{

    tree_int_liss* node = (tree_int_liss*)malloc(sizeof(tree_int_liss));
    node->data = val;
    node->liss = 0;
    node->left = NULL;
    node->right = NULL;
    printf("newNode: [%x] val[%d]\n",node,val);
    return node;

}

tree_sp_int* newNodeConn(int val)
{

    tree_sp_int* node = (tree_sp_int*)malloc(sizeof(tree_sp_int));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    node->conn = NULL;
    printf("newNodeConn: [%x] val[%d]\n",node,val);
    return node;

}



void preorderTraverseInt(tree_int *root)
{

    if(root==NULL)
    {
        return ;
    }

    printf("%d ",root->data);
    preorderTraverseInt(root->left);
    preorderTraverseInt(root->right);
    return;

}

void postorderTraverseInt(tree_int *root)
{
    if(root==NULL)
    {
        return;
    }
    
    postorderTraverseInt(root->left);
    postorderTraverseInt(root->right);
    printf("%d ",root->data);



}
void inorderTraverseInt(tree_int *root)
{
    if(root==NULL)
        return;
    inorderTraverseInt(root->left);
    printf("%d ",root->data);
    inorderTraverseInt(root->right);

}
    
void push(mystack **stack, tree_int* node)
{

    mystack * st = (mystack*) malloc(sizeof(mystack));
    st->next=(*stack);
    st->node = node;
    *stack = st;
}

tree_int* pop(mystack **stack)
{

    tree_int* node;
    mystack* temp;

    if(*stack == NULL)
        return NULL;
    temp = (*stack);
    *stack = (*stack)->next;
    node = temp->node;
    free(temp);
    return node;

}

tree_int* peek(mystack *stack)
{
    if(stack == NULL)
        return NULL;

    return(stack->node);

}

void inorderTraverseIntwoRecursion(tree_int *root)
{

    int done=0;
    tree_int* current = root;
    mystack* s=NULL;

    while(!done)
    {

        if(current != NULL)
        {
            push(&s,current);
            current =  current->left;
        }
        else
        {
            if(s!=NULL)
            {
                current = pop(&s);
                printf("%d ",current->data);
                current = current->right;
            }
            else
            {
                done = 1;
            }

        }


    }


}

tree_threaded_int* newThreadedTreeNode(int val,tree_threaded_int* rightnode)
{
    tree_threaded_int* tree = (tree_threaded_int*) malloc(sizeof(tree_threaded_int));
    tree->data = val;
    tree->right = rightnode;
    if(rightnode != NULL)
        tree->threaded = 1;
    tree->left = NULL;
    return tree;

}

tree_threaded_int* leftmost(tree_threaded_int* root)
{
    while(root == NULL)
        return NULL;
    while(root->left != NULL)
        root = root->left;

    return root;
}

void inorderThreadedTree(tree_threaded_int* root)
{

    tree_threaded_int* cur = leftmost(root);

    while(cur != NULL)
    {
        printf("%d ",cur->data); 
       
        if(cur->threaded == 1)
            cur = cur->right;
        else
            cur = leftmost(cur->right);

    }


}

int sizeofTree(tree_int* root)
{
    
    if (root==NULL)
        return 0;
    else
        return(sizeofTree(root->left)+sizeofTree(root->right)+1);

}

int identicalTrees(tree_int* root1, tree_int* root2)
{

    if(!root1 && !root2)
        return 1;
    if( root1!= NULL && root2!=NULL)
        return((root1->data == root2->data) && identicalTrees(root1->left,root2->left) && identicalTrees(root1->right,root2->right));
    return 0;

}

int max(int a ,int b)
{

    if(a>b) return a;
    
    return b;
}

int depth(tree_int* root)
{
    
    if (root == NULL)
        return 0;
    return (max(depth(root->left),depth(root->right)) + 1);

}


void printArray(int array[],int len)
{
int i=0;
for(i=0;i<len;i++){

    printf("%d ",array[i]);
}
}
void printpathRecurse(tree_int* root,int array[],int len)
{

    if (root==NULL)
        return;

    array[len]=root->data;
    len++;

    if((root->left == NULL) && (root->right == NULL))
    {
        printArray(array,len);
        printf("\n");
    }
    else{

        printpathRecurse(root->left,array,len);
        printpathRecurse(root->right,array,len);


    }
    return;



}


void printPaths(tree_int* root)
{

    int a[100];
    printpathRecurse(root,a,0);


}

tree_int* append(tree_int* left, tree_int* root, tree_int* right)
{

    tree_int* start = root;
    if(left != NULL)
    {
        start= left;

        while(left->right != NULL)
            left = left->right;
        left->right = root;


    }

    root->left = left;
    if(right != NULL)
        right->left = root;
    root->right = right;

    return start;

}

tree_int* convertTreeToList(tree_int* root)
{

    tree_int* left;
    tree_int* right;
    tree_int* list;

    if(root ==NULL)
        return NULL;

    
    left = convertTreeToList(root->left);
    right = convertTreeToList(root->right);
    list = append(left,root,right);
    return list;


}
void print_node(tree_int *node)
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


void print_list(tree_int *head)
{
    tree_int *temp = head;
    tree_int *prev;
    if (head == NULL)
        return;

    printf("List in Forward Direction\n");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    
    while(temp!=NULL)
    {
           print_node(temp);
           prev=temp;
           temp=temp->right;
    }

    printf("List in Reverse\n");
    printf("^^^^^^^^^^^^^^^\n");
    while(prev!=NULL)
    {
        print_node(prev);
        prev=prev->left;

    }

}
void print_dlist(tree_int *head)
{
    tree_int *temp = head;
    tree_int *prev;
    if (head == NULL)
        return;

    printf("List in Forward Direction\n");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    
    print_node(temp);
    while(temp->right!=head)
    {

           temp= temp->right;
           print_node(temp);
    }
    prev=temp;
    printf("List in Reverse\n");
    printf("^^^^^^^^^^^^^^^\n");
    print_node(prev);
    prev=prev->left;
    while(temp!=prev)
    {
        print_node(prev);
        prev=prev->left;

    }

}



tree_int* appendtoDl(tree_int* alist, tree_int* blist)
{
    tree_int* temp;
     
    if (alist == NULL) return blist;
    if (blist == NULL) return alist;
    
    temp = blist->left;

    alist->left->right = blist;
    blist->left = alist->left;

    temp->right = alist;
    alist->left = temp;
//    b->right = a;   
    return alist;


}

tree_int* convertTreeToDlist(tree_int* root)
{
    tree_int* leftlist;
    tree_int* rightlist;

    if (root==NULL)
        return NULL;

    leftlist = convertTreeToDlist(root->left);
    rightlist = convertTreeToDlist(root->right);

    root->right = root;
    root->left = root;

    leftlist = appendtoDl(leftlist,root);
    leftlist = appendtoDl(leftlist,rightlist);

    return leftlist;
   

}

void printLevel(tree_int* root,int level)
{
    if(level == 1 &&(root !=NULL)){
        printf("%d ",root->data);
        return;
    }
    else if(root ==NULL)
        return;
    printLevel(root->left,level-1);
    printLevel(root->right,level-1);
    
}

void printLevelTraversal(tree_int* root)
{

    int height,i=0;


    height = depth(root);

    printf("printLevelTraversal:Height = %d\n",height);

    for(i=1;i<=height;i++){
        printLevel(root,i);
    }



}

myqueue* createQueue()
{

    myqueue* q= (myqueue*)malloc(sizeof(myqueue));
    q->rear=NULL;
    q->front = NULL;
    q->size=0;

}

int getQSize(myqueue* q)
{
    if(q==NULL)
        return 0;
    return q->size;
}

void enqueue(myqueue *q,tree_int* tree_nod)
{

   struct queue_node *node=NULL;

   if (q==NULL)
   {
       printf("Create Q first. Q is NULL\n");
       return ;
   }
   node = (struct queue_node*)malloc(sizeof(struct queue_node));
   node->next = NULL;
   node->node = tree_nod;
   if (q->rear == NULL)
   {

        q->rear = node;
        q->front = q->rear;
   }else
   {

        q->rear->next =  node;
        q->rear = node;
   }
   q->size++;


}

tree_int* dequeue(myqueue *q)
{

    tree_int* temp;
    struct queue_node *node;
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
    temp = node->node;

    q->front = q->front->next;
    free(node);
    node = NULL;
    if(q->front == NULL)
    {
        q->rear=NULL;
    }
    q->size--;
    return temp;


}

tree_int* get_front_of_queue(myqueue *q)
{
    tree_int* temp;
    struct queue_node* node;

    if(q==NULL)
    {
        printf("Create q first\n");
        return NULL;
    }
    if(q->front == NULL)
    {
        printf("Empty q\n");
        return NULL;
    }

    node = q->front;
    temp = node->node;

    return temp;
    

}

void printLevelwithQueue(tree_int* root)
{

    myqueue* q = createQueue();
    tree_int* temp=NULL;

    if(root == NULL)
     {
            printf("Tree is null\n");
            return;
     }
     
    enqueue(q,root);
    while((q->front)!= NULL)
    {
        temp = dequeue(q);
        printf("%d ",temp->data);
        if(temp->left!=NULL)
            enqueue(q,temp->left);
        if(temp->right != NULL)
            enqueue(q,temp->right);

    }
       
}


void printSpiral(tree_int* root)
{

    mystack* s1 = NULL;
    mystack* s2 = NULL;
    tree_int* temp;

    push(&s2,root);

    while(s2!=NULL || s1!=NULL)
    {

        while(s2!= NULL)
        {
            
            temp = pop(&s2);
            printf(" %d ",temp->data);
            if(temp->right != NULL)
                push(&s1,temp->right);
            if(temp->left != NULL)
                push(&s1,temp->left);
            
        }
        while(s1!=NULL)
        {
            temp=pop(&s1);
            printf(" %d ",temp->data);
            if(temp->left != NULL)
                push(&s2, temp->left);
            if(temp->right != NULL)
                push(&s2,temp->right);

        }



    }


}

int checkSumOfChildren(tree_int* root)
{

    int leftdata =0;
    int rightdata = 0;

  if(root == NULL || ((root->left) && (root->right)))
      return 1;
  if(root->left != NULL)
        leftdata = root->left->data;
  if(root->right != NULL)
       rightdata = root->right->data;

  return ((root->data == (leftdata + rightdata)) && (checkSumOfChildren(root->left) && checkSumOfChildren(root->right)));

        

}


void adjustTreetoSumofChildres(tree_int* root)
{
    
     int leftdata =0;
     int rightdata = 0;
     int diff;
     static mystack* s=NULL;
     tree_int* temp;
    if(root == NULL)
        return;
     if(root->left == NULL && root->right == NULL)
        return;

    if(root->left != NULL)
        leftdata = root->left->data;
    if(root->right != NULL)
        rightdata = root->right->data;

    diff = root->data -(leftdata + rightdata);
    printf("Diff =%d\n",diff);
    if(diff == 0)
    {
        /*do nothing */

    }
    else if(diff <0)
    {
        root->data = root->data - diff;
        printf("stack = %x\n", s);
        while(s != NULL){

            temp = pop(&s);
            printf("Adjusting [%x]\n",temp); 
            temp->data = temp->data -diff;
        }


    }
    else
    {
        if(root->left != NULL)
            root->left->data = root->left->data + diff;
        else
            root->right->data = root->right->data +diff;
    }
    printf("stack=%x\n",s);
    push(&s,root);
    adjustTreetoSumofChildres(root->left);
    adjustTreetoSumofChildres(root->right);
    pop(&s);

}

int diameterofTree(tree_int* root, int *height)
{

    int lh=0,rh=0;
    int ld,rd;

    if(root==NULL){

        *height = 0;
        return 0;
    }

    ld = diameterofTree(root->left,&lh);
    rd = diameterofTree(root->left,&rh);

    *height = max(lh,rh)+1;

    return(max((lh+rh+1),max(ld,rd)));


}

unsigned int absdiff(int a,int b)
{
    int diff = a-b;
    if(diff<0) {
        diff = diff*(-1);
    }
    
    return diff;

}

int isBalanced(tree_int* root, int* height)
{

    int lh,rh;
    int lb,rb;
    unsigned int diff;
    if(root==NULL)
    {
        *height = 0;
        return 1;
    }

    lb=isBalanced(root->left ,&lh);
    rb=isBalanced(root->right,&rh);

    *height = max(lh,rh)+1;
    diff = abs(lh-rh);
   

    return(lb && rb && (diff<=1));



}

void inorderMorrisTraversal(tree_int* root)
{

    tree_int* pre;
    tree_int* current;

    if(root == NULL)
        return;

    current = root;
    while(current != NULL)
    {   
       if(current->left ==NULL)
       {
           printf("%d ",current->data);
           current=current->right;
       }
       else
       {
            pre = current->left;
            while((pre->right != NULL) && (pre->right != current))
                pre = pre->right;

            if(pre->right == NULL){
                pre->right = current;
                current = current->left;
            }
            else
            {
                printf("%d ",current->data);
                pre->right = NULL;
                current = current->right;

            }

       }
   }/*while*/

}
int checkSum(tree_int* root,int a[],int level,int sum)
{
    int temp=0,i;

    if(root==NULL)
    {
        for(i=0;i<level;i++)
            temp+=a[i];

        if(temp==sum){
            return( 1);
        }else
        {
            return( 0);
        }

    }
    a[level]=root->data;
    level++;
    return(checkSum(root->left,a,level,sum) || checkSum(root->right,a,level,sum));

}


void checkSumofPathisNumber(tree_int* root,int num)
{

    int a[100]={0};
    int val;
    val= checkSum(root,a,0,num);
    if (val == 1)
        printf("Sum of one of the path is number\n");
    else
        printf("There are no paths with their sum equal to the number give\n");
    return;


}

tree_int* convertArrayToTree(int in[],int pre[],int instrt,int inlen,int *prestrt)
{

    int temp;
    int i,k;
    tree_int* mytree=NULL;
    if(inlen == 0 || (instrt >=inlen))
        return NULL;

    temp = pre[*prestrt];

   (*prestrt)++;

    for(i=instrt;i<inlen;i++)
    {
        if(temp == in[i])
        {
            mytree = (tree_int*)newNode(temp);
            mytree->left = convertArrayToTree(in,pre,instrt,i,prestrt);
            mytree->right = convertArrayToTree(in,pre,i+1,inlen,prestrt);

            return mytree;

        }
    }
    return NULL;

}


tree_int* doubleTree(tree_int* root)
{
    tree_int* leftsub;

    if(root == NULL)
        return NULL;


    leftsub = root->left;

    root->left = (tree_int*)newNode(root->data);
    root->left->left = (tree_int*)doubleTree(leftsub);
    root->right = (tree_int*)doubleTree(root->right);
    
    return root;

}

int isFoldable(tree_int* a, tree_int* b)

{

    if( !a && !b)
        return 1;
    if(!a || !b)
        return 0;

    return(isFoldable(a->right,b->left) && isFoldable(a->left,b->right));

}
void checkFoldable(tree_int* root)
{

    int foldable=0;

    if (root==NULL)
    {
        printf("Foldable. \n");
        return ;
    }
    foldable = isFoldable(root->left,root->right);
    (foldable==1)?printf("Foldable.\n"):printf("Not foldable\n");
    return;

}

int getLevel(tree_int* root, int data,int level)
{

    int ret;
    if(root == NULL)
        return 0;

    if(root->data == data)
    {
        return level;
    }
    ret =  getLevel(root->left,data,level+1);
    if (ret != 0)
        return ret;
    ret= getLevel(root->right,data,level+1);
    return ret;


}

int printAncestors(tree_int* root, int value)
{

    if(root==NULL)
        return 0;
    if(root->data == value)
        return 1;

    if(printAncestors(root->left,value) || printAncestors(root->right,value))
    {
        printf("%d ",root->data);
        return 1;

    }
    return 0;

}

void CheckSumOfChildren(tree_int* root)
{
    int sum;
    if(root == NULL){
        printf("\nSum Tree\n");
        return;
    }
    sum  =checkSumTree(root); 
    if(root->data == sum)
    {
        printf("\nSum Tree\n");
    }
    else
    {
        printf("\nsum == %d\n",sum);
        printf("\nNot a sum tree\n");
    }

}

int checkSumTree(tree_int* root)
{

    int leftsum=0;
    int rightsum=0;
    int sum;

    if(root == NULL )
        return 0;
    if(root->left== NULL && root->right==NULL)
        return root->data;

    leftsum = checkSumTree(root->left);
    rightsum = checkSumTree(root->right);
    
    sum = leftsum+rightsum;
    
        
    printf("\nsum =%d\n",sum);
    return sum;
}

int isALeaf(tree_int* root)
{
    int re=0;
    if((root->left == NULL) && (root->right == NULL))
        re =1;
    return re;
}

int isSumTree(tree_int* root)
{
    int ls;
    int rs;
    
    if((root == NULL) ||(!(root->left) && !(root->right)))
    {
        return 1;
    }
    if( isSumTree(root->left) && isSumTree(root->right))
    {
            if (!(root->left))
                ls=0;
            else if( isALeaf(root->left)){
                ls = root->left->data;
            }
            else {
                ls= 2*(root->left->data);
            }
                

             if (!(root->right))
                rs=0;
            else if( isALeaf(root->right))
                rs = root->right->data;
            else 
                rs= 2*(root->right->data);


            if(root->data == (ls + rs))
                return 1;
            
    }
    return 0;
}
int preOrderFindTree(tree_int* root,tree_int* sub)
{
    if(!(root) && !(sub))
        return 1;
    if(!(root) || !(sub))
            return 0;

    if(root->data == sub->data)
    {
        return (preOrderFindTree(root->left,sub->left) && preOrderFindTree(root->right,sub->right));
    }
    else
        return 0;

}

isSubTreePresent(tree_int* root, tree_int* sub)
{
    tree_int *cnode;
    int a;

    if(root == NULL)
        return 0;
    if(sub == NULL)
        return 1;

    a = preOrderFindTree(root,sub);
    if(a)
        return 1;
    return(preOrderFindTree(root->left,sub) || preOrderFindTree(root->right,sub));

}

connqueue* createConnQueue()
{
    connqueue* q = (connqueue*)malloc(sizeof(connqueue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void conn_enqueue(connqueue* q ,tree_sp_int* root,int level)
{
    struct newqueue* qnode ;
    if(q== NULL)
        return;

    qnode = (struct newqueue*)malloc(sizeof(struct newqueue));
    qnode->node = root;
    qnode->level =level;
    qnode->next = NULL;
    if(q->rear == NULL)
    {
        q->front =  qnode;
        q->rear = qnode;
    }
    else
    {
        q->rear->next = qnode;
        q->rear = qnode;
    }
    return;

    
}
tree_sp_int* conn_dequeue(connqueue* q, int* level)
{
    tree_sp_int* treenode;
    struct newqueue *temp;
    if(q==NULL)
        return NULL;
    if(q->front == NULL)
        return NULL;
    treenode = q->front->node;
    *level = q->front->level;
    temp = q->front;
    q->front = q->front->next;
    if (!(q->front))
        q->rear = NULL;
    free(temp);
    return treenode;
}
int peek_level_conn_queue(connqueue* q)
{
    if(q== NULL)
        return -1;
    if(q->front == NULL)
        return -1;
    
    return (q->front->level);

}

void ConnectToNext(tree_sp_int* root)
{

    connqueue *q = createConnQueue();
    int level=1,prev_level=0;
    tree_sp_int* temp =root;
    tree_sp_int* prev=NULL;
    if(root == NULL)
        printf("Connection is not possible\n");

    conn_enqueue(q,root,level);
    while(q->front != NULL)
    {
            temp = conn_dequeue(q,&level);

            if(prev_level == level){
                if(prev)
                    prev->conn = temp;
            }
            prev= temp;
            prev_level = level;

           if(temp->left != NULL)
            {
                conn_enqueue(q,temp->left,level+1);

            }
            if(temp->right != NULL)
            {
                conn_enqueue(q,temp->right,level+1);
            }
    }
}
tree_sp_int* getRealRight(tree_sp_int* root)
{

    tree_sp_int* temp;
    if(root->conn == NULL)
        return NULL;
    
    temp = root->conn;
//    printf("Calling real right for %d\n",root->right->data);
    while(temp)
    {
        if(temp->left != NULL){
            return temp->left;
        }
        if(temp->right != NULL){
            return temp->right;
        }
        temp = temp->conn;
        printf("next temp=%p\n",temp);
    }
    return NULL;
}
tree_sp_int* getRealLeft(tree_sp_int* root)
{
    tree_sp_int* temp;
    printf("Calling real left for %d\n",root->left->data);
    if(root->right)
        return root->right;
    if(root->conn == NULL)
        return NULL;
    temp = root->conn;
    while(temp)
    {
        if(temp->left != NULL){
            return temp->left;
        }
        if(temp->right != NULL){
            return temp->right;
        }
        temp = temp->conn;
        printf("next temp=%p\n",temp);
    }
    return NULL;
}



void ConnectToNextPreOrder(tree_sp_int* root)
{
    tree_sp_int* temp;
    if(root == NULL)
    {
        printf("Connection is not possible\n");
        return;
    }
    if(!(root->left) && !(root->right))
    {
        return;
    }
    
    temp = root;
    /* not required if we want to process only complete binary tree*/
    while(temp!=NULL){
        ConnectToNextPreOrder(temp->conn);
        temp = temp->conn;
    }

    root->left->conn = getRealLeft(root);
    root->right->conn = getRealRight(root);

    ConnectToNextPreOrder(root->left);
//    ConnectToNextPreOrder(root->right); Not required. Required only in the case if we want to process only complete binary tree

}

void ConnectNextPreorderLoop(tree_sp_int* root)
{
    tree_sp_int* p;
    tree_sp_int* q;

    if(root==NULL)
        return;
    if(!(root->left) && !(root->right))
    {
        return;
    }
    p=root;
    p->conn = NULL;
    while(p!=NULL)
    {
        q=p;
        while(q)
        {
            if(q->left)
                q->left->conn = getRealLeft(q);
            if(q->right)
                q->right->conn = getRealRight(q);

            q= q->conn;
        }
        if(p->left)
            p=p->left;
        else if(p->right)
            p=p->right;
        else
            p=getRealRight(p);

    }


}

void ConvertToSumTree(tree_int* root)
{
    int i;
    i=ChangeToSumTree( root);
    printf("converted.Root data is %d\n",i);
}

int ChangeToSumTree(tree_int* root)
{

    int ls;
    int rs;
    int temp;

    if(root==NULL)
        return 0;
    
    ls = ChangeToSumTree(root->left);
    rs = ChangeToSumTree(root->right);
    temp=root->data;
    root->data =  ls+rs;
    temp=temp+root->data;
    return (temp);
    

}

hash* createHash()
{
    hash *hm = (hash*) malloc(sizeof(hash));
    hm->start = NULL;
    return hm;
}
void printHashEntries(hash* hm)
{
    hashmap *temp=hm->start;
    printf("\n");
    while(temp !=NULL)
    {
        printf("%d ",temp->sum);
        temp=temp->next;

    }
    printf("\n");
}
int getKeyHashSum(hash* hm, int hd)
{
    hashmap* temp;
    if(hm->start == NULL)
        return 0;
    temp = hm->start;
    while(temp)
    {

        if(hd == temp->hd)
            return temp->sum;
        temp=temp->next;
    }
    return 0;


}
void putKeyHashSum(hash* hm,int hd,int sum)
{
    hashmap** temp;
    
    temp=&(hm->start);
    while(*temp!=NULL)
    {
          if((*temp)->hd == hd)
              break;
           temp = &((*temp)->next);
    }
    if(*temp == NULL){

        *temp = (hashmap*)malloc(sizeof(hashmap));
        (*temp)->next = NULL;
    }
   
    (*temp)->hd = hd;
    (*temp)->sum = sum;
    

}

void FindVerticalSum(tree_int* root,hash* hm,int hd)
{
    static int index = 0;
    int temp;
    if(root == NULL)
        return;

    FindVerticalSum(root->left,hm,hd-1);
    temp=getKeyHashSum(hm,hd);
    putKeyHashSum(hm,hd,temp+root->data);
    FindVerticalSum(root->right,hm,hd+1);
    
}
void CalculateVerticalSum(tree_int* root)
{

    hash* hm=createHash();
        
    FindVerticalSum(root,hm,0);
    printf("Vertical Sum\n");
    printHashEntries(hm);


}
int maxofArray(int arr[],int start,int end,int* offset)
{
    int i;
    
    int max=arr[start];
    *offset = start;
    for(i=start;i<end;i++)
    {
        if(arr[i]>max){
            max=arr[i];
            *offset = i;
        }
    }
    return max;


}

tree_int* makeTreeFromInorderArray(int inor[],int instart,int inlen)
{

    int temprootVal;
    int index;
    tree_int* mytree;

    if(instart>=inlen || inlen==0)
        return NULL;

    temprootVal=maxofArray(inor,instart,inlen,&index);
    mytree =(tree_int*)newNode(temprootVal);

    mytree->left = makeTreeFromInorderArray(inor,instart,index);
    mytree->right = makeTreeFromInorderArray(inor,index+1,inlen);

    return mytree;
}

    
tree_int* makeTreeFromSpecialPreorderArrays(int preor[],int* prestart,int prelen,char prop[])
{

     tree_int* mytree;
     if(prelen ==0 || (*prestart) >=prelen)
         return NULL;
    
     (*prestart)++;
     mytree = (tree_int*)newNode(preor[*prestart]);

     if(prop[*prestart] == 'L')
     {
         mytree->left = NULL;
         mytree->right = NULL;
         return mytree;
     }
     else
     {
            mytree->left = (tree_int*)makeTreeFromSpecialPreorderArrays(preor,prestart,prelen,prop);
            mytree->right =(tree_int*)makeTreeFromSpecialPreorderArrays(preor,prestart,prelen,prop);
     }
        
     return mytree;

}

int isCompleteTree(tree_int* root)
{

    if(!root)
        return 1;
    if(!(root->left) && !(root->right))
    {
        return 1;
    }
    if((root->left) && !(root->right))
    {
        return 1;
    }
    if(!(root->left) && (root->right))
    {
        return 0;
    }
    return(isCompleteTree(root->left) && isCompleteTree(root->right));



}

void printLeftBoundary(tree_int* root)
{
    if(root)
    {
        if(root->left)
        {
            printf("%d ",root->data);
            printLeftBoundary(root->left);
        }
        else if(root->right)
        {
            printf("%d ",root->data);
            printLeftBoundary(root->right);
        }

    }
}
void printLeaves(tree_int* root)
{
    if(root)
    {
        if(((root->left)==NULL ) && (root->right ==NULL))
        {
            printf("%d ",root->data);
            return;
        }
        else
        {
            printLeaves(root->left);
            printLeaves(root->right);
        }
    }
}
void printRightBoundary(tree_int* root)
{
    if(root)
    {
        if(root->right)
        {
            printRightBoundary(root->right);
            printf("%d ",root->data);

        }
        else if(root->left)
        {
            printRightBoundary(root->left);
            printf("%d ",root->data);

        }
    }
}

void printBoundary(tree_int* root)
{
    if(root)
    {
        printf("%d ",root->data);
        printLeftBoundary(root->left);
        printLeaves(root);
        printRightBoundary(root->right);

    }

}


tree_int* ConvertPrePostArraysToTree(int pre[],int post[],int poststrt,int postlen,int* preind)
{

    int temp;
    tree_int* mytree=NULL;
    int i=0;

    if(poststrt > postlen )
    {
        return NULL;
       
    }

    temp = pre[*preind];
    mytree = (tree_int*)newNode(temp);
    temp = pre[(*preind)+1];
   (*preind)++;
    for(i=poststrt;i<postlen;i++)
    {
        if(temp == post[i]){
                mytree->left = ConvertPrePostArraysToTree(pre,post,poststrt,i,preind);
                mytree->right = ConvertPrePostArraysToTree(pre,post,i+1,postlen,preind);
               return mytree; 
        }
    }

   return mytree;

}

void preorderIterative(tree_int* root)
{
    mystack* stack=NULL;

    if(root == NULL)
        return;

    while(1)
    {
        if(root != NULL)
        {
            printf("%d ",root->data);
            push(&stack,root);
            root = root->left;
        }
        else
        {
            if(stack == NULL)
            {
                return;
            }
            root = pop(&stack);
            root=root->right;

        }
    }


}



void preOrderMorrisTraversal(tree_int* root)
{

    tree_int* current = root;
    tree_int* pre;

    if(root == NULL)
        return;

    while(current != NULL)
    {
        if(current->left !=NULL)
        {
            pre = current->left;

            while((pre->right != NULL)&&(pre->right!=current))
            {
    
                    pre= pre->right;
            }
            if(pre->right == NULL)
            {

                printf("%d ",current->data);
                pre->right = current;
                current = current->left;

            }
            else if(pre->right == current)
            {
                pre->right = NULL;
                current = current->right;
            }
        }
        else if(current->left == NULL)
        {
            printf("%d ",current->data);
            current=current->right;

        }
    }
    


}


void makeCompleteBinaryTree(tree_int **root, int number,myqueue *q)
{

    tree_int* peektree;
    tree_int* temp;
    if(*root == NULL)
    {
        *root = (tree_int*)newNode(number);
        enqueue(q,*root);
        return;
    }
    peektree = get_front_of_queue(q);

    if(peektree->left == NULL)
    {
        temp = (tree_int*)newNode(number);
        peektree->left = temp;
    }
    else if(peektree->right == NULL)
    {
        temp = (tree_int*)newNode(number);
        peektree->right = temp;
        dequeue(q);
    }
    enqueue(q,temp); 


}

tst* newTSTNode(char ch)
{
    tst* node = (tst*) malloc(sizeof(tst));
    node->left = NULL;
    node->right = NULL;
    node->eq=NULL;
    node->data = ch;
    node->eof = 0;
    return node;
}
void insertTST(tst** root, char* word)
{


    if(!(*root))
        *root = (tst*)newTSTNode(*word);

    if(*word < (*root)->data )
            insertTST(&((*root)->left),word);
    else if(*word > (*root)->data)
        insertTST(&((*root)->right),word);
    else
    {
        if(*(word+1))
        {

            insertTST(&((*root)->eq),(word+1));
        }
        else
        {

            (*root)->eof = 1;
        }
    }

}

void TraverseTST(tst* root, char* buf, int depth)
{
    if(root)
    {
            TraverseTST(root->left,buf,depth);
            buf[depth] = root->data;
            if(root->eof == 1)
            {
                
                buf[depth+1]='\0';
                printf("%s\n",buf);
                 
            }
            TraverseTST(root->eq,buf,depth+1);
            TraverseTST(root->right,buf,depth);

    }
    

}

int SearchTST(tst* root, char *word)
{

    if(root)
    {
        if((*word) < (root)->data)
        {
                return (SearchTST((root)->left,word));
        }
        else if((*word) > (root)->data)
        {
                return (SearchTST((root)->right,word));
        }
        else
        {
            if(*(word+1) == '\0')
            {
                return root->eof;
            }
            else
            {
                return (SearchTST((root)->eq,(word+1)));
            }
        }

    }
    return 0;
}

int getmid(int start,int end)
{

    int mid;
    mid = start +(end-start)/2 ;
    return mid;
       
}

int constructSTutil(int arr[],int ast,int aend, int* st, int idx)
{

    int mid;
    if(ast == aend)
    {
        st[idx] = arr[ast];
        return arr[ast];
    }

    mid = getmid(ast,aend);

    st[idx] = constructSTutil(arr,ast,mid,st,(2*idx+1)) +
                constructSTutil(arr,mid+1,aend,st,(2*idx+2));
    return st[idx];



}


int* makeSegmentTreeImpl(int arr[],int n,int *segsize)
{
    
    int x = (int) ceil(log2(n));

    int size =(int) 2*pow(2,x) - 1;

    int *st = (int*) calloc(size,1);

    constructSTutil(arr,0,n-1,st,0);

    *segsize = size;
    return st;

   
   

}
int getSumofRangeUtil(int *segtree,int firstidx,int lastidx,int rangeSt,int rangeEn,int index)
{
    int mid;
    if(rangeSt <= firstidx && rangeEn >= lastidx)
    {
        return segtree[index];
    }
    if(firstidx > rangeEn || lastidx < rangeSt)
    {
        return 0;
    }
    mid = getmid(firstidx,lastidx);
    return(getSumofRangeUtil(segtree,firstidx,mid,rangeSt,rangeEn,(2*index +1)) +
            getSumofRangeUtil(segtree,mid+1,lastidx,rangeSt,rangeEn,(2*index+2)));

    
}
int getSumofRange(int* segtree, int sizeofarr, int rangeSt, int rangeEn)
{

    if(!(rangeSt>=0  && rangeEn <=(sizeofarr-1)))
    {
        printf("Invalid range\n");
        return -1;
    }
    return (getSumofRangeUtil(segtree,0,sizeofarr-1,rangeSt,rangeEn,0));
}
void printSegmentTree(int* st, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",*(st+i));

    }
    printf("\n");
    return;
}
void updateSegmentTreeUtil(int* segtree,int arr[],int strt,int end,int idx,int val,int sidx)
{
    int mid ;
    if(idx <= end && idx>=strt)
    {
        segtree[sidx] = segtree[sidx]+val;
    }
    else{
        return;
    }
    if (idx == strt && idx== end)
    {
        return;
    }
    mid = getmid(strt,end);
    updateSegmentTreeUtil(segtree,arr,strt,mid,idx,val,(2*sidx+1));
    updateSegmentTreeUtil(segtree,arr,mid+1,end,idx,val,(2*sidx+2));

}
void updateSegmentTreeArrayVal(int* segtree,int arr[],int size,int idx, int val)
{
    if(idx  >=size)
    {
        printf("Invalid index of array\n");
        return ;
    }

    updateSegmentTreeUtil(segtree, arr,0,size-1,idx,val,0);
    
}
void API_makeSegmentTree()
{

    int array[]={1, 3, 5, 7, 9, 11};
    int size = sizeof(array)/sizeof(array[0]);
    int *st;
    int segsize;
    int sum;
    int index;

    st = makeSegmentTreeImpl(array,size,&segsize);

    printSegmentTree(st,segsize);


    sum = getSumofRange(st,size,1,3);
    printf("Sum of range 1 to 3 is %d\n",sum);


    sum = getSumofRange(st,size,0,4);
    printf("Sum of range 0 to 4 is %d\n",sum);


    printf("Update a value in segment tree\n");
    index = 5;
    /* update 6th element in the array by adding value 4 */
    updateSegmentTreeArrayVal(st,array,size,index,4);
        

    printSegmentTree(st,segsize);
}


int LargestIndSet(tree_int_liss* root)
{
    int myliss;
    int childliss;

    if(root==NULL)
        return 0;
    if(root->liss !=0)
    {
        return root->liss;
    }


    myliss =1;

    
    if(root->left != NULL){

        myliss += LargestIndSet(root->left->left) + LargestIndSet(root->left->right);
    }

    if(root->right != NULL) {
        myliss += LargestIndSet(root->right->left) + LargestIndSet(root->right->right);
    }

    childliss = LargestIndSet(root->left) + LargestIndSet(root->right);
    root->liss = max(myliss,childliss);
    return (root->liss);

}



void postOrderIterativeTraversal(tree_int* root)
{
    mystack *s1=NULL;
    mystack *s2=NULL;
    tree_int * temp;

    push(&s1,root);

    while(s1!=NULL)
    {
        temp = pop(&s1);
        push(&s2,temp);
        if(temp->left != NULL)
        {
            push(&s1,temp->left);
        }
        if(temp->right)
        {
            push(&s1,temp->right);
        }
    }
    while(s2!=NULL)
    {
        temp=pop(&s2);
        printf("%d ",temp->data);
    }

}


void reverseLevelOrderTraversal(tree_int* root)
{
    myqueue* q;
    mystack* s1=NULL;
    tree_int* temp;

    q = (myqueue*)createQueue();
    enqueue(q,root);
    while(q->front != NULL)
    {
            temp = dequeue(q);
            push(&s1,temp);
            if(temp->right !=NULL){
            enqueue(q,temp->right);
            }
            if(temp->left !=NULL) {
            enqueue(q,temp->left);
            }
    }
    while(s1)
    {
        temp = pop(&s1);
        printf("%d ",temp->data);
    }
    printf("\n");


}


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
        printf("Created node%d:%p\n",idx,node);
        node->data = dat;
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




tree_int* treeFromLinkedList( mylist* list)
{
    myqueue* q=createQueue();
    tree_int* temp;
    tree_int* tree=NULL;

    if(list == NULL)
        return tree;

    tree = newNode(list->data);
    enqueue(q,tree);
    
    while(q->front !=NULL)
    {

        temp = dequeue(q);
        if(list && list->next) {
            temp->left = newNode(list->next->data);
            enqueue(q,temp->left);
        }
        if(list && list->next && list->next->next) {
            temp->right = newNode(list->next->next->data);
            enqueue(q,temp->right);
        }
        if(list && list->next)
        {
            list = list->next->next;
        }

    }

   return tree;
}
weight_tree* newWeightedNode(int indweight,int weightsum,int num)
{
    weight_tree* node = (weight_tree*)malloc(sizeof(weight_tree));
    node->weight = indweight;
    node->weightsum = weightsum;
    node->num = num;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void getMaxWeight(weight_tree* tree,int *max)
{

    if(tree==NULL)
        return;

    if( tree->weightsum > *max)
    {
        *max = tree->weightsum;
    }
    getMaxWeight(tree->left,max);
    getMaxWeight(tree->right,max);


}


weight_tree* insertNodetoWeightedBST(weight_tree* tree ,int num, int weight,int weightsum)
{
    weight_tree* temp = tree;
    int max1=0;
    int max2=0;

    if(tree == NULL)
    {
        return(newWeightedNode(weight,weightsum,num));
    }
    if(num < tree->num)
    {
        tree->left = insertNodetoWeightedBST(tree->left,num,weight,weight);
    }
    else if(num == tree->num)
    {
        tree->left = insertNodetoWeightedBST(tree->left,num,weight,(weight+tree->weightsum-tree->weight));
    }
    else if(num >tree->num)
    {
        if(tree->left)
        {
             getMaxWeight(tree,&max1);
             getMaxWeight(tree,&max2);
        }
        if(tree->left &&(max2 > max1))

        {
                tree->left = insertNodetoWeightedBST(tree->left,num,weight,weight);
        }
        else
        {
            tree->right = insertNodetoWeightedBST(tree->right,num,weight,weight+tree->weightsum);
        }

    }
    return tree;

}

void printpreorderWeightedTree(weight_tree* tree)
{
    if(tree == NULL)
        return;
    printf("%d %d %d :   ",tree->num,tree->weight,tree->weightsum);
    printpreorderWeightedTree(tree->left);
    printpreorderWeightedTree(tree->right);


}
void printinorderWeightedTree(weight_tree* tree)
{
    if(tree == NULL)
        return;
    printinorderWeightedTree(tree->left);
    printf("%d %d %d :   ",tree->num,tree->weight,tree->weightsum);
    printinorderWeightedTree(tree->right);


}



int findMaxWeight(int num[],int weight[],int size)
{

   int i;
   int max=0;
   weight_tree *tree=NULL;

   for(i=0;i<size;i++)
   {
       tree = insertNodetoWeightedBST(tree,num[i],weight[i],weight[i]);
   }
   
   /* debug*/
   printf("created pre order tree\n");
   printpreorderWeightedTree(tree);
   printf("\n");
   printf("created in order tree\n");
   printinorderWeightedTree(tree);
   printf("\n");
    /*debug */
   getMaxWeight(tree,&max);

   return max;
    
}

int constructSTforMax(int arr[],int start,int end,int* st, int stidx)
{
    int mid;
    if(start==end)
    {
        st[stidx] = arr[start];
        return arr[start];
    }
    mid = getmid(start,end);
    st[stidx] = max(constructSTforMax(arr,start,mid,st,2*stidx+1), constructSTforMax(arr,mid+1,end,st,2*stidx+2));
    return st[stidx];
}

int* constructSTForMaxUtil(int arr[],int n,int *segsize)
{
    int stsize = 2*n - 1;
    *segsize = stsize;
    int *st;
    st=(int*)calloc(stsize,sizeof(int));
    
    constructSTforMax( arr,0,n-1,st,0);

    return st;
}

int getMaxOnaRangeUtil(int* st, int rangest,int rangeen,int strt,int end, int stidx)
{
    int max2;
    int mid;

    if(rangest<=strt && rangeen>=end)
    {

        return st[stidx];
        
    }
    if(strt > rangeen || end < rangest)
    {
        return INT_MIN;
    }

        mid = getmid(strt,end);
    max2 = max(getMaxOnaRangeUtil(st,rangest,rangeen,strt,mid,2*stidx+1),getMaxOnaRangeUtil(st,rangest,rangeen,mid+1,end,2*stidx+2));
    return max2;

}
int getmaxbetween(int* st,int rangest, int rangeen,int size)

{
    
    if(rangest <0 && rangeen >= size)
    {
        return INT_MIN;
    }

    return(getMaxOnaRangeUtil(st,rangest,rangeen,0,size-1,0));

}
void updateArrayIndexUtilImpl(int* st, int strt, int end, int upidx, int stidx,int val)
{
    int mid;
    if(upidx<=end && upidx >=strt)
    {
        if(st[stidx] < val){

            st[stidx] = val;
        }

    }
    else
    {
        return;
    }
    if(upidx == strt && upidx == end)
    {
        st[stidx] = val;
        return;
    }
    mid = getmid(strt,end);
    updateArrayIndexUtilImpl(st,strt,mid,upidx,2*stidx+1,val);
    updateArrayIndexUtilImpl(st,mid+1,end,upidx,2*stidx+1,val);
    return;

}

void updateArrayIndexUtil(int arr[],int size,int* st,int upidx, int val)
{
    if(upidx >=size)
        return ;
    arr[upidx]=val;
    updateArrayIndexUtilImpl(st,0,size-1,upidx,0,val);
}
int API_maxbetweenIndices(int arr[], int i,int j, int size)
{
    int stsize;
    int* st;
    int max;
    int range;
    int strange;
    int enrange;
    int upidx;
    int val;
    
    st=constructSTForMaxUtil(arr,size,&stsize);

    printf("Get max\n");
    printf("Enter 2 ranges: [0 to %d]\n",size-1);
    printf("Enter start range:\n");
    scanf("%d",&strange);

    printf("Enter end range:\n");
    scanf("%d",&enrange);

    max = getmaxbetween(st,strange,enrange,size);
    printf("Max:%d\n",max);

    printf("Enter the array index to be updated\n");
    scanf("%d",&upidx);
    printf("Enter the value to be updated\n");
    scanf("%d",&val);

    updateArrayIndexUtil(arr,size,st,upidx,val);

    printf("Get max\n");
    printf("Enter 2 ranges: [0 to %d]\n",size-1);
    printf("Enter start range:\n");
    scanf("%d",&strange);

    printf("Enter end range:\n");
    scanf("%d",&enrange);

    max = getmaxbetween(st,strange,enrange,size);
    printf("Max:%d\n",max);


    return max; 
}


alph_tree* makeAlphNode(int arr[],int start,int count, char* curr)
{
    alph_tree* node=NULL;
    int temp;
    if(arr[start]== 0 && count==1) 
        return NULL;
   
    temp = arr[start]*10 + arr[start+1];
    if(temp>26 && count ==2)
        return NULL;

    node = (alph_tree*)malloc(sizeof(alph_tree));
    node->left = NULL;
    node->right = NULL;
    memset(node->str,'\0',26);
    if(curr)
    strcpy(node->str,curr);
    if(count == 1 ){
        strcat(node->str,lookup[arr[start]]);
    }
    else if(count==2){
        strcat(node->str,lookup[temp]);
    }
    else{
        /* do nothing */
    }

   node->startindex=start+count;
   return node;
 
}
alph_tree* makeTree(int arr[],int size, int start,int count,char* curr)
{

    alph_tree* node = NULL;
    if(start >= size || (start+count)> size)
    {
        return NULL;
    }

    node = makeAlphNode(arr,start,count,curr);
    if(node){
        node->left=makeTree(arr,size,node->startindex,1,node->str);
        node->right = makeTree(arr,size,node->startindex,2,node->str);
    }
    return node;
}
void printLeaf(alph_tree* root)
{
    if(root == NULL)
    {
        return ;
    }
    if((root->left==NULL) && (root->right ==NULL))
    {
        printf("%s ",root->str);
        return;
    }
    printLeaf(root->left);
    printLeaf(root->right);

}

void arrayToString(int arr[],int size)
{

    alph_tree* root = NULL;
    char *temp='\0';
    root = makeTree(arr,size,0,0,temp);
    
    printLeaf(root);

}


int heightofTreeItr(tree_int* root)
{
    int height=0;
    int qsize;
    tree_int* node;
    if(!root)
        return 0;
    myqueue* q= createQueue();

    enqueue(q,root);
    while(1)
    {
        qsize= getQSize(q);
        if(qsize==0)
        {
            return height;
        }   
        height++;

        while(qsize!=0)
        {
            node=dequeue(q);
            if(node->left !=NULL)
            {
                enqueue(q,node->left);
            }
            if(node->right!=NULL)
            {
                enqueue(q,node->right);
            }
            qsize--;
            
        }

    }


}

void createCustomTree()
{


}

void printAncestorsItr(tree_int* root, int value)
{
    mystack* s1=NULL;
    tree_int* temp;
    tree_int* node;

    while(1)
    {
        while(root!=NULL && (root->data != value))
        {
            push(&s1,root);
            root = root->left;
        }
       
        if((root) && (root->data = value))
        {
            while(s1)
            {
                printf("%d ",(pop(&s1))->data);
            }
            return ;
        }
        if(s1 != NULL)
            temp = peek(s1);
        else
            return;

        while((temp) && temp->right == NULL)
        {
            node = pop(&s1);
            temp = peek(s1);
            while((temp) && node == temp->right)
            {
                node = pop(&s1);

            }
        }
        if(temp == NULL)
            return;
        root = temp->right;

    }


}

int searchroot(int in[], int preval, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(in[i]==preval)
            return i;
    }
    return -1;
}

void printPostOrderFronInPre(int in[],int pre[],int size)
{
    int  rootpos;
    if(size == 0)
            return;
    rootpos  = searchroot(in,pre[0],size);
    if(rootpos==-1)
        return;
    if(rootpos!=0)
    {
        printPostOrderFronInPre(in,pre+1,rootpos);
    }
    if(rootpos!=size-1)
    {
        printPostOrderFronInPre(in+rootpos+1,pre+rootpos+1,(size-rootpos-1));
    }
    printf("%d ",pre[0]);
    return;
}

int isOdd(int number)
{
    if((number)%2)
        return 1;

    else 
        return 0;
}
int maximumOddDepth(tree_int* root,int level)
{
    int depth;
    if(root==NULL)
            return 0;
    if(root->left == NULL && root->right==NULL && level&1)
    {
        return level;
    }
    
    depth = max(maximumOddDepth(root->left,level+1),maximumOddDepth(root->right,level+1));
     
        
}

int checkAllLeafsAreSameLevel(tree_int* root,int level,int* leaflevel)
{
    if(root==NULL)
        return 1;
    if(root->left==NULL && root->right==NULL)
    {
        if(*leaflevel == 0)
        {
            *leaflevel = level;
            return 1;
        }
        else
        {
            return(level == *leaflevel);
        }
    }
    return(checkAllLeafsAreSameLevel(root->left,level+1,leaflevel) &&
            checkAllLeafsAreSameLevel(root->right,level+1,leaflevel));
}


void printLeftView(tree_int* root,int level, int* maxlevel)
{
    if(root==NULL)
        return;
    if(level > *maxlevel)
    {
        *maxlevel = level;
        printf("%d\n",root->data);
    }
    printLeftView(root->left,level+1,maxlevel);
    printLeftView(root->right,level+1,maxlevel);
}

tree_int* pruneUtil(tree_int* root, int k, int *sum)
{
    int localsum;
    int rightlocalsum;

    if (root == NULL)
        return NULL;

    localsum = *sum+root->data;
    rightlocalsum = localsum;
    root->left = pruneUtil(root->left,k,&localsum);
    root->right = pruneUtil(root->right,k,&rightlocalsum);

    *sum = max(localsum,rightlocalsum);
    if(*sum <k)
    {
        free(root);
        root = NULL;
    }
    return root;
}

void prune(tree_int* root,int k)
{
    int sum = 0;
    if (root == NULL)
        return;

    root = pruneUtil(root,k,&sum);
}
tree_int* convertBinarTreeLeavesToListUtil(tree_int* root, tree_int** head)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->left == NULL && root->right==NULL)
    {
        root->right = *head;
        root->left = NULL;
        if(*head!=NULL)
        {
            (*head)->left = root;
        }
        *head = root;
        return NULL;
    }
    root->right = convertBinarTreeLeavesToListUtil(root->right, head);
    root->left = convertBinarTreeLeavesToListUtil(root->left, head);
    
    return root;
}
void printListCreatedFromTree(tree_int* root)
{
    tree_int* prev=NULL;
    if(root==NULL){
        printf("DEBUG:printListCreatedFromTree: NULL list\n");
        return;
    }

    printf("Forward direction:\n");
    while(root!=NULL)
    {
        printf("%d ",root->data);
        prev=root;
        root = root->right;
    }
    printf("\nReverse direction:\n");
    while(prev!=NULL)
    {
        printf("%d ",prev->data);
        prev= prev->left;
    }
    printf("\n");
    return;

}
tree_int* convertBinaryTreeLeavesToList(tree_int* root)
{
    tree_int* headList=NULL;
    root = convertBinarTreeLeavesToListUtil(root,&headList);
    printf("Binary tree after conversion\n");
    preorderIterative(root);
    printf("\nLinked list created\n");
    printListCreatedFromTree(headList);
    printf("\n");
    return root;
}

int DeepestLeftLeafUtil(tree_int* root, int isleft,int level)
{
    int d;
    if(root==NULL)
        return 0;
    if(root->left == NULL && root->right==NULL && isleft==1)
    {
        return level;
    }

    d = max(DeepestLeftLeafUtil(root->left,1,level+1),DeepestLeftLeafUtil(root->right,0,level+1));
    return d;
}

int DeepestLeftLeaf(tree_int* root)
{
    int depth;
    int isLeft=1;
    int level =1 ;
    if(root==NULL)
        return 0;
   
    depth = DeepestLeftLeafUtil(root,isLeft,level);
    printf("Deepest level : %d\n",depth);
    return depth;
}

/* convert tree to list using Static */


tree_int* ConvertTreeToListInorderUtil(tree_int* root,tree_int** head)
{

    static tree_int* prev=NULL;
    if (root==NULL)
        return NULL;
    
    

     ConvertTreeToListInorderUtil(root->left,head);

    if(prev == NULL)
    {
            *head = root;
    }
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;

    ConvertTreeToListInorderUtil(root->right,head);
    return root;
}

void ConvertTreeToListInorder(tree_int* root)
{
    tree_int* headList;
    if(root == NULL)
    {
        printf("DEBUG:ConvertTreeToListInorder: Binary tree is non existant\n");
    }
    ConvertTreeToListInorderUtil(root,&headList);
    printListCreatedFromTree(headList);
    return;
}


tree_int*  findLCA(tree_int* root,int n1, int n2)
{

    tree_int* leftlca;
    tree_int* rightlca;

    if(root == NULL)
        return NULL;

    if(root->data == n1 || root->data == n2)
    {
        return root;
    }

    leftlca = findLCA(root->left,n1,n2);
    rightlca = findLCA(root->right,n1,n2);

    if(leftlca && rightlca)
    {
        return root;
    }
    return((leftlca!=NULL)?leftlca:rightlca);
    
}

int findLevelUtil(tree_int* root,int val,int level)
{
    int dl,dr;
    if(root==NULL)
        return 0;
    if(root->data == val)
        return level;
    dl= findLevelUtil(root->left,val,level+1);
    dr= findLevelUtil(root->right,val,level+1);

    return ((dl!=0)?dl:dr);

}
int findLevel(tree_int* root, int val)
{
    return(findLevelUtil(root,val,1));
}
int DistanceBetweenNodes(tree_int* root, int n1, int n2)
{
    tree_int* lca;
    int d1,d2,d,lca2;

    lca= findLCA(root,n1,n2);
    lca2=findLevel(root,lca->data);
    d1 = findLevel(root,n1);
    d2= findLevel(root,n2);
    if(d1==0 && d2==0)
        return -1;
    d= d1+d2-lca2;

    return d;
}


int findIndexinInorTree(int in[],int level[],int levelstrt, int sidx, int eidx,int size)
{
    int i=-1;
    int j=-1;
    for(i=levelstrt;i<size;i++)
        for(j=sidx;j<=eidx;j++)
        {
            if(in[j] == level[i])
            {
                return j;
            }
        }
    return -1;
}


tree_int* ConstructTreeFromInandLevel
        (int inor[],int levelor[], int strtidx, int endidx, int size,int levelstrt)
{

    int idx;
    tree_int* node;
    

    if(strtidx == endidx)
    {
        node = (tree_int*)newNode(inor[strtidx]);
    }
    if(strtidx < 0 || strtidx >=size)
    {
        return NULL;
    }
    idx= findIndexinInorTree(inor,levelor,levelstrt,strtidx,endidx,size);
    if(idx==-1)
        return NULL;
    node = (tree_int*)newNode(inor[idx]);

    node->left = ConstructTreeFromInandLevel(inor,levelor,strtidx,idx-1,size,levelstrt+1);
    node->right = ConstructTreeFromInandLevel(inor,levelor,idx+1,endidx,size,levelstrt+1);
    return node;
}

tree_int* insertToBST(tree_int* root,int val)
{
    tree_int* node;
    if(root==NULL)
    {
        node = (tree_int*)newNode(val);
        root = node;
    }
    else
    {

        if(val < root->data)
        {
            root->left = insertToBST(root->left,val);
        }
        else
        {
            root->right = insertToBST(root->right,val);
        }
    }
    return root;
}


tree_int* searchBST(tree_int* root, int key)
{
    tree_int* node;
    if(root==NULL || root->data == key)
        return root;
    if(key<root->data)
    {
        node = (tree_int*)searchBST(root->left,key);
    }
    else
    {
        node = (tree_int*)searchBST(root->right,key);
    }
    return node;
}
tree_int* findInorderSuccessor(tree_int* node)
{
    if(node == NULL)
        return NULL;
    if(node->right != NULL)
        node = node->right;
    else
        return NULL;
    while(node->left !=NULL)
    {
        node = node->left;
    }
    return node;
}
tree_int* deleteNodeFromBST(tree_int* root,int key)
{
    tree_int* tmp;
    if(root == NULL)
        return NULL;


    if(root->data < key)
    {
        root->right = deleteNodeFromBST(root->right,key);
    }
    else if(root->data > key)
    {
        root->left = deleteNodeFromBST(root->left,key);
    }
    else
    {
        if(root->right == NULL)
        {
            tmp = root->left;
            free(root);
            return tmp;
        }
        else if(root->left==NULL)
        {
            tmp = root->right;
            free(root);
            return tmp;
        }

        tmp = findInorderSuccessor(root);
        root->data = tmp->data;
        root->right = deleteNodeFromBST(root->right,root->data);
        return root;
    }

    
}


int findMinimuminBST(tree_int* root)
{
    if (root==NULL)
    {
        return -1;
    }
    if(root->left == NULL)
    {
        return root->data;
    }
    return(findMinimuminBST(root->left));
}


void findInorderPreSuc(tree_int* root, int* pre, int* suc,int key)
{
    tree_int* tmp;
    if(root == NULL)
    {
        return ;
    }
    if(root->data < key)
    {
        *pre=root->data;
        findInorderPreSuc(root->right,pre,suc,key);
    }
    else if(root->data > key)
    {
        *suc = root->data;
        findInorderPreSuc(root->left,pre,suc,key);
    }
    else if(root->data == key)
    {
        if(root->left != NULL)
        {
            tmp = root->left;
            while(tmp->right != NULL)
                tmp = tmp->right;
            *pre = tmp->data;
        }
        if(root->right != NULL)
        {
            tmp = root->right;
            while(tmp->left != NULL)
            {
                tmp = tmp->left;
            }
            *suc = tmp->data;
             
        }
    }
    
    return;
}


int checkifBSTUtil(tree_int* root, int min,int max)
{
    if(root ==NULL)
        return 1;

    if(root->data > max && root->data < min)
    {
        return 0;
    }
    return ( checkifBSTUtil(root->left,min,root->data-1)
             && checkifBSTUtil(root->right,root->data+1,max));

}

int checkifBST(tree_int* root)
{
    int min=INT_MIN;
    int max=INT_MAX;
    int result;

    result = checkifBSTUtil(root,min,max);
    
    return result;
}




tree_int* findLCAofBST(tree_int* root,tree_int* n1,tree_int* n2)
{
    if(root==NULL)
        return NULL;
    if(root->data >n1->data && root->data > n2->data)
    {
        return(findLCAofBST(root->left,n1,n2));
    }
    else if((root->data <n1->data) && (root->data <n2->data))
    {
        return (findLCAofBST(root->right,n1,n2));
    }
    return root;
}



int findKthSmallestInBST(tree_int* root, int k)
{
    mystack* s=NULL;
    tree_int* temp=root;
    int n =0;
    if(root==NULL)
        return INT_MIN;

    while(temp!=NULL)
    {
        push(&s,temp);
        temp = temp->left;
    }
    while(s != NULL)
    {
        temp = pop(&s);
        n++;
        if(n==k)
            return temp->data;
        if(temp->right!=NULL)
        {
            temp=temp->right;
            while(temp!=NULL)
            {
                push(&s,temp);
                temp=temp->left;
            }
        }

    }
}


void printBSTKeyInaRange(tree_int* root,int k1, int k2)
{

    if(root==NULL)
        return;
    if(root->data < k1)
    {
        printBSTKeyInaRange (root->right,k1,k2);
    }
    /*gfk soln - test it*/
#if 0
       if ( k1 <= root->data && k2 >= root->data )
                printf("%d ", root->data );
#endif 
    if(root->data >k2)
    {
        printBSTKeyInaRange(root->left,k1,k2);
    }
/* in gfk soln, remove below line */
    printf("%d ",root->data);
    return;

}

