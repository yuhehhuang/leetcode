class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //每一個當作高 找長度
        //長度= 目前的index中 找左邊第一個高度比此index小 右邊第一個高度比index小的 -->長度=right-left+1-2(-2因為這兩格高度小的不能算)
        int result=0;
        stack<int>st;
        heights.insert(heights.begin(),0);
        heights.push_back(0);
        st.push(0);
        for(int i=1;i<heights.size();i++){
            if(heights[i]>heights[st.top()]){
                st.push(i);
            }
            else if(heights[i]==heights[st.top()]){
                st.push(i);
            }
            else{
                while(heights[i]<heights[st.top()]){
                    int mid=st.top();
                    st.pop();
                    if(!st.empty()){
                        int left=st.top();
                        int right=i;
                        int w=right-left-1;
                        int h=heights[mid];
                        result=max(result,h*w);
                    }
                }
                st.push(i);
            }
        }
        return result;
    }
};