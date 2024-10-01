class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        //i+(k-i)%k=0(mod k)
        unordered_map<int,int>map;
        for(int i=0;i<arr.size();i++){
            map[(arr[i]%k+k)%k]++;
        }
        for(int i=0;i<k;i++){
            if(i==0){
                if(map[i]%2!=0){
                    return false;
                }
                continue;
            }
            if(map[i]!=map[k-i]){
                return false;
            }
        }
        return true;
    }
};