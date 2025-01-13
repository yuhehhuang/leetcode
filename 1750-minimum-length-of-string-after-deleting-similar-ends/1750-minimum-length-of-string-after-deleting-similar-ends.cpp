class Solution {
public:
    int minimumLength(string s) {
        int left=0;
        int right=s.length()-1;
        while(left<right){
            if(s[left]==s[right]){
                char ch=s[left];
                while(s[left]==ch&&left<right){
                    left++;
                }
                if(left==right){
                    return 0;
                }
                while(s[right]==ch&&left<right){
                    right--;
                }
            }
            else{
                break;
            }
        }
        return right-left+1;
    }
};