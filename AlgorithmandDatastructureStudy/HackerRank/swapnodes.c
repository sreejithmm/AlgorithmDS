#include <stdio.h>

typedef struct  _Tree
{
	/* data */
	int val
	int level;
	struct _Tree *left;
	struct _Tree *right;
}Tree;


struct queue_node{

    Tree* data;
    struct queue_node* next;

};
typedef struct queue_{
    struct queue_node *front;
    struct queue_node *rear;
}myqueue;


Tree* create_tree_node(int val,int level)
{
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	assert(tree);
	tree->val = val;
	tree->level = level;
	tree->left = NULL;
	tree->right = NULL;
	return tree;

}
myqueue* createQueue()
{

    myqueue* q= (myqueue*)malloc(sizeof(myqueue));
    q->rear=NULL;
    q->front = NULL;
    return q;
}

void enqueue(myqueue *q,Tree* dat)
{

   struct queue_node *node=NULL;

   if (q==NULL)
   {
       printf("Create Q first. Q is NULL\n");
       return ;
   }
   node = (struct queue_node*)malloc(sizeof(struct queue_node));
   node->next = NULL;
   node->data = dat;
   if (q->rear == NULL)
   {

        q->rear = node;
        q->front = q->rear;
   }else
   {

        q->rear->next =  node;
        q->rear = node;
   }


}

Tree* dequeue(myqueue *q)
{

    int temp;
    struct queue_node *node;
    if(q==NULL)
    {

        printf("Create Q first. Q is NULL\n");
        return INT_MIN;
    }
    if(q->front == NULL)
    {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    node = q->front;
    temp = node->data;

    q->front = q->front->next;
    free(node);
    node = NULL;
    if(q->front == NULL)
    {
        q->rear=NULL;
    }

    return temp;


}


Tree* tree_create(int *maxlevel,*nodes)
{
	int i,j;
	int n;
	int val,level=1;
	myqueue *q=NULL;
	Tree* node;
	int lval,rval;
	int T,k;
	Tree* root=NULL;

	scanf("%d",&n);
	if(n>0)
	{
		q=createQueue();

		node = create_tree_node(val,level);
		level ++;
		enqueue(q,node);
		root=node;
	}
	/* Read nodes */	
	for(i=1;i<n;i++)
	{
		scanf("%d %d",lval,rval);
		node = dequeue(q);
		if(lval != -1)
		{
			
			node->left = create_tree_node(lval,level)
			enqueue(q,node);
		}
		if (rval != -1)
		{
			node->right = create_tree_node(rval,level);
			enqueue(rval,node);
		}
		level++;
	}
	printf("maxlevel=%d\n",level );
	*maxlevel = level;
	*nodes = n;
	return root;

}
void print_inorder_of_tree(Tree *root)
{
    if(root==NULL)
        return;
    inorderTraverseInt(root->left);
    printf("%d ",root->val);
    inorderTraverseInt(root->right);

}
void rearrage_nodes(Tree* root, int k,int n, int height)
{
	int i;
	myqueue *q=createQueue();
	Tree* node;
	int level = 1;
	enqueue(q,root);

	for(i=1;(i<n && k < height);i++)
	{
		node = dequeue(q);

		if (node->level %k == 0)
		{

		}



	}
}
int main()
{
	Tree* tree;
	int nT,int k;
	int maxlevel;
	int noofnodes;

	tree = tree_create(&maxlevel,&noofnodes);
	scanf("%d",&nT);
	while(nT)
	{
		scanf("%d",&k);
		/* k is the level */
		if(k >= maxlevel)
		{
			continue;
		}
		else
		{
			rearrage_nodes(tree,k,noofnodes,maxlevel);
		}
		print_inorder_of_tree(tree);
	}


}