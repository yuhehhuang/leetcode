int singleNumber(int* nums, int numsSize){
  //XOR of zero and some bit returns that bit i.e. x^0 = x... hence we define a 初始值unique=0;
  //XOR of two same bits returns 0 i.e. x^x = 0...  
  //And, x^y^x = (x^x)^y = 0^y = y...   that is: due to 交換律 過程是多少無所謂 乘到最後相同的會變0 0^y=y;
  int  uniqnum=0;
  for(int i=0;i<numsSize;i++){
      uniqnum=uniqnum ^ nums[i];
  }
  return uniqnum;
}