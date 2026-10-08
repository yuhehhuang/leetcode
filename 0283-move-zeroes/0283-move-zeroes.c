
void moveZeroes(int* nums, int numsSize) {
    //每遇到一個!=0的element把他排到前面(用slow表示插入的index位置)
    int slow=0;//最一開始能插入的位置
    for(int i=0;i<numsSize;++i){
        if(nums[i]!=0){
            nums[slow++]=nums[i];
        }
    }
    //最後slow指向的位置是尚未完成插入的地方，表示這位置以後都是0
    for(slow;slow<numsSize;++slow){
        nums[slow]=0;
    }
    return;
}