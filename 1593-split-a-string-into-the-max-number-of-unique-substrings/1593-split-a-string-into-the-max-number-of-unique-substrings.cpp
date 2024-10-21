class Solution {
public:
    int backtrack(int start, string& s, unordered_set<string>& seen) {
        if (start == s.size()) {
            return 0;  // 到達字串結尾，這是一條有效的分割路徑
        }
        int maxSplit = -1;  // 初始化為 -1，表示如果後續無法分割，則此路徑無效
        for (int end = start + 1; end <= s.size(); ++end) {
            string substring = s.substr(start, end - start);
            if (seen.find(substring) == seen.end()) {  // 沒有重複的子字串
                seen.insert(substring);  // 標記該子字串已使用
                int nextSplit = backtrack(end, s, seen);
                if (nextSplit != -1) {  // 只有當後續分割成功時才累加
                    maxSplit = max(maxSplit, 1 + nextSplit);
                }
                seen.erase(substring);  // 回溯，移除當前的子字串
            }
        }
        return maxSplit;  // 返回最大分割數量
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return backtrack(0, s, seen);
    }
};