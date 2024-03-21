class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> hashtable;
        set<int>ans;
        for(int i=0;i<arr.size();i++){
            hashtable[arr[i]]++;
        }
        for(auto i=hashtable.begin();i!=hashtable.end();i++){
            ans.insert(i->second); //因為set插入同個值不會重複 EX inset(1),insert(2),insert(2) 結果set裡是1 2
        }
        if(ans.size()==hashtable.size())
        return true;
        return false;
    }
};