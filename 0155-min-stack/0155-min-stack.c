typedef struct node{
    int value;
    int min;
    struct node *next;
}node;

//Minstack實際上就是一個node的指標
typedef struct {
    node* head;
} MinStack;

//建立MinStack指標
MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->head=NULL;
    return obj;
}

void minStackPush(MinStack* obj, int value) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->value=value;
    if(obj->head==NULL||obj->head->min>value){
        newnode->min=value;
    }
    else{
        newnode->min=obj->head->min;
    }
    newnode->next=obj->head;
    obj->head=newnode;
    return;   
}

void minStackPop(MinStack* obj) {
    if(obj->head==NULL){
        return;
    }
    node* tmp=obj->head;
    obj->head=obj->head->next;
    free(tmp);
}

int minStackTop(MinStack* obj) {
    return obj->head->value;
}

int minStackGetMin(MinStack* obj) {
    return obj->head->min;
}

void minStackFree(MinStack* obj) {
    node *cur=obj->head;
    while(cur!=NULL){
        node *tmp=cur;
        cur=cur->next;
        free(tmp);
    }
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