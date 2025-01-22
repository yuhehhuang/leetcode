class Solution {
public:
    void helper(vector<int>&nums1,vector<int>&nums2,int& ans){
        long long target,s;
        sort(nums2.begin(),nums2.end());
        for(int i=0;i<nums1.size();++i){
            target=(long long)nums1[i]*(long long)nums1[i];
            int j=0;
            int k=nums2.size()-1;
            while(j<k){
                s=(long long)nums2[j]*(long long)nums2[k];
                if(s<target){
                    j++;
                }
                else if(s>target){
                    k--;
                }
                else{
                    if(nums2[j]==nums2[k]){
                        ans+=(k-j+1)*(k-j)/2;
                        break;
                    }
                    else{
                        int t1=0,t2=0;
                        int l=nums2[j],r=nums2[k];
                        while(l==nums2[j]){
                            t1++;
                            j++;
                        }
                        while(r==nums2[k]){
                            t2++;
                            k--;
                        }
                        ans+=t1*t2;
                    }
                }
            }
        }
    }
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        //
        int ans=0;
        helper(nums1,nums2,ans);
        helper(nums2,nums1,ans);
        return ans;
    }
};