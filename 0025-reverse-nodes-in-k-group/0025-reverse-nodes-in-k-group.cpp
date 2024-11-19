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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0,head);
        ListNode* p0=&dummy;
        ListNode* tmp=head;
        ListNode* cur=head;
        ListNode* pre=NULL;
        int n=0;
        while(tmp!=NULL){
            tmp=tmp->next;
            n++;
        }
        for(;n>=k;n-=k){
            for(int i=0;i<k;++i){
                ListNode* next=cur->next;
                cur->next=pre;
                pre=cur;
                cur=next;
            }
            ListNode* next_p0=p0->next;
            p0->next->next=cur;
            p0->next=pre;
            p0=next_p0;
        }
        return dummy.next;

    }
};