int lengthOfLastWord(char * s){
    int length=strlen(s)-1; //index of last word;
    int result=0;
    while(length>=0&&s[length]==' '){
        length--;
    }
    while(length>=0&&s[length]!=' '){
        length--;
        result++;

    }
    return result;

}