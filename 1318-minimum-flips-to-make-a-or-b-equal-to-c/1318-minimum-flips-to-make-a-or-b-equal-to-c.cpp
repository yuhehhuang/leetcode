class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        while(a>0||b>0||c>0){
            int check1=a&1;
            a=a>>1;
            int check2=b&1;
            b=b>>1;
            int check3=c&1;
            c=c>>1;
            if(check1==0&&check2==0&&check3==1){
                ans++;
            }
            else if(check3==0&&((check1==0&&check2==1)||(check1==1&&check2==0))){
                ans++;
            }
            else if(check3==0&&check1==1&&check2==1){
                ans+=2;
            }
        }
        return ans;
    }
};