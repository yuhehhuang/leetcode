class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n= matrix[0].size();
        int left=0;
        int right=m*n-1;
        while(left<=right){
            int mid = (right-left)/2+left;
            if(matrix[mid/n][mid%n]<=target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        int check=left-1;
        if(check>=0&&matrix[check/n][check%n]==target){
            return true;
        }
        return false;

    }
};