int nextsum(int n){
    int sum=0;
    while(n){
        sum+=(n%10)*(n%10);
        n=n/10;
    }
    return sum;
}
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while(1){
            int sum=nextsum(n);
            if(sum==1){
                return 1;
            }
            if(set.find(sum)!=set.end()){ //表示找到sum這個key;
                return false;
            }
            else{
                set.insert(n);
            }
            n=sum;
        }
    }
};