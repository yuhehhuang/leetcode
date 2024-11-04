class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>>que;
    unordered_set<int>set;
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;++i){
            que.push(i);
            set.insert(i);
        }
    }
    
    int popSmallest() {
        int tmp=que.top();
        set.erase(tmp);
        que.pop();
        return tmp;
    }
    
    void addBack(int num) {
        if(set.find(num)==set.end()){
            que.push(num);
            set.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */