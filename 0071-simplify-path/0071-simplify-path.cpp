class Solution {
public:
    string simplifyPath(string path) {
     //queue 把/之間的單詞push進去，如果/ / 之間是..就pop一個單詞出來 一個.就部動作
     int i=0,n=path.length();
     stack<string>st;
     string ans;
     for(int i=0;i<n;){
        while(i<n&&path[i]=='/')i++;
        if(i>=n) break;

        string word;
        while(i<n&&path[i]!='/'){
            word+=path[i++];
        }
        if(word=="."||word.empty()){
            continue;
        }
        else if(word==".."){
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            st.push(word);
        }
     }
     if(st.empty()) return "/";
      vector<string>tmp;
      while(!st.empty()){
        tmp.push_back(st.top());
        st.pop(); 
    }
      for(int i=tmp.size()-1;i>=0;i--){
        ans+="/"+tmp[i];
      }
      return ans;
    }
    
};