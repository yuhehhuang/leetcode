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
        //每次記住沒有重疊的這些set裡 最右邊的intervals[i] = [starti, endi] 又排好序了所以只要比最右邊那個看看有沒有重疊(因為要比的人 starti+1>starti，要重疊一定發生在目前最右邊的元素)
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