class Solution {
public:
    static bool cmp(int a,int b){
        return a>b;
    }
    int hIndex(vector<int>& citations) {
        int h_index=0;
        sort(citations.begin(),citations.end(),cmp);
        for(int i=0;i<citations.size();++i){
            if(citations[i]>=h_index+1){
                h_index++;
            }
            else{
                break;
            }
        }
        return h_index;
    }
};