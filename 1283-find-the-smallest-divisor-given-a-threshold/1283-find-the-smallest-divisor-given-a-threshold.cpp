class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
       //找到最小的divisor使 sum:nums[i]/divisor<=threshold
       sort(nums.begin(),nums.end());
       int left=1;
       int right=nums[nums.size()-1];
       while(left<=right){
        int mid=(left+right)/2;
        int sum=0;
        for(int i=0;i<nums.size();++i){
            sum+=nums[i]/mid;
            if(nums[i]%mid!=0){
                sum+=1;
            }
        }
        if(sum>threshold){
            left=mid+1;//left以左的divisor,sum>threshold
        }
        else{
            right=mid-1; //right以右的divisor,sum<=threshold
        }
       }
       return right+1;
    }
};