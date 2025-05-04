class SnapshotArray {
public:
    int cur_snap_id = 0;
    unordered_map<int,vector<pair<int,int>>>history;
    //紀錄每個index 在每個time slot的value;
    SnapshotArray(int length) {
    }
    
    void set(int index, int val) {
        history[index].push_back(pair<int,int>(cur_snap_id,val));
    }
    
    int snap() {
        return cur_snap_id++;
    }
    
    int get(int index, int snap_id) {
        vector<pair<int,int>>&h=history[index];
        int j=ranges::lower_bound(h,pair(snap_id+1,0))-h.begin()-1;
        return j>=0?h[j].second:0;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */