/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode* dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next=head;
    struct ListNode* p0=dummy;
    int cnt=left-1;
    while(cnt--){
        p0=p0->next;
    }
    struct ListNode* prev=NULL;
    struct ListNode* cur=p0->next;
    int reverse_cnt=right-left+1;
    while(reverse_cnt--){
        struct ListNode* nxt=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nxt;    
    }
    p0->next->next=cur;
    p0->next=prev;
    struct ListNode* new_head=dummy->next;
    free(dummy);
    return new_head;
}