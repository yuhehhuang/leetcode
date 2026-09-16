class LRUCache {
public:
    int capacity;
    list<pair<int,int>>cache_list;
    unordered_map<int,list<pair<int,int>>::iterator>key_to_iter;
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(key_to_iter.find(key)!=key_to_iter.end()){
            auto node_iter=key_to_iter[key];
            cache_list.splice(cache_list.begin(),cache_list,node_iter);
            return node_iter->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto ump_iter=key_to_iter.find(key);
        if(ump_iter!=key_to_iter.end()){
            auto list_iter=ump_iter->second;
            list_iter->second=value;
            cache_list.splice(cache_list.begin(),cache_list,list_iter);
            return;
        }
        //case no this key;
        cache_list.emplace_front(key,value);
        key_to_iter[key]=cache_list.begin();
        if(key_to_iter.size()>capacity){
            key_to_iter.erase(cache_list.back().first);
            cache_list.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */