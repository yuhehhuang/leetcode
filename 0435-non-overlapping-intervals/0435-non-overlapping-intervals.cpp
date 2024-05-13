
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
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