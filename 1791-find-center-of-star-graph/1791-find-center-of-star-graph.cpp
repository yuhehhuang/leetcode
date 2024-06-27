class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        for(int i=0;i<=1;i++){
            if(edges[0][i]==edges[1][0]){
                return edges[1][0];
            }
            if(edges[0][i]==edges[1][1]){
                return edges[1][1];
            }
        }
        return -1;
    }
};