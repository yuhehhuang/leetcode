class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //紅藍分配，紅色表示無法在h小時內吃完全部的吃速，藍色表示可以h小時內吃完全部的吃速
        int left=1;
        int right = *max_element(piles.begin(), piles.end());
        while(left<=right){
            int mid=left+(right-left)/2;
            long long cnt=0;
            for(int i=0;i<piles.size();++i){
                cnt+=(piles[i]/mid);//cnt=吃完全部香蕉的時間
                if(piles[i]%mid>0){
                    cnt+=1;
                }
            }
            if(cnt>h){
                //無法滿足h小時內吃完
                //更新紅色
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return right+1;
    }
};