class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans=1;
        if(arr.size()<=1){
            return 1;
        }
        for(int i=0;i<arr.size()-1;++i){
            int diff=arr[i+1]-arr[i];
            bool flip=diff>0?true:false;
            int cnt=2;
            int p=i;
            while(p<arr.size()-2&&((flip&&arr[p+2]-arr[p+1]<0)||(!flip&&arr[p+2]-arr[p+1]>0))){
                cnt++;
                p++;
                flip=!flip;
            }
            if(diff==0){
                cnt=1;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};