class cmp{
    public:
 bool operator()(vector<int>&a,vector<int>&b){
    if(a[0]==b[0]){
        return a[1]<b[1];
    }
    return a[0]<b[0];
 }
};
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), cmp());
    int num=0;
    int right=intervals[0][1];
    for(int i=1;i<intervals.size();i++){
        if(right>intervals[i][0]){
            num++;
            right = min(right,intervals[i][1]);
        }
        else{
            right=intervals[i][1];
        }
    }
    return num;
    }
};