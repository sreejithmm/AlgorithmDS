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
  
}
int* convert_tree_to_array(TREE* root, int len)
{
  int* array = (int*)calloc(sizeof(int),len);
  int index=0;

  convert_tree_to_array_impl(array,root,len,&index);

  return array;
}

int main()
{

  TREE* root;

  int * arr;

  int length = 5;

  root = newNode(10);
  root->left = newNode(30);
  root->right = newNode(15);
  root->left->left = newNode(20);
  root->right->right = newNode(5);

  arr = convert_tree_to_array(root,length);


}
