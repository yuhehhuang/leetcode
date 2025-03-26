class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans=0;
        //arr1的每個element去找arr2內最接近的來判斷
        sort(arr2.begin(),arr2.end());
        for(int i=0;i<arr1.size();++i){
            int left=0;
            int right=arr2.size()-1;
            while(left<=right){
                int tmp=(left+right)/2;
                if(arr2[tmp]>arr1[i]){
                    //right以右都比arr1[i]大
                    right=tmp-1;
                }
                else{
                    //left以左都比arr1[i]小
                    left=tmp+1;
                }
            }
            bool valid = true;
            if (right >= 0 && abs(arr1[i] - arr2[right]) <= d) valid = false; // 最近左側比 arr1[i] 小
            if (left < arr2.size() && abs(arr1[i] - arr2[left]) <= d) valid = false; // 最近右側比 arr1[i] 大
            
            if (valid) ans++;
        }
        return ans;
    }
};