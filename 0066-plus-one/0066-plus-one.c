/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
   if(digits[digitsSize - 1] != 9){
    digits[digitsSize - 1]++;
    *returnSize = digitsSize;
}
else{
    digits[digitsSize - 1] = 0;
    for(int i = digitsSize - 2; i >= 0 ;i--){
        if(digits[i] != 9){
            digits[i]++;
            *returnSize = digitsSize;
            break;
        }
        else{
            digits[i] = 0;
        }
    }
    if(digits[0] == 0){
        digits = (int *) calloc(digitsSize + 1, sizeof(int));
        digits[0] = 1;
        *returnSize = digitsSize + 1;
    }
}
return digits;
}