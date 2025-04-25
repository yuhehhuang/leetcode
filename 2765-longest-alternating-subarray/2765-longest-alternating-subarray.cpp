class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int ans=-1;
        for(int i=0;i<nums.size()-1;++i){
            int dif=nums[i+1]-nums[i];
            if(dif!=1){continue;}
            bool flip=true;
            int start=i;
            int j=i;
            while(j<nums.size()-1&&((flip&&nums[j+1]-nums[j]==1)||(!flip&&nums[j+1]-nums[j]==-1))){
                flip=!flip;
                j++;
            }
            if(j!=start){
                ans=max(ans,j-start+1);
            }
        }
        return ans;
    }
};