#include <stdio.h>
#include <stdlib.h>



typedef struct list {
    int num;
    char command;
    struct list * next;
}LIST;

LIST* skip(LIST * start , int length, LIST** prev){

    int skipl ;
    int i = 0;
    LIST* ret=start;
    if(start){
        skipl = length;
        for(i=0;i<skipl;i++){
            *prev = ret;
            ret = start->next;
        }
    }
    return ret;

}

void print_list(LIST* node) {
    while(node) {
        printf("[%c %d]---> ",node->command,node->num);
        node = node->next;
    }
    printf("NULL\n");
}

int main () {

    LIST * Head, *temp, *prev , * curr;
    int length;
    int i;
    char cmd;
    int value;

    Head = NULL;
    prev = NULL;

    printf("Enter the number of nodes \n");
    scanf("%d",&length);
    printf("Enter the command and value\n");
    for(i = 0; i<length ; i++) {
        scanf(" %c %d",&cmd, &value);
        temp = (LIST*)malloc(sizeof(LIST));
        temp->command = cmd;
        temp->num = value;
        if(i==0)
            Head = temp;
        if(prev) 
            prev->next = temp;
        prev = temp;
        temp->next = NULL;
    }

    printf("Input\n");
    print_list(Head);

    temp = Head;
    prev = NULL;
    while(temp){
        cmd = temp->command;
        switch(cmd){
            case 's':
                printf("Skip %d nodes including current node\n",temp->num);
                temp = skip(temp,temp->num,&prev);
                break;
            case 'r':
                printf("reverse %d nodes from current node \n",temp->num); 
                if(prev){
                    LIST * tmp_prev;
                    tmp_prev = prev;
                    tmp_prev->next = reverse(temp,temp->num,&temp,&prev);
                } else {
                    Head = reverse(temp,temp->num,&temp,&prev);
                }
                break;
            default:
                printf("Unknown command. Skip the node\n");
                temp = temp->next;
                break;

        }

    }
    printf("List after all operations\n")
    print_list(Head);
    return 0;

}

LIST* reverse (LIST* start, int length,LIST ** current,LIST ** real_prev) {
    LIST * prev, *curr, * next;
    LIST ** temp;
    int i = 0;

    curr = start;
    next = NULL;
    prev = NULL;
    temp = &(curr->next );

    for(i=0;i<length;i++){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } 

    *temp = curr;
    *current = curr;
    return prev;

}
