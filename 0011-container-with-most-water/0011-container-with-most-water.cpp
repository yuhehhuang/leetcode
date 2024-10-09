class Solution {
public:
    int maxArea(vector<int>& height) {
        //area=(index j-index i)*min(height[i],height[j]);
        int ans=INT_MIN;
        int i=0;
        int j=height.size()-1;
        while(i<j){
            ans=max(min(height[i],height[j])*(j-i),ans);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};