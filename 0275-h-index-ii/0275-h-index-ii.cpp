class Solution {
public:
    int hIndex(vector<int>& citations) {
        //有k篇paper至少被cite k次
        //return max k
        int cnt=0;
        for(int i=citations.size()-1;i>=0;--i){
            if(citations[i]>cnt){
                cnt++;
            }
            else{
                break;
            }
        }
        return cnt;
    }
};