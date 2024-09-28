class MyCircularDeque {
public:
vector<int>q;
int k;
int front;
int back;
int size;
    MyCircularDeque(int k) :q(k),k(k),front(0),back(k-1),size(0){
        
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        front=(front-1+k)%k;
        q[front]=value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        back=(back+1)%k;
        q[back]=value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        front=(front+1)%k;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        back=(back-1+k)%k;
        size--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return q[front];
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return q[back];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */