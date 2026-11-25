/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(head==NULL){
        return NULL;
    }
    struct ListNode * cur = head;
    int cnt =0;
    // (cnt-n+1)-th node
    while(cur){
        cnt++;
        cur=cur->next;
    }
    struct ListNode dummy; 
    dummy.next = head;
    // (cnt-n+1)-th node =(cnt-n)-index node 
    int index = cnt-n;
    struct ListNode *iter = &dummy;
    while(index--){
        iter= iter->next;
    }
    struct ListNode *tmp = iter->next;
    iter->next = iter->next->next;
    free(tmp);
    return dummy.next;
}