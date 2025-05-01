class RangeFreqQuery {
    unordered_map<int,vector<int>>pos;
public:
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0;i<arr.size();++i){
            pos[arr[i]].push_back(i);
        }
    }
    
    int query(int l, int r, int value) {
        unordered_map<int,vector<int>>::iterator it=pos.find(value);
        if(it==pos.end()){
            return 0;
        }
        vector<int>&a=it->second;

        //在a中找第一個>=l的位置還有第一個<=r的位置
        int left=0;
        int right=a.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(a[mid]>=l){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        int index1=right+1;
        left=0;
        right=a.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(a[mid]<=r){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        int index2=left-1;
        return index2-index1+1;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */