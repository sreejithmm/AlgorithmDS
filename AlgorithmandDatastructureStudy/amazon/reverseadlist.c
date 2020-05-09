#include <stdio.h>

typedef struct dlist{
	int num;
	stuct dlist* next;
	struct dlist* prev;
}dList;

void InitDlist(dList** head)
{
	*head = (dList*)malloc(sizeof(dList));
	*head->next=NULL;
	*head->prev=NULL;
	return;
}

int main()
{
	int i=0
	dList* head=NULL;
	printf("Enter the number of elements in linked list\n");
	scanf("%d",&n);
	head = readValues(n);
	head=reverse(head)

	


}
