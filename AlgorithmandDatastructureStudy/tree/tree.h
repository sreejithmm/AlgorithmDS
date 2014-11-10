typedef struct tree_node_int{

    int data;
    struct tree_node_int *left;
    struct tree_node_int *right;
}tree_int;

typedef struct tree_liss_node_int{

    int data;
    int liss; /* to support dp*/
    struct tree_liss_node_int *left;
    struct tree_liss_node_int *right;
}tree_int_liss;


typedef struct weight_tree_node{
    int num;
    int weight;
    int weightsum;
    struct weight_tree_node *left;
    struct weight_tree_node *right;
}weight_tree;


typedef struct stack_tree{
    
    tree_int* node;
    struct stack_tree* next;
}mystack;

typedef struct threaded_tree{
    int data;
    struct threaded_tree* left;
    struct threaded_tree* right;
    int threaded;
}tree_threaded_int;



struct queue_node{

    tree_int* node;
    struct queue_node * next;

};

typedef struct queue{

    struct queue_node* front;
    struct queue_node* rear;

}myqueue;

typedef enum {

    false,
    true

}boolean;

typedef struct conn_tree{

    int data;
    struct conn_tree *left;
    struct conn_tree *right;
    struct conn_tree *conn;

}tree_sp_int;

struct newqueue{
    tree_sp_int* node;
    int level;
    struct newqueue* next;
};

typedef struct conn_queue{

    struct newqueue* front;
    struct newqueue* rear;
}connqueue;

typedef struct hashkey{
    
            int hd;
            int sum;
            struct hashkey* next;

}hashmap;

typedef struct hash{
    hashmap *start;
}hash;


typedef struct tst_node{
    char data;
    int eof;
    struct tst_node* left;
    struct tst_node* eq;
    struct tst_node* right;
}tst;

typedef struct node{

    int data;
    struct node *next;

}mylist;


typedef struct alpha_tree{
    
    char str[26];
    int  startindex;
    struct alpha_tree* left;
    struct alpha_tree* right;

}alph_tree;
