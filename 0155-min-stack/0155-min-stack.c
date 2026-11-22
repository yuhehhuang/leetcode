struct stack_node{
    int val;
    struct stack_node *next;
    int min;
}typedef Node;

typedef struct {
    Node*head;
    int size;
    //maybe int min; (等等決定)
} MinStack;


MinStack* minStackCreate() {
    MinStack *obj = (MinStack*)malloc(sizeof(MinStack));
    obj->size=0;
    obj->head=NULL;
    return obj;
}

void minStackPush(MinStack* obj, int value) {
    Node* unit = (Node*)malloc(sizeof(Node));
    unit->val=value;
    if(obj->head==NULL){
        obj->head=unit;
        unit->next=NULL;
        unit->min=value;
    }
    else{
        if(obj->head->min<=value){
            unit->min=obj->head->min;
        }
        else{
            unit->min=value;
        }
        unit->next=obj->head;
        obj->head=unit;

    }
    obj->size++;
    return;
}

void minStackPop(MinStack* obj) {
    Node* tmp = obj->head;
    obj->head=obj->head->next;
    free(tmp);
    obj->size--;
    return;
}

int minStackTop(MinStack* obj) {
    return obj->head->val;
}

int minStackGetMin(MinStack* obj) {
    return obj->head->min;
}

void minStackFree(MinStack* obj) {
    int cnt = obj->size;
    Node*cur=obj->head;
    for(int i=0;i<cnt;++i){
        Node*tmp =cur;
        cur=cur->next;
        free(tmp);
    }
    free(obj);
    return ;
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