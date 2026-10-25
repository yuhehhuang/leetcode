/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* ans=NULL;
    struct ListNode* cur=NULL;
    int carry=0;
    while(l1!=NULL&&l2!=NULL){
        struct ListNode* new_node=(struct ListNode*)malloc(sizeof(struct ListNode));
        new_node->val=(carry+l1->val+l2->val)%10;
        new_node->next=NULL;
        carry=(carry+l1->val+l2->val)/10;
        if(ans==NULL){
            ans=new_node;
            cur=ans;
        }
        else{
            cur->next=new_node;
            cur=cur->next;
        }
        l1=l1->next;
        l2=l2->next;
    }
    while(l1!=NULL){
        struct ListNode* new_node=(struct ListNode*)malloc(sizeof(struct ListNode));
        new_node->val=(carry+l1->val)%10;
        new_node->next=NULL;
        carry=(carry+l1->val)/10;
        cur->next=new_node;
        cur=cur->next;
        l1=l1->next;
    }
    while(l2!=NULL){
        struct ListNode* new_node=(struct ListNode*)malloc(sizeof(struct ListNode));
        new_node->val=(carry+l2->val)%10;
        new_node->next=NULL;
        carry=(carry+l2->val)/10;
        cur->next=new_node;
        cur=cur->next;
        l2=l2->next;
    }
    if(carry>0){
        struct ListNode *new_node=(struct ListNode*)malloc(sizeof(struct ListNode));
        new_node->val=carry;
        new_node->next=NULL;
        cur->next=new_node;
    }
    return ans;
}