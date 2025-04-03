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
        ListNode* pre=head;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast&&fast->next){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        pre->next=NULL;
        return slow;
    }
    ListNode* mergeTwoLists(ListNode* list1,ListNode* list2){
        ListNode dummy;
        ListNode* cur=&dummy;
        while(list1&&list2){
            if(list1->val<list2->val){
                cur->next=list1;
                list1=list1->next;
            }
            else{
                cur->next=list2;
                list2=list2->next;
            }
            cur=cur->next;
        }
        cur->next=list1?list1:list2;
        return dummy.next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* head2=middleNode(head);
        head=sortList(head);
        head2=sortList(head2);
        return mergeTwoLists(head,head2);
    }
};