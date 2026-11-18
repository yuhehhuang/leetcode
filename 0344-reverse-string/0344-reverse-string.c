void swap(char*s1,char*s2){
    *s1=*s1^*s2;
    *s2=*s1^*s2;
    *s1=*s1^*s2;
    return ;
}
void reverseString(char* s, int sSize) {
    for(int i=0;i<sSize/2;++i){
        swap((s+i),(s+sSize-1-i));
    }
    return ;
}