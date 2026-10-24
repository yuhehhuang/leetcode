typedef struct Node{
    int val;
    int min;
    struct Node *next;
}Node;


typedef struct MinStack{
    Node* head;
} MinStack;


MinStack* minStackCreate() {
    MinStack* obj=(MinStack*)malloc(sizeof(MinStack));
    obj->head=NULL;
    return obj;
}

void minStackPush(MinStack* obj, int value) {
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->val=value;
    if(obj->head==NULL){
        new_node->next=NULL;
        new_node->min=value;
        obj->head=new_node;
        return;
    }
    new_node->next=obj->head;
    new_node->min=obj->head->min<=value?obj->head->min:value;
    obj->head=new_node;
    return;
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
    while(obj->head!=NULL){
        Node* tmp=obj->head;
        obj->head=tmp->next;
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