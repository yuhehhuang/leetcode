class Solution {
public:
 vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
      unordered_map<int,int>mp;
      vector<vector<int>> ans(2);
      //value=0表示兩邊都有 1表示arr1才有 2表示arr2才有
      for(int ele:nums1){
          mp[ele]=1;
      }
      for(int ele:nums2){
          if(mp.find(ele)!=mp.end()&&mp[ele]!=2){
              mp[ele]=0;
          }
          else
          mp[ele]=2;
      }
      for(auto itr:mp){
          if(itr.second==1){
              ans[0].push_back(itr.first);
          }
          else if(itr.second==2){
              ans[1].push_back(itr.first);
          }
      }
      return ans;
 }
        
};