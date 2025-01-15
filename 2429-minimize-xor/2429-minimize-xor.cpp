class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int x=0;
        int cnt=0;
        int pow=1;
        while (num2) {
            cnt += (num2 & 1);
            num2 >>= 1;
        }
        //ans=把num1高位元的1的位置放1 
        //若還有cnt就從底部遇到0的地方放1
        for(int i=31;i>=0&&cnt;i--){
            if((num1)&(1<<i)){
                x=(x|(1<<i));
                cnt--;
            }
        }
        for(int i=0;i<32&&cnt;++i){
            if(!((x)&(1<<i))){
                x=(x|(1<<i));
                cnt--;
            }
        }
        return  x;
    }
};