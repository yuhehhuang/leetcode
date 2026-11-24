bool isPalindrome(char* s) {
    if(s==NULL)return true;
    int len = strlen(s);
    int index=0;
    char *c = (char*)malloc(sizeof(char)*len+1);
    for(int i=0;i<len;++i){
        if(*s>='a'&&*s<='z'){
            c[index++]=*s;
        }
        else if(*s>='A'&&*s<='Z'){
            c[index++]= (char)(*s+32);
        }
        else if(*s>='0'&&*s<='9'){
            c[index++] =*s;
        }
        s++;
    }
    c[index]= '\0';
    int left=0;
    int right = index-1;
    while(left<=right){
        if(c[left++]!=c[right--]){
            return false;
        }
    }
    free(c);
    return true;
}