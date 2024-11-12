class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // 檢查 mid 是否為峰值
            bool isLeftSmaller = (mid == 0 || nums[mid] > nums[mid - 1]);
            bool isRightSmaller = (mid == nums.size() - 1 || nums[mid] > nums[mid + 1]);
            
            if (isLeftSmaller && isRightSmaller) {
                return mid; // 找到峰值
            } else if (!isLeftSmaller) {
                // 峰值在左側
                right = mid - 1;
            } else {
                // 峰值在右側
                left = mid + 1;
            }
        }
        
        return -1; // 根據題意，應該總能找到峰值，所以不會到這一步
    }
};