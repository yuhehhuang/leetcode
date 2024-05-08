class compare{
    public:
    bool operator()(int a,int b){
        return a>b;
    }
};
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int,string>map;
        vector<int>copy=score;
        vector<string> ans(score.size());
        if(score.size()==1){
            ans[0]="Gold Medal";
            return ans;
        }
        if(score.size()==2){
            if(score[0]>score[1]){
                ans[0]="Gold Medal";
                ans[1]="Silver Medal";
                return ans;
            }
            else{
                ans[0]="Silver Medal";
                ans[1]="Gold Medal";
                return ans;
            }
        }
        sort(copy.begin(),copy.end(),compare());
        map.insert(pair<int,string>(copy[0],"Gold Medal"));
        map.insert(pair<int,string>(copy[1],"Silver Medal"));
        map.insert(pair<int,string>(copy[2],"Bronze Medal"));
        if(score.size()>3){
        for(int i=3;i<copy.size();i++){
            map.insert(pair<int,string>(copy[i],to_string(i+1)));
        }
                          }
        for(int i=0;i<score.size();i++){
            ans[i]=map[score[i]];
        }  
        return ans;
    }
};