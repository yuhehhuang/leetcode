double findMaxAverage(int* nums, int numsSize, int k){
    int sum=0;
    double ans;
    int index;
    for( index=0;index<k;index++){
        sum=sum+nums[index];
    }
    ans=sum;
    for(index=k;index<numsSize;index++){
        sum=sum+nums[index]-nums[index-k];
        ans=(ans<sum)?sum:ans;
    }
    return ans/k;
}