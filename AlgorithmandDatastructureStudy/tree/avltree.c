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

Avltree* rotate_right(Avltree* node)
{
	Avltree* temp1;
	Avltree* temp2;
	temp1 = node->left->right;
	node->left->right = node;
	node->left = temp1;

	node->left->height = max(calc_height(node->left->left),calc_height(node->left->right));
	node->height = max(calc_height(node->left),calc_height(node->right));

	return node->left;

}

Avltree* rotate_left(Avltree* node)
{
	Avltree* temp1 = node->right;
	Avltree* temp2 = temp1->left;

	temp1->left = node;
	node->right = temp2;

	temp1->height = max(calc_height(temp1->left),calc_height(temp1->right));
	node->height = max(calc_height(node->left),calc_height(node->right));

	return temp1;
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
		return temp;	
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
void print_pre_order(Avltree* node)
{
	while(node)
	{
		printf("%d ",node->val);
		print_pre_order(node->left);
		print_pre_order(node->right);
	}
}
int main()
{
	int i;

	Avltree *root;

	root = insertToAVLTree(root,10);
	root = insertToAVLTree(root,20);
	root = insertToAVLTree(root,30);
	root = insertToAVLTree(root,40);
	root = insertToAVLTree(root,50);
	root = insertToAVLTree(root,25);



	print_pre_order(root);
	printf("\n");

	return 0;
}