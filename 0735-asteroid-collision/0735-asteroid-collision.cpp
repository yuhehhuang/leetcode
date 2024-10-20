class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        stack<int>st;
        for(int i=0;i<as.size();i++){
            if(as[i]>0||st.empty()){
                st.push(as[i]);
            }
            else{
                while(!st.empty()&&st.top()>0&&st.top()<abs(as[i])){
                    st.pop();
                }
                if(!st.empty()&&st.top()==abs(as[i])){
                    st.pop();
                }
                else{
                    if(st.empty()||st.top()<0){
                        st.push(as[i]);
                    }
                }
            }
        }
        vector<int>res(st.size());
        for(int i=st.size()-1;i>=0;--i){
                res[i]=st.top();
                st.pop();
        }
        return res;
    }
};