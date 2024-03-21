class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trust_other(n+1,0);
        vector<int> be_trusted(n+1,0);
        for(vector<vector<int>>::iterator it =trust.begin();it!=trust.end();it++){
            trust_other[(*it)[0]]++;
            be_trusted[(*it)[1]]++;
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            if(trust_other[i]==0&&be_trusted[i]==n-1){
                ans=i;
            }
        }
        return ans;
    }
};