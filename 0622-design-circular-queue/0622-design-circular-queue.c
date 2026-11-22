struct Queue_Node{
    int val;
    struct Queue_Node* next;
    struct Queue_Node* prev;
}typedef Node;
typedef struct {
    struct Queue_Node*front;
    struct Queue_Node*rear;
    int size;
    int capacity;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue * obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->front=NULL;
    obj->rear = NULL;
    obj->size = 0;
    obj->capacity = k;
    return obj;
}
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if(obj->size==0){
        return true;
    }
    return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if(obj->capacity == obj->size){
        return true;
    }
    return false;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(obj==NULL){
        return false;
    }
    if(myCircularQueueIsFull(obj)){
        //capacity is full cant push more data in.
        return false;
    }
    Node *unit = (Node*)malloc(sizeof(Node));
    unit->val=value;
    if(myCircularQueueIsEmpty(obj)){
        obj->front=unit;
        obj->rear=unit;
        unit->next=unit;
        unit->prev=unit;
    }
    else{
        unit->next=obj->front;
        unit->prev=obj->rear;
        obj->rear->next=unit;
        obj->front->prev=unit;
        obj->rear=unit;
    }
    obj->size++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(obj==NULL){
        return false;
    }
    if(myCircularQueueIsEmpty(obj)){
        return false;
    }
    if(obj->size==1){
        free(obj->front);
        obj->front=NULL;
        obj->rear=NULL;
    }
    else{
        Node*tmp = obj->front;
        obj->front=obj->front->next;
        obj->front->prev=obj->rear;
        obj->rear->next=obj->front;
        free(tmp);
    }
    obj->size--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
        return -1;
    }
    return obj->front->val;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
        return -1;
    }
    return obj->rear->val;
}


void myCircularQueueFree(MyCircularQueue* obj) {
    int k = obj->size;
    Node*cur=obj->front;
    for(int i=0;i<k;++i){
        Node*tmp =cur;
        cur=cur->next;
        free(tmp);
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