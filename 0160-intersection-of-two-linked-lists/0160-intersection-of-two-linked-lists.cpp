/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA=0;
    int lenB=0;
    ListNode*curA=headA;
    ListNode*curB=headB;
     while(curA!=NULL){
         lenA++;
         curA=curA->next;
     }
    while(curB!=NULL){
         lenB++;
         curB=curB->next;
     }
     if(lenA<lenB){
         swap(lenA,lenB);
         swap(headA,headB);
     }
     int diff=lenA-lenB;
     while(diff--){
         headA=headA->next;
     }
     while(headA!=NULL){
         if(headA==headB){
             return headA;
         }
         headA=headA->next;
         headB=headB->next;
     }
     return NULL;
    }
};