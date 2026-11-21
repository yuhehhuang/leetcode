struct linkedlist_node{
    int value;
    struct linkedlist_node *next;
}typedef Node;

typedef struct {
    Node *head;   
} MyLinkedList;

//addat tail 跟addat index都有機會加在頭部,會需要更新head
//所以直接呼叫addat head處理就不用function寫得太亂
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj =  (MyLinkedList*)malloc(sizeof(MyLinkedList)); 
    obj->head=NULL;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    Node *cur = obj->head;
    while(cur!=NULL){
        if(index==0){
            return cur->value;
        }
        index--;
        cur=cur->next;
    }
    return -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node * unit = (Node*)malloc(sizeof(Node));
    unit->value=val;
    if(obj->head==NULL){
        obj->head=unit;
        unit->next=NULL;
    }
    else{
        unit->next=obj->head;
        obj->head=unit;   
    }
    return;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    if(obj->head==NULL){
        myLinkedListAddAtHead(obj,val);
        return ;
    }
    Node *unit = (Node*)malloc(sizeof(Node));
    unit->value=val;
    unit->next = NULL;
    Node *cur = obj->head;
    while(cur!=NULL&&cur->next!=NULL){
        cur=cur->next;
    }
    //此時cur指向最後一個節點
    cur->next=unit;
    return ;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(obj==NULL){
        return ;
    }
    if(index==0){
        myLinkedListAddAtHead(obj,val);
        return ;
    }
    Node dummy;
    dummy.next=obj->head;
    Node* cur = &dummy;
    while(cur){
        if(index==0){
           Node* unit=(Node*) malloc(sizeof(Node));
           if(cur->next==NULL){
            //case 加在尾巴
            unit->next=NULL;
           }
           else{
            //case 新增的位置後面有節點
            unit->next = cur->next;
           }
           unit->value=val;
           cur->next=unit;
           return ;
        }
        cur=cur->next;
        index--;
    }
    return ;

}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(obj==NULL||obj->head==NULL){
        return ;
    }
    Node dummy;
    dummy.next=obj->head;
    Node* cur = &dummy;
    while(index>0&&cur!=NULL){
        cur =cur->next;
        index--;
    }
    if(cur==NULL||cur->next==NULL){
        return;
    }
    Node*tmp = cur->next;
    cur->next =cur->next->next;
    free(tmp);
    obj->head=dummy.next;
}

void myLinkedListFree(MyLinkedList* obj) {
    Node* cur =obj->head;
    while(cur){
        Node* tmp =cur->next;
        free(cur);
        cur = tmp;
    }
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/