class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *curNode1,*curNode2,*tmp,*head;
        ListNode dummy(-1);
        ListNode* curNode = &dummy;
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        curNode1=list1;
        curNode2=list2;
        head=curNode;
        while(curNode1!=NULL&&curNode2!=NULL){
            if(curNode1->val<curNode2->val){
                curNode->next=curNode1;
                curNode1=curNode1->next;
            }
            else{
                curNode->next=curNode2;
                curNode2=curNode2->next;
            }
            curNode=curNode->next;
        }
        if(curNode1==NULL){
            curNode->next=curNode2;
        }
        if(curNode2==NULL){
            curNode->next=curNode1;
        }
        return head->next;
    }
}; 