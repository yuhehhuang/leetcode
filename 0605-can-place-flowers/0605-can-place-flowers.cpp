class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt=0;
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]==0&&flowerbed[i-1]==0&&flowerbed[i+1]==0){
                flowerbed[i]=1;
                cnt++;
            }
        }
        if(flowerbed[0]==0&&flowerbed[1]==0){
            cnt++;
        }
        if(flowerbed[flowerbed.size()-1]==0&&flowerbed[flowerbed.size()-2]==0){
            cnt++;
        }
        if(cnt>=n){
            return true;
        }
        return false;
    }
};