class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int tmp=x;
        int long sum=0;
        while(tmp){
            sum=sum*10+tmp%10;
            tmp/=10;
        }
        if(sum==x){
            return true;
        }
        return false;
    }
};