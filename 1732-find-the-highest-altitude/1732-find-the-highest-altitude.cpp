class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int>tmp(gain.size()+1,0);
        int ans=0;
        for(int i=1;i<tmp.size();i++){
            tmp[i]=tmp[i-1]+gain[i-1];
            if(tmp[i]>ans){
                ans=tmp[i];
            }
        }
        return ans;
    }
};
