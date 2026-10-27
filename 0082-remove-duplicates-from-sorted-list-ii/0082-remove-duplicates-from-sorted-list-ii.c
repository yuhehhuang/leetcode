/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* dummy= (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next=head;
    struct ListNode* cur=dummy;
    while(cur->next!=NULL&&cur->next->next!=NULL){
        if(cur->next->val==cur->next->next->val){
            int val=cur->next->val;
            while(cur->next!=NULL&&cur->next->val==val){
                cur->next=cur->next->next;
            }
            //while 出來後cur->next一定是跟cur不同或著說cur->next是NULL;
        }
        else{
            cur=cur->next;
        }
    }
    return dummy->next;
}