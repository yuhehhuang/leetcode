class MinStack {
    vector<pair<int,int>>vec;
    int min=INT_MAX;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        pair<int,int>x;
        if(value<min){
            min=value;
        }
        x.first=value;
        x.second=min;
        vec.push_back(x);
    }
    
    void pop() {
        int x=vec.back().second;
        vec.pop_back();
        if(!vec.empty())min=vec.back().second;
        else{
            min=INT_MAX;
        }
    }
    
    int top() {
        int x= vec.back().first;
        return x;
    }
    
    int getMin() {
        return vec.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */