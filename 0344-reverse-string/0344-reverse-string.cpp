class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char>::iterator left=s.begin();
        vector<char>::iterator right=s.end()-1;
        char tmp;
        while(left<right){
            tmp=*left;
            *left=*right;
            *right=tmp;
            left++;
            right--;
        }
    }
};