class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int x=0,y=0;
        int m = matrix.size();
        int n = matrix[0].size();
        //右，下，左，上
        vector<pair<int,int>>operate={{0,1},{1,0},{0,-1},{-1,0}};
        int ope_now=0;
        int cnt= m*n;
        int left_limit=0,right_limit=n-1,up_limit=1,down_limit=m-1;
        while(cnt--){
            ans.push_back(matrix[x][y]);
            if(ope_now==0&&y<right_limit || ope_now==1&&x<down_limit || ope_now==2 && y >left_limit || ope_now==3 &&x>up_limit){
                x=x+operate[ope_now].first;
                y=y+operate[ope_now].second;
            }
            //換方向，更改邊界
            else{
                if(ope_now==0) right_limit--;
                if(ope_now==1) down_limit--;
                if(ope_now==2) left_limit++;
                if(ope_now==3) up_limit++;
                ope_now = (ope_now+1)%4;
                x=x+operate[ope_now].first;
                y=y+operate[ope_now].second;
            }
        }
        return ans; 
    }
};