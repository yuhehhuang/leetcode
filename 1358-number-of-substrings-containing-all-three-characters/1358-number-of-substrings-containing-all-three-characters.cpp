class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt[3]{}; // 0 對應 'a'，1 對應 'b'，2 對應 'c'
        int right = 0;
        int ans = 0;

        // 枚舉每個左指標
        for (int left = 0; left < s.length(); ++left) {
            if (left > 0) {
                // 左指標右移，減少對應字元的計數
                cnt[s[left - 1] - 'a']--;
            }

            // 右指標向右移動，直到找到包含 'a'、'b'、'c' 的子串
            while (right < s.length() && (cnt[0] < 1 || cnt[1] < 1 || cnt[2] < 1)) {
                cnt[s[right] - 'a']++;
                right++;
            }

            // 若 right 已移動到字串末尾，可能不再有滿足條件的子串
            if (cnt[0] >= 1 && cnt[1] >= 1 && cnt[2] >= 1) {
                ans += s.length() - right + 1; // 加上所有以 left 開頭的有效子串數量
            }
        }
        return ans;
    }
};