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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr||k==0){
            return head;
        }
        //先建立閉環
        //找到新的尾巴，head=新尾->next; 新尾->next=NULL;
        int len=1;
        ListNode* tmp=head;
        while(tmp->next){
            len++;
            tmp=tmp->next;
        }
        ListNode*tail=tmp;
        tail->next=head;//建立閉環
        int true_rot=k%len;
        ListNode* newtail=head;
        int x=len-true_rot-1;
        while(x--){
            newtail=newtail->next;
        }
        head=newtail->next;
        newtail->next=NULL;
        return head;
    }
};