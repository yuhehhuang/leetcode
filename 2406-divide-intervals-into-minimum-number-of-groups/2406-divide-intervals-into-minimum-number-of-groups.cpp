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
        priority_queue<int, vector<int>, greater<int>> que;//storing each group end time
        int ans = 1;
		que.push(intervals[0][1]);
        for(int i=1;i<intervals.size();++i){//在min_heap head的一定是現在這個intervals[i]最可以放進group裡的，
            if(intervals[i][0]<=que.top()){//跑進這個if表示最有機會的group也放不下==>多一個group，並且記錄這個gruop的結束時間
                que.push(intervals[i][1]);
            }
            else{//跑進這個else表示最有機會的gruop放得下，==>更新這個group的結束時間
                que.pop();
                que.push(intervals[i][1]);
            }
        }
        return que.size();
    }
};