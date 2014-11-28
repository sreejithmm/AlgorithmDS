#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{

	Queue * q = createQ();
	QNode * node = NULL;
	enQ(q,10);
	enQ(q,9);
	enQ(q,11);
	enQ(q,12);
	enQ(q,8);

        node = deQ(q);
	if(node != NULL)
	{
	    printf("deQed val = %d\n",node->val);
	    free(node);
	}
	else
	{
	    printf("Empty Queue !!!\n");
	}

	enQ(q,7);
	enQ(q,14);
	deQ(q);
	deQ(q);
	deQ(q);
	enQ(q,16);
	enQ(q,19);
	enQ(q,20);
        node = deQ(q);
	
	if(node != NULL)
	{
	    printf("deQed val = %d\n",node->val);
	    free(node);
	}
	else
	{
	    printf("Empty Queue !!!\n");
	}


	return 0;
}
