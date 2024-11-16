class Solution {
public:
    int trap(vector<int>& h) {
        //st.top():裝水的高度
        //i:st.top()的右壁
        //st.pop()後 st.top()=裝水的高度的左壁
        if(h.size()<=2) return 0;
        stack<int>st;
        st.push(0);
        int result=0;
        for(int i=1;i<h.size();i++){
            if(h[i]<h[st.top()]){
                st.push(i);
            }
            else if(h[i]==h[st.top()]){
                st.push(i);
            }
            else{
                while(!st.empty()&&h[i]>h[st.top()]){
                    int mid=st.top();
                    st.pop();
                    if(!st.empty()){
                    int left=st.top();
                    int right=i;
                    int width=right-left-1;
                    int len=min(h[left],h[right])-h[mid];
                    result+=width*len;
                    }
                }
                st.push(i);
            }
        }
        return result;
    }
};