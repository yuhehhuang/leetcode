class Solution {
public:
    bool canTransform(string start, string result) {
        string s=start,r=result;
        s.erase(remove(s.begin(),s.end(),'X'),s.end());
        r.erase(remove(r.begin(),r.end(),'X'),r.end());
        if(s!=r){
            return false;
        }
        for(int i=0,j=0;i<start.size();++i){
            if(start[i]=='X'){
                continue;
            }
            while(result[j]=='X'){
                j++;
            }
            if(result[j]=='L'&&i<j){
                return false;
            }
            if(result[j]=='R'&&i>j){
                return false;
            }
            j++;
        }
        return true;
    }
};