/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head){
struct ListNode* slow=head,*fast=head,*prev=NULL,*tmp;
while(fast!=NULL&&fast->next!=NULL){
    fast=fast->next->next;
    tmp=slow->next;
    slow->next=prev;
    prev=slow;
    slow=tmp;
}
slow=((fast!=NULL)?slow->next:slow);
while(slow!=NULL){
    if(slow->val!=prev->val)
    return false;
    else
    slow=slow->next;
    prev=prev->next;
}
return true;
}