class Solution {
public:
    static bool cmp(pair<int,int>a,pair<int,int>b){
        return a.second>b.second;
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int,int>>vec;
        for(int i=0;i<n;++i){
            vec.push_back({nums1[i],nums2[i]});
        }
        sort(vec.begin(),vec.end(),cmp);
        priority_queue<int,vector<int>,greater<int>>pq;
        long long sum=0;
        for(int i=0;i<k;++i){
            pair<int,int>cur=vec[i];
            sum+=cur.first;
            pq.push(cur.first);
        }
        long long ans=vec[k-1].second*sum;
        for(k;k<n;++k){
            pair<int,int>cur=vec[k];
            if(cur.first>pq.top()){
                int del=pq.top();
                pq.pop();
                pq.push(cur.first);
                sum+=cur.first-del;
                ans=max(ans,sum*cur.second);
            }
        }
        return ans;
    }
};