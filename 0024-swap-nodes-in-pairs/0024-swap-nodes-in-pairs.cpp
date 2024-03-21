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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead=new ListNode();
        dummyHead->next=head;
        ListNode* cur=dummyHead;
        while(cur->next!=NULL&&cur->next->next!=NULL){
            ListNode*tmp1=cur->next;
            ListNode*tmp2=cur->next->next->next;
            cur->next=cur->next->next;
            cur->next->next=tmp1;
            cur->next->next->next=tmp2;
            cur=cur->next->next;
        }
        return dummyHead->next;
    }
};