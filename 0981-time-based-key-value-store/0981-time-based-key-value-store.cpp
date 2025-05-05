class TimeMap {
public:
//(key,time)->value 
//mp[key]->vector<pair<int,string>> vector紀錄(time,value)
    static bool cmp(const pair<int,string>&a,const pair<int,string>&b){
        return a.first<b.first;
    }
    unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(pair(timestamp,value));
    }
    //return timestamp之前(包含)的set(key,t')=>在vector找第一個>=(timestamp+1,"")的位置-1;
    string get(string key, int timestamp) {
        if (!mp.count(key)) return "";
        vector<pair<int,string>>& tmp = mp.at(key);
        int j=lower_bound(tmp.begin(),tmp.end(),pair(timestamp+1,""),cmp)-tmp.begin()-1;
        return j>=0?tmp[j].second:"";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */