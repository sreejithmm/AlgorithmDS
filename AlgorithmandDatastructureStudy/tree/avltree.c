#include <stdio.h>



typedef struct _avltree{
	int val;
	int height;
	struct _avltree* left;
	struct _avltree* right;
}Avltree;



void insertToAVLTree(Avltree** root, int val)
{
	Avltree* temp;
	int balance;

	if(root == NULL)
	{
		temp = (Avltree*)malloc(sizeof(Avltree));
		temp->val = val;
		temp->height = 1;
		temp->left = NULL;
		temp->right = NULL;
		*root = temp;
	}
	else
	{
		if(val < root->val)
		{
			insertToAVLTree(&(root->left),val);
		}
		else
		{
			insertToAVLTree(&(root->right),val);
		}
		(*root)->height = max(calc_height((*root)->left),calc_height((*root)->right));
		balance = getbalance(*root);
		/* check the balancing of the tree */

	}
}
int main()
{
	int i;

	Avltree *root;

	insertToAVLTree(&root,10);
	insertToAVLTree(&root,20);
	insertToAVLTree(&root,30);
	insertToAVLTree(&root,40);
	insertToAVLTree(&root,50);
	insertToAVLTree(&root,25);



	print_pre_order(root);

	return 0;
}