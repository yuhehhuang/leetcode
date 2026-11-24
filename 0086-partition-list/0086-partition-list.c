/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    if(head==NULL){
        return NULL;
    }
    struct ListNode *head1 = NULL;
    struct ListNode *tail1 = NULL;
    struct ListNode *head2 = NULL;
    struct ListNode *tail2 = NULL;
    struct ListNode *cur = head;
    while(cur){
        if(cur->val<x){
            if(head1==NULL){
                head1=cur;
                tail1=cur;
            }
            else{
                tail1->next=cur;
                tail1=tail1->next;
            }
        }
        else{
            if(head2==NULL){
                head2 = cur;
                tail2 = cur;
            }
            else{
                tail2->next= cur;
                tail2=tail2->next;
            }
        }
        cur = cur->next;
    }
    if(tail2!=NULL){
        tail2->next=NULL;
    }
    if(head1==NULL){
        return head2;
    }
    tail1->next=head2;
    return head1;    
}