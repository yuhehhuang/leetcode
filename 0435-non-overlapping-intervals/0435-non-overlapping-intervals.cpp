class cmp {
public:
    bool operator()(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        else {
            return a[0] < b[0];
        }
    }
};

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp());
        int ans = 0;
        int left=intervals[0][0];
        int right = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0]>=right){//不可能重疊啦
                right=intervals[i][1];
                left=intervals[i][0];
            }
            else{ //絕對重疊啦
                ans++;
                int tmp=intervals[i][1];
                right=min(right,intervals[i][1]); //選尾值小 因為這樣比較不容易重疊
                if(tmp==intervals[i][1]){
                    left=intervals[i][0];
                }
            }
        }

        return ans;
    }
};