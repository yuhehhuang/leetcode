class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        if(arr.size()<k){
            return 0;
        }
        int tmp=0;
        int ans=0;
        for(int i=0;i<k;++i){
            tmp+=arr[i];
        }
        if(tmp/k>=threshold){
            ans++;
        }
        for(int i=k;i<arr.size();++i){
            tmp+=arr[i]-arr[i-k];
            if(tmp/k>=threshold){
                ans++;
            }
        }
        return ans;
    }
};