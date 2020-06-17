/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode list;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
    int val=0;
    struct ListNode* result,*tmp;
    tmp = (struct Listnode*) malloc(sizeof(list));
    result = tmp;
    
    while(l1 || l2){
        if(l1){
            val = val + l1->val;
            l1 = l1->next;
        }
        if(l2){
            val = val + l2->val;
            l2 = l2->next;
        }

        tmp->next = (struct Listnode*)malloc(sizeof(list));
        tmp = tmp->next;

        tmp->val = val%10;
        tmp->next = NULL;
        val = val / 10;
    }
    if(val){
        tmp->next = (struct Listnode*)malloc(sizeof(list));
        tmp = tmp->next;
        tmp->val = val;
        tmp->next = NULL;

    }
    return result->next;
}