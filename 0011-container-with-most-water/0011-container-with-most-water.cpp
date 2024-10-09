class Solution {
public:
    int maxArea(vector<int>& height) {
        //area=(index j-index i)*min(height[i],height[j]);
        //initial 頭尾算面積
        //思考後 若移動高度高的pointer那這樣算出來的結果一定比原本更慘(上一輪矮的主導算面積或有比上一輪小的主導又長度更短=>都比原本結果差所以不用考慮移動高度高的pointer
        //==>都移動比較矮的才有可能得到更加解(犧牲長度換取最低水平面)
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
