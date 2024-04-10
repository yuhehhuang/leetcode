class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> ans(deck.size());
        sort(deck.begin(),deck.end());
        queue<int>que; //用來放index
        for(int i=0;i<deck.size();i++){
            que.push(i);
        }
        for(int i=0;i<deck.size();i++){
            ans[que.front()]=deck[i];
            que.pop();
            que.push(que.front());
            que.pop();
        }
        return ans;
    }
};