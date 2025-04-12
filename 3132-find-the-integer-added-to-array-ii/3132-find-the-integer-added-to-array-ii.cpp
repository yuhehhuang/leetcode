class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for(int i=2;i>0;--i){
            int x=nums2[0]-nums1[i];
            int j=0;
            for(int k=i;k<nums1.size();++k){
                if(nums2[j]==nums1[k]+x){
                    j++;
                    if(j==nums2.size()){
                        return x;
                    }
                }
            }
        }
        return nums2[0]-nums1[0];
    }
};