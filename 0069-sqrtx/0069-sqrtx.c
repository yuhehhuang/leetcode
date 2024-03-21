int mySqrt(int x){
//binary search
long long low=0;
long long high=x;
int ans;
while(low<=high){
   long long mid=(low+high)/2; 
    if(mid*mid==x){
        return mid;
    }
    else if(mid*mid>x){
        high=mid-1;
    }
    else{
        low=mid+1;
        ans=mid;
    }

}
    return ans;
}