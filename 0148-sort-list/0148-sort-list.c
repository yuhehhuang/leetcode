/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *list_of_mid(struct ListNode*head){
    struct ListNode* fast=head;
    struct ListNode* slow =head;
    struct ListNode* prev_of_slow=slow;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        prev_of_slow=slow;
        slow=slow->next;
    }
    prev_of_slow->next=NULL;
    return slow;
}

struct ListNode* merge(struct ListNode* part1,struct ListNode* part2){
    if(part1==NULL||part2==NULL){
        return part1==NULL?part2:part1;
    }
    struct ListNode* head=NULL;
    struct ListNode* cur = NULL;
    while(part1!=NULL&&part2!=NULL){
        if(part1->val<=part2->val){
            if(head==NULL){
                head=part1;
                cur=part1;
            }
            else{
                cur->next=part1;
                cur=cur->next;
            }
            part1=part1->next;
        }
        else{
            if(head==NULL){
                head=part2;
                cur=part2;
            }
            else{
                cur->next=part2;
                cur=cur->next;
            }
            part2=part2->next;
        }
    }
    if(part1!=NULL){
        cur->next=part1;
    }
    if(part2!=NULL){
        cur->next=part2;
    }
    return head;
}

struct ListNode* sortList(struct ListNode* head) {
    if(head==NULL||head->next==NULL){
        return head;
    }
    struct ListNode* mid = list_of_mid(head);
    struct ListNode* part1 = sortList(head);
    struct ListNode* part2 = sortList(mid);
    struct ListNode* ans = merge(part1,part2);
    return ans;    
}