class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
       for(auto it=map.begin();it!=map.end();it++){
           pq.push(make_pair(it->second,it->first));
           if(pq.size()>k){
               pq.pop();
           }
       }
       for(int i=0;i<k;i++){
           ans.push_back(pq.top().second);
           pq.pop();
                  }
                  return ans;
    }
};