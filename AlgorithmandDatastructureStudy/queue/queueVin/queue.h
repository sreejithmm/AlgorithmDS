#ifndef __QUEUE_H
#define __QUEUE_H

typedef struct _QNode
{
    int val ;
    struct _QNode * next ;

}QNode;
typedef struct _Queue
{
    QNode *front ,*rear ;

}Queue;


QNode * newQnode(int );
Queue * createQ();
void enQ(Queue * q ,int data);
QNode * deQ(Queue * q);

#endif /*__QUEUE_H*/
