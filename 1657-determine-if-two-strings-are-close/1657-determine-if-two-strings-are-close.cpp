class Solution {
public:
    bool closeStrings(string word1, string word2) {
        //內部字母可以交換位置
        //內部有的字母可以互換(a3b2=>a2b3)
        //只要WORD1 WORD2內字母都一樣不用管字母有幾個只要每個字母有的數字排起來跟另一個WORD排起來依樣
        if(word1.size()!=word2.size()){
            return false;
        }
        unordered_set<int>set1;
        unordered_set<int>set2;
        for(int i=0;i<word1.size();i++){
            set1.insert(word1[i]);
            set2.insert(word2[i]);
        }
        if(set1!=set2){
            return false;
        }
        vector<int>vec1(26,0);
        vector<int>vec2(26,0);
        for(int i=0;i<word1.size();i++){
            vec1[word1[i]-'a']++;
            vec2[word2[i]-'a']++;
        }
        sort(vec1.begin(),vec1.end());
        sort(vec2.begin(),vec2.end());
        if(vec1==vec2){
            return true;
        }
        return false;

    }
};