class Solution {
public:
    int maximumSwap(int num) {
        //計算每個index開始到終點最大的value的index
        //從左遍歷遇到第一個位置上value不是此index到終點的最大的，把他跟最大的做交換
        string numSt=to_string(num);
        int n=numSt.length();
        vector<int>record(n,-1);
        int curMaxPos=n-1;
        for(int i=n-1;i>=0;--i){
            if(numSt[i]>numSt[curMaxPos]){
                curMaxPos=i;
            }
            record[i]=curMaxPos;
        }
        for(int i=0;i<n;++i){
            if(numSt[record[i]]!=numSt[i]){
                swap(numSt[i],numSt[record[i]]);
                break;
            }
        }
        return stoi(numSt);
    }
};