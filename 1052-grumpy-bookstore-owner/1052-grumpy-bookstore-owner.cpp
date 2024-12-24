class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        //
        int ans=0;
        for(int i=0;i<minutes;++i){
            ans+=customers[i];
        }
        for(int i=minutes;i<customers.size();++i){
            if(grumpy[i]==0){
                ans+=customers[i];
            }
        }
        int max_ans=ans;
        for(int i=minutes;i<customers.size();++i){
            if(grumpy[i]==1){//代表上一輪沒加到
                ans+=customers[i];
            }
            if(grumpy[i-minutes]==1){
                ans-=customers[i-minutes];
            }
            max_ans=max(ans,max_ans);
        }
        return max_ans;
    }
};