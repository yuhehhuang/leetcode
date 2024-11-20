/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* middleNode(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head){
        ListNode* pre=NULL;
        ListNode* cur=head;
        while(cur!=NULL){
            ListNode* next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }
public:
    void reorderList(ListNode* head) {
        ListNode* mid=middleNode(head);
        ListNode* head2=reverseList(mid);
        while(head2->next!=NULL){
            ListNode* next=head->next;
            ListNode* next2=head2->next;
            head->next=head2;
            head2->next=next;
            head=next;
            head2=next2;
        }
    }
};