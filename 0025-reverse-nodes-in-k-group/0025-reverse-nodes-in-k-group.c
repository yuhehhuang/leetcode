/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    int list_len=0;
    struct ListNode* tmp=head;
    while(tmp!=NULL){
        list_len++;
        tmp=tmp->next;
    }
    struct ListNode* dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next=head;
    struct ListNode* p0=dummy;
    struct ListNode* cur=p0->next;
    struct ListNode* prev=NULL;
    while(list_len>=k){
        list_len-=k;
        struct ListNode* next_p0=p0->next;
        int cnt=k;
        while(cnt--){
            //reverse function
            struct ListNode* next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        p0->next->next=cur;
        p0->next=prev;
        p0=next_p0;
    }
    struct ListNode* new_head=dummy->next;
    free(dummy);
    return new_head;
}