class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //每次淘汰比較遠的
        int left=0;
        int right=arr.size()-1;
        vector<int>ans(k);
        while(right-left+1>k){
            if(abs(arr[left]-x)<=abs(arr[right]-x)){
                //淘汰right
                right--;
            }
            else{
                left++;
            }
        }
        for(int i=left;i<=right;++i){
            ans[i-left]=arr[i];
        }
        return ans;
    }
};