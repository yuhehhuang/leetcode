class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int>tmp(gain.size()+1,0);
        int ans=0;
        for(int i=1;i<gain.size()+1;i++){
            tmp[i]=tmp[i-1]+gain[i-1];
        }
        for(int i=0;i<tmp.size();i++){
            ans=max(ans,tmp[i]);
        }
        return ans;
    }
};