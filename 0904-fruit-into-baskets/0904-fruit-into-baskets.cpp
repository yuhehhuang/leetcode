class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>bucket;
        int left=0;
        int ans=INT_MIN;
        for(int right=0;right<fruits.size();++right){
            bucket[fruits[right]]++;
            while(bucket.size()>2){
                bucket[fruits[left]]--;
                if(bucket[fruits[left]]==0){
                    bucket.erase(fruits[left]);
                }
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};