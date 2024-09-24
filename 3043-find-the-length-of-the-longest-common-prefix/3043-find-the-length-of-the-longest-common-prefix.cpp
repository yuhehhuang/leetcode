
class Solution {
public:
//先做arr1的所有prefix可能放進map
//之後再用arr2去做對比是否有這個prefix
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans=0;
        unordered_map<string,int>mp;
        for(int i=0;i<arr1.size();i++){
            string arr1_x=to_string(arr1[i]);
            string prefix_1;
            for(int j=0;j<arr1_x.length();j++){
                prefix_1+=arr1_x[j];
                mp[prefix_1]++;
            }
        }
        for(int i=0;i<arr2.size();i++){
            string arr2_x=to_string(arr2[i]);
            string prefix_2;
            for(int j=0;j<arr2_x.length();j++){
                prefix_2+=arr2_x[j];
                if(mp.find(prefix_2)!=mp.end()){
                    ans=max((int)prefix_2.length(),ans);
                }
            }
        }
        return ans;
    }
};