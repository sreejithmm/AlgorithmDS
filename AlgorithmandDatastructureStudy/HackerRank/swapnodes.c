#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>



#ifdef FILE_INPUT
FILE *fd;
void init_test_file()
{
	fd = fopen("test.txt","r");
}
void readTwoInt(int *a, int *b)
{
	fscanf(fd,"%d",a);
	fscanf(fd,"%d",b);
	return;
}
void readInt(int *a)
{
	fscanf(fd,"%d",a);
	return;
}
#endif

int max(int a , int b)
{
	int max;
	max =(a>b)?a:b;
	return max;
}
typedef struct  _Tree
{
	/* data */
	int val;
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

    Tree* temp;
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


Tree* tree_create(int *maxlevel,int *nodes)
{
	int i,j;
	int n;
	int val,level=1;
	myqueue *q=NULL;
	Tree* node;
	int lval,rval;
	int T,k;
	Tree* root=NULL;

	*maxlevel=1;
#ifdef FILE_INPUT
	readInt(&n);
#else
	scanf("%d",&n);
#endif
	if(n>0)
	{
		q=createQueue();

		node = create_tree_node(1,level);
		enqueue(q,node);
		root=node;
	}
	/* Read nodes */
	while(q->front != NULL)
	{
#ifdef FILE_INPUT
		readTwoInt(&lval,&rval);
#else
		scanf("%d %d",&lval,&rval);
#endif
		if(q->front != NULL)
			node = dequeue(q);
		else
			break;
		if(lval != -1)
		{

			node->left = create_tree_node(lval,node->level+1);
			enqueue(q,node->left);
			*maxlevel = max(*maxlevel, node->level+1);
		}
		if (rval != -1)
		{
			node->right = create_tree_node(rval,node->level+1);
			enqueue(q,node->right);
			*maxlevel = max(*maxlevel, node->level+1);
		}


	}
//	printf("maxlevel=%d\n",*maxlevel);

	*nodes = n;
	return root;

}
void print_inorder_of_tree(Tree *root)
{
    if(root==NULL)
        return;
    print_inorder_of_tree(root->left);
    printf("%d ",root->val);
    print_inorder_of_tree(root->right);

}
void call_dummy()
{
	return;
}
void rearrage_nodes(Tree* root, int k,int n, int height)
{
	int i;
	myqueue *q=createQueue();
	Tree* node;
	int level = 1,j=1;
	enqueue(q,root);
	Tree* temp;

	while (q->front != NULL)
	{
		if(q->front != NULL)
			node = dequeue(q);
		else
			break;
		if (node->level %k == 0)
		{
			if(node->level == 12)
				call_dummy();
			temp = node->left;
			node->left = node->right;
			node->right = temp;
		}
	#if 0
		if(node->level > k)
		{
			j++;
			k = j*k;
			if(k >= height)
				break;
		}
	#endif
		if(node->left)
			enqueue(q,node->left);
		if(node->right)
			enqueue(q,node->right);

	}
}
int main()
{
	Tree* tree;
	int nT,k;
	int maxlevel;
	int noofnodes;
#ifdef FILE_INPUT
	init_test_file();
#endif

	tree = tree_create(&maxlevel,&noofnodes);
#ifdef FILE_INPUT
	readInt(&nT);
#else
	scanf("%d",&nT);
#endif
	while(nT)
	{
#ifdef FILE_INPUT
	readInt(&k);
#else
		scanf("%d",&k);
#endif
		/* k is the level */
		if(k > maxlevel)
		{
			continue;
		}
		else
		{
			rearrage_nodes(tree,k,noofnodes,maxlevel);
		}
		print_inorder_of_tree(tree);
		printf("\n");
		nT--;
	}


}
