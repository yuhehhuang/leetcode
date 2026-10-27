/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(k==0||head==NULL)return head;
    int len=0;
    struct ListNode* tmp=head;
    while(tmp){
        len++;
        tmp=tmp->next;
    }
    int rt_cnt=k%len;
    if(rt_cnt==0){
        return head;
    }
    struct ListNode* dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* new_end=dummy;
    dummy->next=head;
    int shift=len-rt_cnt;
    while(shift--){
        new_end=new_end->next;
    }
    struct ListNode* new_head=new_end->next;
    struct ListNode* tmp2=new_head;
    while(tmp2!=NULL&&tmp2->next!=NULL){
        tmp2=tmp2->next;
    }
    tmp2->next=head;
    new_end->next=NULL;
    return new_head;
}