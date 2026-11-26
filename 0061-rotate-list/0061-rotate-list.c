/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head==NULL){
        return NULL;
    }
    //先建立環
    struct ListNode* cur = head;
    int cnt=0;
    while(cur->next!=NULL){
        ++cnt;
        cur=cur->next;
    }
    ++cnt;
    cur->next=head;
    //找尾巴 ,new_head=tail->next, tail->next=NULL/
    int true_rot = k%cnt;
    struct ListNode* tmp =head;
    int cnt_rot = cnt - true_rot - 1;
    while(cnt_rot--){
        tmp=tmp->next;
    }
    struct  ListNode* new_head = tmp->next;
    struct  ListNode* new_tail = tmp;
    new_tail->next=NULL;
    return new_head;
}