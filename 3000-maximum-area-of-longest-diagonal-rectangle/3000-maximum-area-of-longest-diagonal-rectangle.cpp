class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        //求有最大diagnal的area，若diagnal相同就比area大小
        int dia=0; //紀錄max dia
        int ans=0; //紀錄最佳解
        for(int i=0;i<dimensions.size();++i){
            int the_area=dimensions[i][0]*dimensions[i][1];
            int the_dia=dimensions[i][0]*dimensions[i][0]+dimensions[i][1]*dimensions[i][1];
            if(the_dia>=dia){
                if(the_dia==dia){
                    if(the_area>ans){
                        ans=the_area;
                    }
                }
                else{
                    ans=the_area;
                }
                dia=the_dia;
            }
        }
        return ans;
    }
};