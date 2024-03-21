class Solution {
    class Myqueue{
        public:
          deque<int> que;
          void pop(int value){
              if(!que.empty()&&value==que.front()){ //push可能會先幫我把原本要清除的清掉
                  que.pop_front();
              }
          }
          void push(int value){ //我的push會自動把比我小的值移除
              while(!que.empty()&&value>que.back()){
                  que.pop_back();
              }
              que.push_back(value);
          }
          int front(){ //代表此window的最大值
              return que.front();
          }

    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Myqueue que;
        vector<int> result;
        for(int i=0;i<k;i++){
            que.push(nums[i]);
        }
        result.push_back(que.front());
        for(int i=k;i<nums.size();i++){
            que.pop(nums[i-k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
            return result;
    }
};