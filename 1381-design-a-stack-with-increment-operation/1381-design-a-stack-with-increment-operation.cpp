class CustomStack {
public:
    int maxSize;
    int index=0;//頭元素index
    int cnt=0;//目前有幾個元素在stack
    int arr[1000];
    CustomStack(int maxSize) {
        this->maxSize=maxSize;
    }
    
    void push(int x) {
        if(cnt<maxSize){
            index=(index==0)?maxSize-1:index-1;
            arr[index]=x;
            cnt++;
            return;
        }
        return;
    }
    
    int pop() {
        if(cnt==0){
            return -1;
        }
        int tmp=arr[index];
        index=(index==maxSize-1)?0:index+1;
        cnt--;
        return tmp;
    }
    
    void increment(int k, int val) {
        for(int i=maxSize-1;i>maxSize-1-min(k,cnt);i--){
            arr[i]+=val;
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