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
    ListNode* sortList(ListNode* head) {
    vector<int>a;
    ListNode* tmp1 =head;
    ListNode* tmp2 =head;
    while(tmp1!=NULL){
        a.push_back(tmp1->val);
        tmp1=tmp1->next;
    }
    sort(a.begin(),a.end());
    for(int i=0;i<a.size();++i){
        tmp2->val=a[i];
        tmp2=tmp2->next;
    }
    return head;
    }
};