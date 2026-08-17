class RandomizedSet {
public:
    vector<int>vec;
    unordered_map<int,int>mp;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        vec.push_back(val);
        mp[val]=vec.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()){
            return false;
        }
        unordered_map<int,int>::iterator it=mp.find(val);
        int index=it->second;
        //把最後一個元素搬到即將刪除的val他原本的index
        mp[vec.back()]=index;
        mp.erase(val);
        vec[index]=vec.back();
        vec.pop_back();
        return true;

    }
    
    int getRandom() {
        int index = rand()%vec.size();
        return vec[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */