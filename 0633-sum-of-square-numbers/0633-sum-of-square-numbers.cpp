class Solution {
public:
    bool judgeSquareSum(int c) {
        //可能就是[0,m]選兩個有機會滿足a^2+b^2=c;
        int m=floor(sqrt(c));
        long long  left=0;
        long long right=m;
        while(left<=right){
            if(left*left+right*right==c){
                return true;
            }
            else if(left*left+right*right>c){
                right--;
            }
            else{
                left++;
            }
        }
        return false;
    }
};