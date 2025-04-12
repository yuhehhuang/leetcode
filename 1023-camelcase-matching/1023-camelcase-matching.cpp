class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int i = 0;
        vector<bool> ans;
        while (i < queries.size()) {
            int j = 0, k = 0;
            bool upperFound=false;
            while (j != queries[i].length() && k != pattern.length()) {
                if (queries[i][j] == pattern[k]) {
                    k++;
                }
                else if(queries[i][j] >= 'A' && queries[i][j] <= 'Z'){
                    upperFound=true;
                    break;
                }
                j++;
            }

            if (k == pattern.length()) {
                for (; j < queries[i].length(); ++j) {
                    if (queries[i][j] >= 'A' && queries[i][j] <= 'Z') {
                        ans.push_back(false);
                        upperFound = true;
                        break;
                    }
                }
                if (!upperFound) ans.push_back(true);
            } else {
                ans.push_back(false);
            }
            i++;
        }
        return ans;
    }
};