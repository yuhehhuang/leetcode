class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        map<vector<int>,int>mp;
        int cnt=0;
        for(int i=0;i<grid.size();i++){
                mp[grid[i]]++;
        }
        for(int i=0;i<grid.size();i++){
            vector<int>col;
            for(int j=0;j<grid.size();j++){
                col.push_back(grid[j][i]);
            }
            if(mp.find(col)!=mp.end()){
                cnt+=mp[col];
            }       
        }
        return cnt;
    }
};