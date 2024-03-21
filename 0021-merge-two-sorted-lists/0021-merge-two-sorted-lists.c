/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode head;
    struct ListNode *h=&head; //h是存"head"位置 此位置放的資料結構是struct
    if(list1==NULL && list2==NULL){
        return NULL;
    }
    while(list1!=NULL&&list2!=NULL){
        if(list1->val<list2->val){
            h->next=list1;
            list1=list1->next;
            h=h->next;
        }
        else{
            h->next=list2;
            list2=list2->next;
            h=h->next;
        }
    }
    if(list1==NULL){
        h->next =list2;
    }
    if(list2==NULL){
        h->next=list1;
    }
    return head.next;

   
}