int reverseBits(int n) {
    unsigned int ans=0;
    for(int i=0;i<31;++i){
        ans |= (n & 1);
        ans <<= 1;
        n >>=1;
    }
    ans |=(n & 1);
    return (int)ans;
}