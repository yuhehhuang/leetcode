class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>nums3;
        int i=0;
        int j=0;
        while(m&&n){
            if(nums1[i]<=nums2[j]){
                nums3.push_back(nums1[i]);
                i++;
                m--;
            }
            else{
                nums3.push_back(nums2[j]);
                j++;
                n--;
            }
        }
        while(n){
            nums3.push_back(nums2[j]);
            j++;
            n--;
        }
        while(m){
            nums3.push_back(nums1[i]);
            i++;
            m--;
        }
        nums1=nums3;
        return ;
    }
};