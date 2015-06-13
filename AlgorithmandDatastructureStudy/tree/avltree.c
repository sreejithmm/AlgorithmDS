#include <stdio.h>



typedef struct _avltree{
	int val;
	int height;
	struct _avltree* left;
	struct _avltree* right;
}Avltree;

int max(int a, int b)
{
	if (a>b)
	{
		return a;
	}
	else 
	{
		return b;
	}
}

int calc_height(Avltree* node)
{
	return (node->height);
}

int getbalance(Avltree* node)
{
	return ((node->left->height) - (node->right->height));
}

Avltree* insertToAVLTree(Avltree* root, int val)
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
		
	}
	else
	{
		if(val < root->val)
		{
			root->left = insertToAVLTree(root->left,val);
		}
		else
		{
			root->right = insertToAVLTree(root->right,val);
		}
		temp = root;	
	}

	temp->height = max(calc_height(temp->left),calc_height(temp->right));
	balance = getbalance(temp);
	/* check the balancing of the tree */
	if(balance > 1 && (temp->left->val > val))
	{
		temp = rotate_right(temp);
	}
	else if(balance > 1 && (temp->left->val < val))
	{
		temp->left = rotate_left(temp->left);
		temp  = rotate_right(temp);

	}
	else if(balance < 1 && (temp->right>val < val))
	{
		temp = rotate_left(temp);

	}
	else if(balance <1 && (temp->right->val > val))
	{
		temp->right = rotate_right(temp->right);
		temp = rotate_left(temp);
	}

	return temp;

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