/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){
struct ListNode *tmp=head;
while(tmp != NULL && tmp->next != NULL){
    if(tmp->val==tmp->next->val){
      struct ListNode *buffer=tmp->next;
        tmp->next=tmp->next->next;
        free(buffer);
    }
    else{
        tmp=tmp->next;
    }
}
return head;
}