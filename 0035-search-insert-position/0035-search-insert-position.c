int searchInsert(int* nums, int numsSize, int target){
int min=0;
int max=numsSize-1; 
int mid;
while(min<=max){
    mid=(min+max)/2;
    if(nums[mid]==target){
    return mid;
    }
    else if (nums[mid]>target){
        max=mid-1;
    }
    else min=mid+1;
}
return min;

}