class cmp{
    public:
    bool operator()(vector<int>& a,vector<int>& b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]>b[0];
    }
};
//身高先排 高到低 若同高度則優先度 小排到大(目的是讓排完後，第i個元素前面的都是比第i個元素大於等於的) 第二個變數在排好身高後 比他前面的那些元素個數只能有ki個 所以再把他往前插入到第k個位置
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>>que;
        sort(people.begin(),people.end(),cmp());
        for(int i=0;i<people.size();i++){
            int position=people[i][1];
            que.insert(que.begin()+position,people[i]);
        }
        return que;
    }
};