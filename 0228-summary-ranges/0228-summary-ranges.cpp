class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        //遇到第一個不連續的就進行存檔
        vector<string>ans;
        int i=0;
        while(i<nums.size()){
            int start=i;
            string tmp;
            while(i<nums.size()-1&&(long long)nums[i + 1] - (long long)nums[i] == 1){
                i++;
            }
            if(i-start){
                tmp=to_string(nums[start]);
                tmp+="->";
                tmp+=to_string(nums[i]);
            }
            else{
                tmp=to_string(nums[start]);
            }
            i++;
            ans.push_back(tmp);
        }
        return ans;
    }
};