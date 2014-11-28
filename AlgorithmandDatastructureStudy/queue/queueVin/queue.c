#include<stdlib.h>
#include "queue.h"


QNode * newQnode(int k)
{
	QNode * qnode = NULL;
	qnode = (QNode *)malloc(sizeof(QNode));   
	qnode->val = k;
	qnode->next = NULL;

	return qnode;
}

Queue * createQ()
{
	Queue * queue = (Queue *)malloc(sizeof(Queue));

	queue->front = NULL;
	queue->rear = NULL;

	return queue;
}

void enQ(Queue * q ,int data)
{

	QNode * qnode = NULL;
	qnode = newQnode(data);//new Node creation

	if(q->rear == NULL)//empty Q
	{
		q->front = qnode ;
		q->rear = qnode ;
	}
	else
	{
		q->rear->next = qnode;
		q->rear = qnode ;

	}	


	return ;
}
QNode * deQ(Queue * q)
{
	QNode * temp = NULL;

	if(q->front == NULL)
	{
		return NULL;
	}
	else
	{
		temp = q->front ;
		q->front = q->front->next ;
	}

	if(q->front == NULL)
	{
		q->rear = NULL;
	}

	return temp ; 
}


