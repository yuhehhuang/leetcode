/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next=head;
    struct ListNode* p0=dummy;
    for(int i=0;i<left-1;++i){
        p0=p0->next;
    }
    struct ListNode* prev=NULL;
    struct ListNode* cur=p0->next;
    int cnt=right-left+1;
    while(cnt--){
        struct ListNode* tmp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=tmp;
    }
    p0->next->next=cur;
    p0->next=prev;
    struct ListNode* ans=dummy->next;
    free(dummy);
    return ans;
}