/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next=head;
    dummy->val=0;
    struct ListNode* tmp =head;
    int len=0;
    while(tmp){
        len++;
        tmp=tmp->next;
    }

    struct ListNode* prev=dummy;
    int move_cnt=len-n;
    while(move_cnt--){
        prev=prev->next;
    }
    struct ListNode* target=prev->next;
    prev->next=target->next;
    free(target);
    struct ListNode* newhead=dummy->next;
    free(dummy);
    return newhead;
}