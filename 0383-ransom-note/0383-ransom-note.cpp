class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int m=ransomNote.size();
        int n=magazine.size();
         unordered_map<char,int> map;
         for(int i=0;i<m;i++){
             map[ransomNote[i]]++;
         }
         for(int i=0;i<n;i++){
             map[magazine[i]]--;
         }
         for(int i=0;i<map.size();i++){
             if(map[i]>0){
                 return false;
             }
         }
         return true;
        
    }
};