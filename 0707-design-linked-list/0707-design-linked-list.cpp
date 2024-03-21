class MyLinkedList {
public:
     struct Node{
         int val;
         Node* next;
         Node(int val){
             this->val=val;
             this->next=NULL;
         }
     };
     int size;
     Node* dummyHead;
    MyLinkedList() {
        size=0;
        dummyHead=new Node(0);
    }
    
    int get(int index) {
        if(index<0||index>size-1){
            return -1;
        }
        Node*cur=dummyHead->next;
        while(index--){
            cur=cur->next;
        }
        return cur->val;
        
    }
    
    void addAtHead(int val) {
        Node* newNode =new Node(val);
        newNode->next=dummyHead->next;
        dummyHead->next=newNode;
        size++;
        
    }
    
    void addAtTail(int val) {
        Node* newNode=new Node(val);
        Node* cur=dummyHead;
        while(cur->next!=NULL){
            cur=cur->next;
        }
        cur->next=newNode;
        size++;
        
    }
    
    void addAtIndex(int index, int val){
        Node* newNode=new Node(val);
        if(index>size){
            return ;
        }
        Node* cur=dummyHead;
        while(index--){
            cur=cur->next;
        }
        newNode->next=cur->next;
        cur->next=newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index>=size||index<0){
            return ;
        }
        Node* cur=dummyHead;
        while(index--){
            cur=cur->next;
        }
        Node*tmp=cur->next;
        cur->next=cur->next->next;
        delete tmp;
        tmp=NULL;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */