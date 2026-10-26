/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        return head;
    }
    struct ListNode* dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next=head;
    struct ListNode* Prev=dummy;
    struct ListNode* Cur=head;
    struct ListNode* Next=head->next;
    while(Cur!=NULL&&Cur->next!=NULL){
        Prev->next=Next;
        Cur->next=Next->next;
        Next->next=Cur;
        Prev=Cur;
        Cur=Cur->next;
        Next=(Cur==NULL)?NULL:Cur->next;
    }
    return dummy->next;
}