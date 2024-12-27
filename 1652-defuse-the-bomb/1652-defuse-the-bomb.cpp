class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int>ans(n);
        if(k==0){
            return ans;
        }
        bool check =k>0?1:0;
        if(check){
            int tmp=0;
            for(int i=1;i<1+k;++i){
                tmp+=code[i%n];
            }
            ans[0]=tmp;
            for(int i=2;i<2+n;++i){
                tmp+=code[(i+k-1)%n]-code[(i-1)%n];
                ans[(i-1)%n]=tmp;
            }
        }
        else{
            int tmp=0;
            int tk=abs(k);
            for(int i=n-tk;i<n;++i){
                tmp+=code[(i+n)%n];
            }
            ans[0]=tmp;
            for(int i=n-tk+1;i<2*n-tk+1;++i){
                tmp+=code[(i+tk-1)%n]-code[(i-1)%n];
                ans[(i+tk+n)%n]=tmp;
            }
        }
        return ans;
    }
};