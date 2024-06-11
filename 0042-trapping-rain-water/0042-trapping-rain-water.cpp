class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<=2) return 0;
        vector<int>Lheight(height.size(),0);
        vector<int>Rheight(height.size(),0);
        Lheight[0]=height[0];
        Rheight[height.size()-1]=height[height.size()-1];
        for(int i=1;i<height.size();i++){
            Lheight[i]=max(Lheight[i-1],height[i]);
        }
        for(int j=height.size()-2;j>=0;j--){
            Rheight[j]=max(Rheight[j+1],height[j]);
        }
        int result=0;
        for(int i=0;i<height.size();i++){
            int count=min(Lheight[i],Rheight[i])-height[i];
            if(count>0){
                result+=count;
            }
        }
        return result;
    }
};