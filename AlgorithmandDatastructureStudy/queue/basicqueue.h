
typedef struct queue{
    int front;
    int rear;
    int size;
    int capacity;
    int *array;
}myqueuear;


struct queue_node{

    int data;
    struct queue_node* next;

};
typedef struct queue_{
    struct queue_node *front;
    struct queue_node *rear;
}myqueue;

typedef struct st{
    
    int val;
    struct st *next;

}mystack;

typedef struct _stackqueue{

    mystack *stack1;
    mystack *stack2;

}stackqueue;


typedef struct petrol{
int petrol;
int distance;

}petrolst;







struct queue_node_str{

    char *str;
    struct queue_node_str* next;

};
typedef struct queue_str{
    struct queue_node_str *front;
    struct queue_node_str *rear;
}mystrqueue;









