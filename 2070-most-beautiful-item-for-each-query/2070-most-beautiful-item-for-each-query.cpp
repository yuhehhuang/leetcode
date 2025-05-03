class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[0]<b[0];
    }
    int BS(vector<vector<int>>&nums,int n){
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid][0]>n){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return right;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end(),cmp);
        for(int i=1;i<items.size();++i){
            items[i][1]=max(items[i][1],items[i-1][1]);
        }
        for(int&q:queries){
            int j=BS(items,q);
            q=(j>=0)?items[j][1]:0;
        }
        return queries;
    }
};