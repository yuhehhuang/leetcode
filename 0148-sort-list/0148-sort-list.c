/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mid(struct ListNode* head){
    struct ListNode* slow=head;
    struct ListNode* fast=head;
    struct ListNode* mid_prev=NULL;
    while(fast&&fast->next){
        mid_prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    mid_prev->next=NULL;
    return slow;
}

struct ListNode* merge_list(struct ListNode* head1,struct ListNode* head2){
    struct ListNode* merge_head=NULL;
    struct ListNode* merge_tmp;
    while(head1&&head2){
        if(head1->val<=head2->val){
            if(merge_head==NULL){
                merge_head=head1;
                merge_tmp=merge_head;
                head1=head1->next;
            }
            else{
                merge_tmp->next=head1;
                merge_tmp=merge_tmp->next;
                head1=head1->next;
            }
        }
        else{
            if(merge_head==NULL){
                merge_head=head2;
                merge_tmp=merge_head;
                head2=head2->next;
            }
            else{
                merge_tmp->next=head2;
                merge_tmp=merge_tmp->next;
                head2=head2->next;
            }
        }   
    }
    while(head1){
        merge_tmp->next=head1;
        merge_tmp=merge_tmp->next;
        head1=head1->next;
    }
    while(head2){
        merge_tmp->next=head2;
        merge_tmp=merge_tmp->next;
        head2=head2->next;
    }
    return merge_head;
}

struct ListNode* sortList(struct ListNode* head) {
    if(head==NULL||head->next==NULL){
        return head;
    }
    struct ListNode* middle=mid(head);
    struct ListNode* first_part=sortList(head);
    struct ListNode* second_part=sortList(middle);
    return merge_list(first_part,second_part);
}