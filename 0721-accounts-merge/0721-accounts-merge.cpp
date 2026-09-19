class Solution {
public:
    unordered_set<string>email_set;
    unordered_map<string,vector<int>>email_to_idx;
    void dfs(vector<vector<string>>& accounts,vector<bool>&vis,int index){
        vis[index]=true;
        for(int k=1;k<accounts[index].size();++k){
            string email=accounts[index][k];
            if(email_set.contains(email)){
                continue;
            }
            email_set.insert(email);
            for(int j:email_to_idx[email]){
                if(!vis[j]){
                    dfs(accounts,vis,j);
                }
            }
        }
        return ;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for(int i=0;i<accounts.size();++i){
            for(int j=1;j<accounts[i].size();++j){
                email_to_idx[accounts[i][j]].push_back(i);
            }
        }
        vector<bool>vis(accounts.size(),false);//紀錄這個index是否已經調查過。
        vector<vector<string>>ans;
        for(int i=0;i<vis.size();++i){
            if(vis[i]){
                continue;
            }
            email_set.clear();
            dfs(accounts,vis,i);
            vector<string>res={accounts[i][0]};
            res.insert(res.end(),email_set.begin(),email_set.end());
            sort(res.begin()+1,res.end());
            ans.push_back(res);
        }
        return ans;
    }
};