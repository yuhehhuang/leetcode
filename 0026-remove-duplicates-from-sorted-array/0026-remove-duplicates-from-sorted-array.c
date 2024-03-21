int removeDuplicates(int* nums, int numsSize)
{
  int count=1;
  int tmp[numsSize]; 
  tmp[0]=nums[0];  //第一個數字因為inplace所以留著
  for(int i=1;i<numsSize;i++) //從第二個數字開始 每個跟前一項比若值不同表示此值是第一個跟前一項不同的值 把他丟到暫存的tmp array
  if(nums[i-1]!=nums[i]){
      tmp[count]=nums[i];
      count++;
  }
 for(int i=0;i<numsSize;i++)
nums[i]=tmp[i]; //因為他只會比前couint個數字後面都不會管 所以可以這樣做

  return count;
}