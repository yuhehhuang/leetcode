// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int left=1;//left以左都是good
    int right=n;//right以右都是bad
    while(left<=right){
        int mid = (right-left)/2+ left;
        if(isBadVersion(mid)){
            right= mid-1;
        }
        else{
            left = mid+1;
        }
    }
    return right+1;
}