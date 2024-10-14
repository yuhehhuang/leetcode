class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>que;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            que.push(nums[i]);
        }
        for(int i=0;i<k;i++){
            int val=que.top();
            sum+=val;
            que.pop();
            if(val%3==0){
                que.push(val/3);
            }
            else{
                que.push(val/3+1);
            }
        }
        return sum;
    }
};