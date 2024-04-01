class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max=INT_MIN;
        for(int i=0;i<candies.size();i++){
            if(candies[i]>max){
                max=candies[i];
            }
        }
        vector<bool>ans(candies.size());
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=max){
                ans[i]=true;
            }
            else ans[i]=false;
        }
        return ans;
    }
};