class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        //非嚴格遞增
        //找比target大,且最接近targets
        int left=0;
        int right=letters.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(letters[mid]<=target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return left==letters.size()?letters[0]:letters[left];
    }
};