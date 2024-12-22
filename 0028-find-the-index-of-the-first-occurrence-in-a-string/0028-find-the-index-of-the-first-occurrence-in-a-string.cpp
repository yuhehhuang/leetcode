class Solution {
public:
    int strStr(string haystack, string needle) {
        int needleLength=needle.length();
        if(needleLength==0)return 0;
        int* next = new int[needleLength](); 
        //left:longest prefix的後一個元素(longest prefix的len)，right:longest suffix的後一個元素
        for(int right=1,left=0;right<needle.size();++right){
            while(left>0&&needle[left]!=needle[right]){
                left=next[left-1];
            }
            if(needle[left]==needle[right]){
                left++;
            }
            next[right]=left;
        }
        for(int i=0,j=0;i<haystack.length();++i){
            while(j>0&&haystack[i]!=needle[j]){
                j=next[j-1];//j>0是為了避免[j-1] overflow，
                //j代表遇到不一樣的時候 needle要用哪個index的字來跟現在的i比
            }
            if(haystack[i]==needle[j]){
                j++;
            }
            if(j==needleLength){
                return i-needleLength+1;
            }
        }
        return -1;
    }
};