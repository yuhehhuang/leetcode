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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy=ListNode(0,head);
        ListNode* right=&dummy;
        ListNode* left=&dummy;
        for(int i=0;i<n;++i){
            right=right->next;
        }
        while(right->next!=NULL){
            left=left->next;
            right=right->next;
        }
        left->next=left->next->next;
        return dummy.next;
    }
};