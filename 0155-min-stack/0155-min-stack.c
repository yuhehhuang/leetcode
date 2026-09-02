typedef struct Node{
    int val;
    int min;
    struct Node* next;
}Node;


typedef struct {
    Node* head;
} MinStack;


MinStack* minStackCreate() {
    MinStack* obj =(MinStack*)malloc(sizeof(MinStack));
    obj->head=NULL;
    return obj;
}

void minStackPush(MinStack* obj, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val=value;
    if(obj->head==NULL||value<obj->head->min){
        newNode->min=value;
    }
    else{
        newNode->min=obj->head->min;
    }
    newNode->next=obj->head;
    obj->head=newNode;
}

void minStackPop(MinStack* obj) {
    if(obj->head==NULL){
        return;
    }
    Node* tmp=obj->head;
    obj->head=obj->head->next;
    free(tmp);
}

int minStackTop(MinStack* obj) {
    return obj->head->val;
}

int minStackGetMin(MinStack* obj) {
    return obj->head->min;
}

void minStackFree(MinStack* obj) {
    Node *cur=obj->head;
    while(cur!=NULL){
        Node* tmp=cur;
        cur=cur->next;
        free(tmp);
    }
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, value);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/