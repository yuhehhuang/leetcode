class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<strs.size();++i){
            string s_sort = strs[i];
            sort(s_sort.begin(),s_sort.end());
            mp[s_sort].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(unordered_map<string,vector<string>>::iterator it=mp.begin();it!=mp.end();it++ ){
            ans.push_back(it->second);
        }
        return ans;
    }
};