class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int>new_arr;
        for(int i=0;i<arr.size();++i){
            new_arr.push_back(arr[i]);
            if(arr[i]==0){
                new_arr.push_back(0);
            }
        }
        for(int i=0;i<arr.size();++i){
            arr[i]=new_arr[i];
        }
        return ;
    }
};