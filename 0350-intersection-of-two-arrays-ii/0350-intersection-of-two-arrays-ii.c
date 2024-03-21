/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int hashtable1[1001]={0}; //0~1000有1001個數
    int hashtable2[1001]={0};
     int lessSize = nums1Size < nums2Size ? nums1Size : nums2Size;
    int * result = (int *) calloc(lessSize, sizeof(int)); 
     int set=0;
     for(int i=0;i<nums1Size;i++){
         hashtable1[nums1[i]]++;
     }
         for(int i=0;i<nums2Size;i++){
         hashtable2[nums2[i]]++;
     }
     for(int i=0;i<1001;i++){
         if(hashtable1[i]&&hashtable2[i]){
             int min=hashtable1[i]<hashtable2[i]?hashtable1[i]:hashtable2[i];
             while(min!=0){
                 result[set]=i;
                 set++;
                 min--;
                 
                              }
         }
     }
     *returnSize=set;
     return result;
}