typedef struct Node{
    int val;
    struct Node* next;
}Node;


typedef struct {
    int size;
    int capacity;
    Node* head;
    Node* tail;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj=(MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->size=0;
    obj->capacity=k;
    obj->head=NULL;
    obj->tail=NULL;
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(obj->size>=obj->capacity){
        return false;
    }
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->val=value;
    if(obj->size==0){
        new_node->next=new_node;
        obj->head=new_node;
        obj->tail=new_node;
    }
    else{
        obj->tail->next=new_node;
        new_node->next=obj->head;
        obj->tail=new_node;
    }
    obj->size++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(obj->size<=0){
        return false;
    }
    if(obj->size==1){
        Node* tmp=obj->head;
        obj->head=NULL;
        obj->tail=NULL;
        obj->size=0;
        free(tmp);
        return true;
    }
    Node* tmp=obj->head;
    obj->head=obj->head->next;
    obj->tail->next=obj->head;
    free(tmp);
    obj->size--;
    return true;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if(obj->size==0){
        return true;
    }
    return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if(obj->size==obj->capacity){
        return true;
    }
    return false;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)==true){
        return -1;
    }
    return obj->head->val;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)==true){
        return -1;
    }
    return obj->tail->val;
}


void myCircularQueueFree(MyCircularQueue* obj) {
    if(obj==NULL){
        return;
    }
    if(obj->head!=NULL){
        obj->tail->next=NULL;
    }
    Node* cur=obj->head;
    while(cur){
        Node* next_node=cur->next;
        free(cur);
        cur=next_node;
    }
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/