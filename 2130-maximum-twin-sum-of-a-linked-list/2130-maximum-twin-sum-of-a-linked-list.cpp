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
    int pairSum(ListNode* head) {
        if(head==NULL){
            return 0;
        }
        ListNode* node=head;
        vector<int>val;
        int size=0;
        while(node!=NULL){
            node=node->next;
            size++;
        }
        node=head;
        int half=size/2;
        for(int i=0;i<half;++i){
            val.push_back(node->val);
            node=node->next;
        }
        for(int i=half;i<size;++i){
            val[size-1-i]+=node->val;
            node=node->next;
        }
        sort(val.begin(),val.end());
        return val[half-1];
    }
};