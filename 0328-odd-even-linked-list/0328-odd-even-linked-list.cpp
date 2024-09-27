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
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode* copy=head;
        ListNode* copy2=head->next;
        ListNode* copy3=head->next;
        while(copy->next!=NULL&&copy2->next!=NULL){
            copy->next=copy->next->next;
            copy2->next=copy2->next->next;
            copy=copy->next;
            copy2=copy2->next;
        }
        copy->next=copy3;
        return head;
    }
};