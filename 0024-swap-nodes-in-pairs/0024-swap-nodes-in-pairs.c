/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if(head==NULL){
        return NULL;
    }
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->next=head;
    struct ListNode *p0 = dummy;
    struct ListNode *p1 = head;
    while(p1&&p1->next){
        struct ListNode *p2=p1->next;
        struct ListNode *p3=p2->next;
        p0->next=p2;
        p2->next=p1;
        p1->next=p3;

        p0=p1;
        p1=p3;
    }

    return dummy->next;
}