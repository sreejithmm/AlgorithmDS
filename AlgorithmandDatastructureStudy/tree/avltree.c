#include <stdio.h>



typedef struct _avltree{
	int val;
	struct _avltree* left;
	struct _avltree* right;
}Avltree;



void insertToAVLTree(Avltree** root, int val)
{
	
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