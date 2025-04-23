class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans=0;
        int i=1;
        while(i<arr.size()-1){
            if(arr[i]>arr[i+1]&&arr[i]>arr[i-1]){
                int left=i-1;
                int right=i+1;
                while(right<arr.size()-1&&arr[right]>arr[right+1]){
                    right++;
                }
                while(left>0&&arr[left]>arr[left-1]){
                    left--;
                }
                ans=max(ans,right-left+1);
                i=right+1;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};