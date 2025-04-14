class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ranges::sort(nums);
        long long ans = 0;
        int l = nums.size(), r = l;
        for (int j = 0; j < nums.size(); j++) {
            while (r && nums[r - 1] > upper - nums[j]) {
                r--;
            }
            while (l && nums[l - 1] >= lower - nums[j]) {
                l--;
            }
            // 在方法一中，二分的结果必须 <= j，方法二同理
            ans += min(r, j) - min(l, j);
        }
        return ans;
    }
};