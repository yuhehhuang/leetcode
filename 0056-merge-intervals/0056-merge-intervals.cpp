class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int left_edge=intervals[0][0];
        int right_edge=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=right_edge){
                right_edge=max(right_edge,intervals[i][1]);
            }
            else{
                ans.push_back({left_edge,right_edge});
                left_edge=intervals[i][0];
                right_edge=intervals[i][1];
            }
        }
        ans.push_back({left_edge,right_edge});
        return ans;
        
    }
};