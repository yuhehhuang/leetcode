class CustomStack {
public:
    int maxSize;
    int index=0;//頭元素index
    int cnt=0;//目前有幾個元素在stack
    vector<int>vec;
    CustomStack(int maxSize) {
        this->maxSize=maxSize;
        vec.resize(maxSize);
    }
    
    void push(int x) {
        if(cnt<maxSize){
            vec[index]=x;
            index++;
            cnt++;
            return;
        }
        return;
    }
    
    int pop() {
        if(cnt==0){
            return -1;
        }
        index--;
        int tmp=vec[index];
        cnt--;
        return tmp;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<min(k,cnt);i++){
            vec[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */