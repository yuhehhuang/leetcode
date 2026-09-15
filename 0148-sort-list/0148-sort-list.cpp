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
    ListNode* mid_location(ListNode*head){
        ListNode *slow=head;
        ListNode * fast=head;
        ListNode *prev;
        while(fast!=nullptr&&fast->next!=nullptr){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=nullptr;
        return slow;
    }
    ListNode* merge(ListNode* head1,ListNode* head2){
        //return the head after merge;
        ListNode *newhead=nullptr;
        ListNode *mem;
        while(head1!=nullptr&&head2!=nullptr){
            if(head1->val<=head2->val){
               if(newhead==nullptr){
                newhead=head1;
                mem=head1;
               }
               else{
                newhead->next=head1;
                newhead=newhead->next;  
               }
               head1=head1->next;
            }
            else{
                if(newhead==nullptr){
                    newhead=head2;
                    mem=head2;
                }
                else{
                    newhead->next=head2;
                    newhead=newhead->next;  
                }
                head2=head2->next;
            }          
        }
        while(head1!=nullptr){
            newhead->next=head1;
            newhead=newhead->next;
            head1=head1->next;
        }
        while(head2!=nullptr){
            newhead->next=head2;
            newhead=newhead->next;
            head2=head2->next;
        }
        return mem;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode *head2=mid_location(head);
        head=sortList(head);
        head2=sortList(head2);
        ListNode* ans=merge(head,head2);
        return ans;
    }
};