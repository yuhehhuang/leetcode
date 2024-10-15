class Solution {
public:
    int maxVowels(string s, int k) {
        int cnt=0;
        queue<int>que;
        for(int i=0;i<k;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                cnt++;
            }
            que.push(s[i]);
        }
         int ans=cnt;
        for(int i=k;i<s.size();i++){
            que.push(s[i]);
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                cnt++;
            }
            if(que.front()=='a'||que.front()=='e'||que.front()=='i'||que.front()=='o'||que.front()=='u'){
                cnt--;
            }
            que.pop();
            ans=max(cnt,ans);
            
        }
        return ans;
    }
};