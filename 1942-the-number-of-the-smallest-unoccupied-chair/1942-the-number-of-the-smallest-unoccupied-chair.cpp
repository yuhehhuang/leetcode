class Solution {
public:
    static bool cmp(const pair<int, pair<int, bool>>& a, const pair<int, pair<int, bool>>& b) {
        if (a.first == b.first) {
            // 如果時間相同，先處理離開事件 (isArriving == false)
            return a.second.second < b.second.second;
        }
        // 否則，按照時間排序
        return a.first < b.first;
    }
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        vector<pair<int,pair<int,bool>>>events;
        for(int i=0;i<n;i++){
            events.push_back({times[i][0],{i,true}});
            events.push_back({times[i][1],{i,false}});
        }
        sort(events.begin(),events.end(),cmp);
        priority_queue<int,vector<int>,greater<int>>availableChair;//可用的椅子 編號小的優先
        for(int i=0;i<n;i++){
            availableChair.push(i);
        }
        vector<int>occupiedChair(n);//紀錄user們使用的椅子
        for(int i=0;i<events.size();i++){
            int time=events[i].first;
            int friendIndex=events[i].second.first;
            bool isArriving=events[i].second.second;
            if(isArriving){
                int chair=availableChair.top();
                availableChair.pop();
                occupiedChair[friendIndex]=chair;
                if(friendIndex==targetFriend){
                    return chair;
                }
            }
            else{
                availableChair.push(occupiedChair[friendIndex]);
            }
        }
        return 100;
    }
};