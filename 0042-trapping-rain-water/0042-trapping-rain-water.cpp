class Solution {
public:
    int trap(vector<int>& height) {
       stack<int>st;
       int result=0;
       if(height.size()<=2){
        return 0;
       }
       st.push(0);
       for(int i=1;i<height.size();i++){
        if(height[i]<=height[st.top()]){
            st.push(i);
        }
        else{
            while(!st.empty()&&height[i]>height[st.top()]){
                int mid=height[st.top()];
                st.pop();
                if(!st.empty()){
                    int h=min(height[st.top()],height[i])-mid;
                    int w=i-st.top()-1;
                    result+=h*w;
                }
            }
            st.push(i);
        }
       }
       return result;

        
    }
};