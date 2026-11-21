int myAtoi(char* s) {
    if(s==NULL)return 0;
    int ans = 0;
    int sign =1;
    int sign_cnt=1;
    bool read_on=false;
    while(*s!='\0'){
        if(*s>='0'&&*s<='9'){
            if(read_on==false){
                //確認已經有數字進來,之後不會再收+-符
                read_on=true;
            }
            int digit = *s - '0';
            if(ans >INT_MAX/10||(ans==INT_MAX/10&&digit>INT_MAX%10)){
                return (sign==1)?INT_MAX:INT_MIN;
            }
            ans = 10* ans + digit;
            s++;
        }
        else if(*s==' '&&!read_on){
            s++;
        }
        else if((*s=='-'||*s=='+')&&sign_cnt==1&&!read_on){
            read_on =true;
            if(*s=='-'){
                sign=-1;
                sign_cnt--;
            }
            *s++;
        }
        else{
            break;
        }
    }
    return sign*ans;
}