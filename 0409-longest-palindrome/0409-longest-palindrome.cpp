class Solution {
public:
    int longestPalindrome(string s) {
        //pair 2 ans single 1;
        int ans=0;
        int one_odd=false;
        unordered_map<int,int>mp;
        for(int i=0;i<s.length();++i){
            mp[s[i]]++;
        }
        for(unordered_map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
            if(it->second%2==0){
                ans+=it->second;
            }
            else{
                one_odd=true;
                ans+=it->second-1;
            }
        }
        if(one_odd){
            ans+=1;
        }
        return ans;
    }
};