class cmp{
    public:
 bool operator()(vector<int>&a,vector<int>&b){
        return a[0]<b[0];
 }
};
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp());
        int ans=1;//一定會切一刀，所以我先預給
        if(points.size()==1){
            return 1;
        }
        for(int i=1;i<points.size();i++){
            if(points[i][0]>points[i-1][1]){
                ans++;
            }
            else{
                points[i][1]=min(points[i][1],points[i-1][1]);
            }
        }
        return ans;
    }
};