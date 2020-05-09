#include <stdio.h>

typedef struct tree
{
  int val;
  struct tree* left;
  struct tree* right;
}TREE;


TREE* newNode(int val)
{

  TREE* node = (TREE*)malloc(sizeof(TREE));
  node->val = val;
  node->left = NULL;
  node->right = NULL;

  return node;
}

void convert_tree_to_array_impl(int *array, TREE* root, int len, int* index)
{
  if(root == NULL)
  {
    return;
  }

  convert_tree_to_array_impl(array,root->left,len,index);
  array[*index] = root->val;
  (*index)++;
  convert_tree_to_array_impl(arra,root->right,len,index);

}
int comp(void* a, void*b)
{
  return(*(int*)a - *(int*)b);
}

int* convert_tree_to_array(TREE* root, int len)
{
  int* array = (int*)calloc(sizeof(int),len);
  int index=0;

  convert_tree_to_array_impl(array,root,len,&index);

  qsort(array,len,sizeof(array[0]),comp);
  return array;
}

void binary_tree_to_bst(int* array, TREE* root, int len, int* indx)
{
  if(root == NULL)
  {
    return;

  }
  binary_tree_to_bst(array,root->left,len,indx);
  root->val = array[*indx];
  (*indx)++;
  binary_tree_to_bst(array,root->right,len,indx);
}

int main()
{

  TREE* root;

  int * arr;

  int length = 5;
  int index = 0;

  root = newNode(10);
  root->left = newNode(30);
  root->right = newNode(15);
  root->left->left = newNode(20);
  root->right->right = newNode(5);

  arr = convert_tree_to_array(root,length);

   binary_tree_to_bst(array,root,len,&index);

}
