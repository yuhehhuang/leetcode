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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        int sum=0;
        ListNode* ans=new ListNode(0) ;
        ListNode* record_ini=ans;
       while(l1!=NULL||l2!=NULL){
        if(l1!=NULL){
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum+=l2->val;
            l2=l2->next;
        }
        sum+=carry;
        carry=sum/10;
        ans->val=sum%10;
        sum=0;
        if(l1==NULL&&l2==NULL){
            if(carry==1){
                ListNode* tmp=new ListNode(1);
                ans->next=tmp;
            }
            break;
        }
        ListNode* tmp=new ListNode(0);
        ans->next=tmp;
        ans=ans->next;
       }
       return record_ini;
    }
};