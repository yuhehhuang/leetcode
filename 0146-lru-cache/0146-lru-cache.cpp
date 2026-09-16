class LRUCache {
    int capacity;
    list<pair<int,int>>cache_list;
    unordered_map<int,list<pair<int,int>>::iterator>key_to_iter;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        auto umap_iter=key_to_iter.find(key);
        if(umap_iter==key_to_iter.end()){
            return -1;
        }
        auto list_iter=umap_iter->second;
        cache_list.splice(cache_list.begin(),cache_list,list_iter);
        return list_iter->second;
    }
    
    void put(int key, int value) {
        auto umap_iter=key_to_iter.find(key);
        //case 已經有key，刷新key對應的value;
        if(umap_iter!=key_to_iter.end()){
            auto list_iter=umap_iter->second;
            list_iter->second=value;
            cache_list.splice(cache_list.begin(),cache_list,list_iter);
            return;
        }
        //case 沒有這key;
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