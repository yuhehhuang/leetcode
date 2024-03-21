class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
    vector<string> result;
    int hash[26]={0};
    if(A.size()==0) return result;
    for(int i=0;i<A[0].size();i++){
        hash[A[0][i]-'a']++;
    } 
    int hashOtherStr[26]={0};
    for(int i=1;i<A.size();i++){
        memset(hashOtherStr,0,26*sizeof(int));
        for(int j=0;j<A[i].size();j++){
            hashOtherStr[A[i][j]-'a']++;
        }
        for(int k=0;k<26;k++){
            hash[k]=min(hash[k],hashOtherStr[k]);
        }
    }
    for(int i=0;i<26;i++){
        while(hash[i]!=0){
            //string (size_t n, char c);
            string s(1, i + 'a'); 
            result.push_back(s);
            hash[i]--;

        }
    }
    return result;

        
    }
};