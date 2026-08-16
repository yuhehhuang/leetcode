class Solution {
public:
    int kthDigit(long long k) {
        long long tmp=k;
        if(tmp<=9) return tmp;
        tmp-=9;
        long long d=2;
        long long count =9;
        long long b_start=1;
        while(tmp>count*(10*d)){
            tmp-=count*(10*d);
            count*=10;
            b_start*=10;
            d++;
        }
        long long block_len =10*d; //一個block(10個整數)的長度
        long long b= b_start+(tmp-1)/block_len;//b表示目標在哪個block
        long long idx =(tmp-1)%block_len;
        string s="";
        for(int i=0;i<10;++i){
            s+=to_string(10*b+i);
        }
        if(b%2!=0){
            s="";
            for(int i=9;i>=0;--i){
                s+=to_string(10*b+i);
            }
        }
        return s[idx]-'0';
    }
};