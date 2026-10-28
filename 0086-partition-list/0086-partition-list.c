/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    //建立兩條linked-list，最後黏在一起
    if(head==NULL)return NULL;
    struct ListNode* head1=(struct ListNode*)malloc(sizeof(struct ListNode));
    head1->next=NULL;
    struct ListNode* head2=(struct ListNode*)malloc(sizeof(struct ListNode));
    head2->next=NULL;
    struct ListNode* tmp1=head1;
    struct ListNode* tmp2=head2;
    struct ListNode* tmp=head;
    while(tmp){
        if(tmp->val<x){
            tmp1->next=tmp;
            tmp1=tmp1->next;
        }
        else{
            tmp2->next=tmp;
            tmp2=tmp2->next;
        }
        tmp=tmp->next;
    }
    tmp2->next=NULL;
    tmp1->next=head2->next;
    return head1->next;
}