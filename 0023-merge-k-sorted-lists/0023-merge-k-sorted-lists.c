/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* merge(struct ListNode* list1,struct ListNode* list2){
    struct ListNode* ans=NULL;
    struct ListNode* cur=NULL;
    if(list1==NULL||list2==NULL){
        return list1==NULL?list2:list1;
    }
    while(list1!=NULL&&list2!=NULL){
        struct ListNode* new_node=(struct ListNode*)malloc(sizeof(struct ListNode));
        if(cur==NULL){
            ans=new_node;
            cur=new_node;
            new_node->next=NULL;
            if(list1->val<list2->val){
                new_node->val=list1->val;
                list1=list1->next;
            }
            else{
                new_node->val=list2->val;
                list2=list2->next;
            }
        }
        else{
            new_node->next=NULL;
            cur->next=new_node;
            cur=cur->next;
            if(list1->val<list2->val){
                new_node->val=list1->val;
                list1=list1->next;
            }
            else{
                new_node->val=list2->val;
                list2=list2->next;
            }
        }
    }
    if(list1==NULL){
      cur->next=list2;  
    }
    if(list2==NULL){
        cur->next=list1;
    }
    return ans;   
}
struct ListNode* mergeKList_helper(struct ListNode**lists,int left,int right){
    if(left==right){
        return lists[left];
    }
    int mid=left+(right-left)/2;
    struct ListNode* l1=mergeKList_helper(lists,left,mid);
    struct ListNode* l2=mergeKList_helper(lists,mid+1,right);
    return merge(l1,l2);
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if(listsSize==0){
        return NULL;
    }
    return mergeKList_helper(lists,0,listsSize-1);
}