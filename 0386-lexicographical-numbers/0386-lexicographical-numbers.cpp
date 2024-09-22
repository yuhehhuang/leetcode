class Solution {
public:
    void solve(int count_num,int n,vector<int>& v){
        if(count_num>n){
            return ;
        }
        v.push_back(count_num);
        for(int i=0;i<=9;i++){
            solve(count_num*10+i,n,v);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1;i<=9;i++){
            solve(i,n,ans);
        }
        return ans;
    }
};