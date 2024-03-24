class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int q=0;
        int j=0;
        for(int i=2;i<nums.size();i++){
            if(arr1[q]>arr2[j]){
                arr1.push_back(nums[i]);
                q++;
            }
            else{
                arr2.push_back(nums[i]);
                j++;
            }
        }
        for(int i=0;i<arr2.size();i++){
            arr1.push_back(arr2[i]);
        }
        return arr1;
    }
};