bool Mycompare(int a,int b){
    string str_a=to_string(a);
    string str_b=to_string(b);
    int tmp=min(str_a.size(),str_b.size());
    int i=0;
    while(i!=tmp){
        if(str_a[i]<str_b[i]){
            return true;
        }
        else if(str_a[i]>str_b[i]){
            return false;
        }
        else{
            i++;
        }
    }
    if(str_a.size()==tmp){
        return true;
    }
    else{
        return false;
    }
    return 0 ;
}
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i=1;i<=n;i++){
            ans.push_back(i);
        }
        sort(ans.begin(),ans.end(),Mycompare);
        return ans;
    }
};