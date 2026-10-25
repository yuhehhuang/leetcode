/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int len=0;
    struct ListNode* cur=head;
    while(cur!=NULL){
        len++;
        cur=cur->next;
    }
    if(n==len){
        struct ListNode* nexthead=head->next;
        free(head);
        return nexthead;
    }
    struct ListNode* tmp=head;
    struct ListNode* prev=NULL;
    int move=len-n;
    while(move--){
        prev=tmp;
        tmp=tmp->next;
    }
    prev->next=tmp->next;
    free(tmp);
    return head;
}