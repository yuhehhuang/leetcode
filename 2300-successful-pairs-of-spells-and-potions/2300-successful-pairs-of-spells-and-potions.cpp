class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int>ans;
        for(int i=0;i<spells.size();++i){
            long long target = (success % spells[i] == 0) ? (success / spells[i]) : (success / spells[i] + 1);
            int left=0;
            int right=potions.size()-1;
            while(left<=right){
            int mid = left + (right - left) / 2; // 防止溢位
                if(potions[mid]<target){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
            ans.push_back(potions.size() - left);
        }
        return ans;
    }
};