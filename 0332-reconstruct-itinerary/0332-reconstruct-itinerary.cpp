class Solution {
public:
unordered_map<string, map<string, int>> targets;
bool backtracking(int ticketNum, vector<string>& result){
    if(result.size()==ticketNum+1){
        return true;
    }
    //因為我用map<string,int>所以for()的search 順序已經照字母小排到大
    for(pair<const string,int>&target:targets[result[result.size()-1]]){
        if(target.second>0){
            result.push_back(target.first);
            target.second--;
            if(backtracking(ticketNum,result)) return true;
            result.pop_back();
            target.second++;
        }
    }
    return false;
}
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string>result;
        for(const vector<string>&vec:tickets){
            //targets[vec[0]]是targets[vec[0]]的value
            //targets[vec[0]]的value是map資料型態
            //targets[vec[0]][vec[1]]是此map的value
            targets[vec[0]][vec[1]]++;
        }
        result.push_back("JFK");
        backtracking(tickets.size(),result);
        return result;
    }
};