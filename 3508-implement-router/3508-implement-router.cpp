class Router {
public:
    int limit;
    queue<int>q;
    unordered_map<int,deque<array<int,3>>>m;
    set<array<int,3>>s;
    Router(int memoryLimit) {
        limit=memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if(s.find({timestamp,source,destination})==s.end()){
           q.push(destination);
           s.insert({timestamp,source,destination});
           m[destination].push_back({timestamp,source,destination});
           if(s.size()>limit){
            int f=q.front();
            array<int,3>aa=m[f].front();
            s.erase(aa);
            q.pop();
            m[f].pop_front();
           }
           return true;
        }
        return false;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()){
            return {};
        }
        int f=q.front();
        array<int,3>a=m[f].front();
        s.erase(a);
        q.pop();
        m[f].pop_front();
        return {a[1],a[2],a[0]};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        deque<array<int,3>>&tmp=m[destination];
        auto l=lower_bound(tmp.begin(),tmp.end(),array{startTime,0,0});
        auto r=upper_bound(tmp.begin(),tmp.end(),array{endTime,INT_MAX,INT_MAX});
        return r-l;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */