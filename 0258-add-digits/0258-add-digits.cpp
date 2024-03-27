class Solution {
public:
    int magic(int &num){
        int ans=0;
        while(num!=0){
            ans+=num%10;
            num/=10;
        }
        return ans; 
    }
    int addDigits(int num) {
        int ans=magic(num);
        while(1){
            if (ans>9){
                ans=magic(ans);
            }
            else{return ans;
            }
        }

    }
};