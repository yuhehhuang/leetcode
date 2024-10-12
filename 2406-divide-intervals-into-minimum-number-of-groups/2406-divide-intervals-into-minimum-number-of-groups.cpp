bool cmp(vector<int>a,vector<int>b){
    if(a[0]==b[0]){
        //起始點依樣就先做會先結束的
        return a[1]<b[1];
    }
    return a[0]<b[0];
}
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        priority_queue<int, vector<int>, greater<int>> que;
        for(int i=0;i<intervals.size();i++){
            int arrive=intervals[i][0];
            int leave=intervals[i][1];
            if(!que.empty()&&arrive>que.top()){//新進來的時間在原本的活動結束以後，原本活動可以丟掉
                que.pop();
            }
            que.push(leave);
        }
        return que.size();
    }
};