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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return NULL;
        }
        int cnt=0;
        ListNode* tmp1=head;
        while(tmp1!=NULL){
            tmp1=tmp1->next;
            cnt++;
        }
        ListNode* tmp2=head;
        for(int i=0;i<cnt/2-1;i++){
            tmp2=tmp2->next;
        }
        tmp2->next=tmp2->next->next; 
        
        return head;
    }
};