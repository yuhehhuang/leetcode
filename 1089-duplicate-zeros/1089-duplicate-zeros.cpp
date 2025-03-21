class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        //先計算有幾個zero
        int zero=0;
        for(int i=0;i<arr.size();++i){
            if(arr[i]==0){
                zero++;
            }
        }
        //
        int j=arr.size()+zero-1;
        for(int i=arr.size()-1;i>=0;--i){
            if(j<arr.size()){
                arr[j]=arr[i];
            }
            if(arr[i]==0){
                j--;
                if(j<arr.size()){
                    arr[j]=0;
                }
            }
            j--;
        }
        return ;
    }
};