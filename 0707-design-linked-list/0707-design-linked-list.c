struct List_Node {
    int value;
    struct List_Node* next; //紀錄下一個node
    struct List_Node* prev; //紀錄前一個node
}typedef Node;

typedef struct {
    Node* head;
    int size;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList*obj =(MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head=NULL;
    obj->size=0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if(index>=obj->size){
        return -1;
    }
    int cnt = 0;
    Node* cur =obj->head;
    while(cur!=NULL){
        if(cnt!=index){
            cur=cur->next;
            cnt++;
        }
        else if(cnt==index){
            return cur->value;
        }
    }
    return -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    obj->size++;
    Node* unit =(Node*)malloc(sizeof(Node));
    unit->value = val;
    //分兩種情況
    //第一種目前沒有節點
    if(obj->head==NULL){
        obj->head = unit;
        unit->next=unit;
        unit->prev=unit;
    }
    else{
        unit->next=obj->head;
        unit->prev=obj->head->prev;
        obj->head->prev->next=unit;//原本最後一個元素的next連到new node;
        obj->head->prev=unit; //原本第一個元素的prev連到new node;
        obj->head = unit;
    }
    return ;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    obj->size++;
    Node* unit =(Node*)malloc(sizeof(Node));
    unit->value = val;
    if(obj->head==NULL){
        obj->head=unit;
        unit->next=unit;
        unit->prev=unit;
    }
    else{
        unit->next=obj->head;
        unit->prev=obj->head->prev;
        obj->head->prev->next=unit;
        obj->head->prev = unit;
    }
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(index>obj->size){
        return ;
    }
    if(index==0){
        myLinkedListAddAtHead(obj,val);
        return;
    }
    if(index==obj->size){
        myLinkedListAddAtTail(obj,val);
        return;
    }
    //double linked list index==size時效果跟index =0一樣
    Node *cur=obj->head;
    int cnt=index;
    while(cnt--){
        cur=cur->next;
    }
    Node*unit=(Node*)malloc(sizeof(Node));
    unit->value=val;
    unit->next=cur;
    unit->prev=cur->prev;
    cur->prev->next=unit;
    cur->prev=unit;
        obj->size++;
    return;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index>=obj->size||obj->head==NULL){
        return ;
    }
    Node*cur=obj->head;
    int cnt=index;
    while(cnt--){
        cur=cur->next;
    }
    if(obj->size==1){
        obj->head=NULL;
    }
    else{
        cur->next->prev=cur->prev;
        cur->prev->next=cur->next;
        if(cur==obj->head){
            obj->head=cur->next;
        }
    }
    obj->size--;
    free(cur);
    return;
}

void myLinkedListFree(MyLinkedList* obj) {
    if(obj==NULL){
        return ;
    }
    Node*cur=obj->head;
    for(int i=0;i<obj->size;++i){
        Node* next=cur->next;
        free(cur);
        cur=next;
    }
    free(obj);
    return;
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