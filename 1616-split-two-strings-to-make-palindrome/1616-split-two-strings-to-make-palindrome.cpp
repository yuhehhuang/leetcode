class Solution {
public:
    bool isPalindrome(string &s,int i,int j){
        while(i<j&&s[i]==s[j]){
            ++i;
            --j;
        }
        return i>=j;
    }
    bool check(string &a,string &b){
        int i=0;
        int j=a.length()-1;
        while(i<j&&a[i]==b[j]){
            ++i;
            --j;
        }
        //i j第一個不對稱的index
        return isPalindrome(a,i,j)||isPalindrome(b,i,j);
    }
    bool checkPalindromeFormation(string a, string b) {
        return check(a,b)||check(b,a);
    }
};