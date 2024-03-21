/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //關鍵想法:
 //a ^ b             = c  then 
//c ^ (a ^ b)       = c ^ c then     
//c ^ (a ^ b) ^ b   = 0 ^ b then
//(c ^ a) ^ (b ^ b) = b then 
//a ^ c = b
int* findArray(int* pref, int prefSize, int* returnSize){
*returnSize=prefSize;
int *ans=malloc(sizeof(int)*prefSize);
ans[0]=pref[0];
for(int i=1;i<prefSize;i++){
    ans[i]=pref[i]^pref[i-1];
}
return ans;
}