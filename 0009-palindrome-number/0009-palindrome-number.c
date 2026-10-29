bool isPalindrome(int x) {
    if(x<0){
        return false;
    }
    int tmp=x;
    long long cmp=0;
    while(tmp){
        cmp=10*cmp+tmp%10;
        tmp/=10;
    }
    return (cmp==x)?true:false;
}