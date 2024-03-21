class Solution {
public:
    int hammingWeight(uint32_t n) {
      int cnt=0;
      int b;
        for(int i=0;i<32;i++){
          b=n%2;
          n/=2;
          if(b==1){
            cnt++;
          }
        }
     return cnt;
    }

};