class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<nums2.size();i++){
            mp2[nums2[i]]++;
        }
        for(int i=0;i<nums1.size();i++){
            if(mp2.find(nums1[i])!=NULL){
                cnt1++;
            }
        }
        ans.push_back(cnt1);
        for(int i=0;i<nums1.size();i++){
            mp1[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            if(mp1.find(nums2[i])!=NULL){
                 cnt2++;
            }
        }
        ans.push_back(cnt2);
        return ans;
    }
};