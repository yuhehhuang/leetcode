void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
int ptr1=0;
int ptr2=0;
int i=0;
int arr[nums1Size+nums2Size];
while(ptr1!=m && ptr2!=n){
    if(nums1[ptr1]<nums2[ptr2]){
        arr[i]=nums1[ptr1];
        i++;
        ptr1++;
    }
    else{
        arr[i]=nums2[ptr2];
        i++;
        ptr2++;
    }
}
if(ptr1==m){
    while(ptr2!=n){
    arr[i]=nums2[ptr2];
    i++;
    ptr2++;}
}
else{
    while(ptr1!=m){
        arr[i]=nums1[ptr1];
        i++;
        ptr1++;
    }
}
for(int j=0;j<m+n;j++){
    nums1[j]=arr[j];
}
}