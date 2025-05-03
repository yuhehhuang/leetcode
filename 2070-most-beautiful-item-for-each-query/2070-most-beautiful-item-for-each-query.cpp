class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<pair<int, int>> query_with_index;
        for (int i = 0; i < queries.size(); ++i) {
            query_with_index.push_back({queries[i], i});
        }
        sort(query_with_index.begin(), query_with_index.end());
        sort(items.begin(),items.end());
        vector<int>ans(queries.size());
        int max_beauty=0,j=0;
        for(int i=0;i<query_with_index.size();++i){
            int q = query_with_index[i].first;
            int idx = query_with_index[i].second;
            while(j<items.size()&&items[j][0]<=q){
                max_beauty=max(max_beauty,items[j][1]);
                j++;
            }
            ans[idx] = max_beauty;  // 放到原本的位置
        }
        return ans;
    }
};