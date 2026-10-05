
typedef struct Node{
    int val;
    struct Node *next;
}Node;

typedef struct {
    Node* head ;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj=(MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head=NULL;
    return obj;
}
int myLinkedListGet(MyLinkedList* obj, int index) {
    Node *cur=obj->head;
    for(int i=0;cur!=NULL;i++){
        if(i==index){
            return cur->val;
        }
        cur=cur->next;
    }
    return -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node *cur=obj->head;
    Node* new_head=(Node*)malloc(sizeof(Node));
    new_head->val=val;
    new_head->next=cur;
    obj->head=new_head;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node *cur = obj->head;
    if(cur==NULL){
        myLinkedListAddAtHead(obj,val);
        return;
    }
    Node *tail=NULL;
    while(cur!=NULL){
        tail=cur;
        cur=cur->next;
    }
    Node *last  = (Node*)malloc(sizeof(Node));
    last->val=val;
    last->next=NULL;
    tail->next=last;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(index==0){
        myLinkedListAddAtHead(obj,val);
        return;
    }
    Node *cur=obj->head;
    Node*tail=NULL;
    int i=0;
    for( i=0;cur!=NULL;++i){
        if(i==index){
            Node* add_node=(Node*)malloc(sizeof(Node));
            tail->next=add_node;
            add_node->val = val;
            add_node->next=cur;
            return;
        }
        tail=cur;
        cur=cur->next;
    }
    if(i==index){
        Node* add_node=(Node*)malloc(sizeof(Node));
        add_node->val=val;
        tail->next=add_node;
        add_node->next=NULL;
    }
    return ;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index==0&&obj->head!=NULL){
        Node* tmp= obj->head;
        Node* next=obj->head->next;
        free(tmp);
        obj->head=next;
        return;
    }
    Node *cur =obj->head;
    Node *prev=NULL;
    for(int i=0;cur;++i){
        if(index==i){
            prev->next=cur->next;
            free(cur);
            return;
        }
        prev=cur;
        cur=cur->next;
    }
    return ;
}

void myLinkedListFree(MyLinkedList* obj) {
    Node* cur=obj->head;
    while(cur){
        Node* tmp = cur;
        cur=cur->next;
        free(tmp);
    }
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