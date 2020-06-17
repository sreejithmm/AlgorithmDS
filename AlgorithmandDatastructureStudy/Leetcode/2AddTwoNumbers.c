/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
    int carry=0,val=0;
    struct ListNode* result,*tmp,*node;
    struct ListNode test;
    tmp = (struct Listnode*) malloc(sizeof(test));
    result = tmp;
    while(l1 || l2){
        val = carry;
        if(l1){
            val = val + l1->val;
            l1 = l1->next;
        }
        if(l2){
            val = val + l2->val;
            l2 = l2->next;
        }

        node = (struct Listnode*)malloc(sizeof(test));
        node->val = val%10;
        node->next = NULL;
        tmp->next = node;
        tmp = node;
        carry = val / 10;
    }
    if(carry){
        node = (struct Listnode*)malloc(sizeof(test));
        node->val = carry;
        node->next = NULL;
        tmp->next = node;

    }
    return result->next;
}