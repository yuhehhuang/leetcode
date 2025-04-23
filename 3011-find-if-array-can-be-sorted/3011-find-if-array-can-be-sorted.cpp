class Solution {
public:
    int set_bits(int a) {
        int ans = 0;
        while (a) {
            ans += (a & 1);
            a >>= 1;
        }
        return ans;
    }
     bool canSortArray(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            int start = i;
            // 找到這段相同 set_bits 的區間
            while (i + 1 < nums.size() && set_bits(nums[i]) == set_bits(nums[i + 1])) {
                i++;
            }
            // 排序這段（包含 i）
            sort(nums.begin() + start, nums.begin() + i + 1);
            i++;  // 下一段開頭
        }

        // 檢查整體是否為遞減排序
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) return false;
        }
        return true;
    }
};