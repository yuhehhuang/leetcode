class MyQueue {
public:
    stack<int> staIn;
    stack<int> staOut;
    MyQueue() {
        
    }
    
    void push(int x) {
        staIn.push(x);
    }
    
    int pop() {
        if(staOut.empty()){
            while(!staIn.empty()){
                staOut.push(staIn.top());
                staIn.pop();
            }
        }
        int result=staOut.top();
        staOut.pop();
        return result;
        
    }
    
    int peek() {
        int ans=this->pop();
        staOut.push(ans);
        return ans;
    }
    
    bool empty() {
        return staIn.empty()&&staOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */