/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* tmp=head;
    int len_cnt=0;
    while(tmp){
        tmp=tmp->next;
        len_cnt++;
    }
    struct ListNode* dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next=head;
    struct ListNode* p0=dummy;
    struct ListNode* cur=head;
    struct ListNode* prev=dummy;    
    while(len_cnt>=2){
        len_cnt-=2;
        int cnt=2;
        struct ListNode* p0_next=p0->next;
        while(cnt--){
            struct ListNode* next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        p0->next->next=cur;
        p0->next=prev;
        p0=p0_next;
    }
    return dummy->next;
}