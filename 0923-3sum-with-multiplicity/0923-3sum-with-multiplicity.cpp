class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int mod=1e9+7;
        int res=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-2;i++){
            int subsum=target-arr[i];
            int j=i+1;
            int k=arr.size()-1;
            while(j<k){
                if(arr[j]+arr[k]>subsum){
                    k--;
                }
                else if(arr[j]+arr[k]<subsum){
                    j++;
                }
                else{
                    if(arr[j]!=arr[k]){
                        int leftcnt=1;
                        while(j<k&&arr[j]==arr[j+1]){
                            j++;
                            leftcnt++;
                        }
                        int rightcnt=1;
                        while(j<k&&arr[k-1]==arr[k]){
                            k--;
                            rightcnt++;
                        }
                        res+=(rightcnt*leftcnt)%mod;
                        j++;
                        k--;
                    }
                    else{
                        res+=((k-j+1)*(k-j)/2)%mod;
                        break;
                    }
                }
            }
        }
        return res%mod;
    }
};