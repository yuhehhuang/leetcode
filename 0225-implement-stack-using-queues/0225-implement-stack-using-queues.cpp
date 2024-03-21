class MyStack {
public:
    queue<int>m1,m2;
    MyStack() {
        
    }
    
    void push(int x) {
        m1.push(x);
    }
    
    int pop() {
        int count=m1.size()-1;
        while(count--){
            m2.push(m1.front());
            m1.pop();
        }
        int ans=m1.front();
        m1.pop();
        while(m2.size()!=0){
            m1.push(m2.front());
            m2.pop();
        }
        return ans;
    }
    
    int top() {
        return m1.back();
    }
    
    bool empty() {
        return m1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */