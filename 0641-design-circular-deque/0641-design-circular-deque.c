typedef struct Node{
    int val;
    struct Node* next;
    struct Node* prev;
}Node;

typedef struct {
    Node* head;
    Node* tail;
    int capacity;
    int size;
} MyCircularDeque;


MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* obj=(MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    obj->head=NULL;
    obj->tail=NULL;
    obj->capacity=k;
    obj->size=0;
    return obj;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if(obj->capacity<=obj->size){
        return false;
    }
   Node* new_node= (Node*)malloc(sizeof(Node));
   new_node->val=value;
   if(obj->head==NULL){
    new_node->next=new_node;
    new_node->prev=new_node;
    obj->head=new_node;
    obj->tail=new_node;
   }
   else{
    new_node->next=obj->head;
    new_node->prev=obj->tail;
    obj->head->prev=new_node;
    obj->tail->next=new_node;
    obj->head=new_node;
   }
    obj->size++;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if(obj->capacity<=obj->size){
        return false;
    }
   Node* new_node= (Node*)malloc(sizeof(Node));
   new_node->val=value;
   if(obj->head==NULL){
    new_node->next=new_node;
    new_node->prev=new_node;
    obj->head=new_node;
    obj->tail=new_node;
   }
   else{
    new_node->next=obj->head;
    new_node->prev=obj->tail;
    obj->head->prev=new_node;
    obj->tail->next=new_node;
    obj->tail=new_node;
   }
   obj->size++;
   return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if(obj->size<=0){
        return false;
    }
    Node* tmp=obj->head;
    if(obj->size==1){
        obj->head=NULL;
        obj->tail=NULL;
    }
    else{
    obj->head=tmp->next;
    obj->head->prev=obj->tail;
    obj->tail->next=obj->head;
    }
    obj->size--;
    free(tmp);
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if(obj->size<=0){
        return false;
    }
    Node*tmp=obj->tail;
    if(obj->size==1){
        obj->head=NULL;
        obj->tail=NULL;
    }
    else{
    obj->tail=tmp->prev;
    obj->tail->next=obj->head;
    obj->head->prev=obj->tail;
    }
    obj->size--;
    free(tmp);
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    return (obj->head==NULL)?-1:obj->head->val;
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    return (obj->tail==NULL)?-1:obj->tail->val;
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->size==0;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->size==obj->capacity;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    if(obj==NULL){
        return;
    }
    if(obj->head!=NULL){
        Node* curr=obj->head;
        Node* tail=obj->tail;
        tail->next=NULL;
        while(curr!=NULL){
            Node*tmp=curr;
            curr=curr->next;
            free(tmp);
        }
    }
    free(obj);
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/