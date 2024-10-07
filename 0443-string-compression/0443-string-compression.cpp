class Solution {
public:
    int compress(vector<char>& chars) {
        //指針指向下一個要write/read的元素
        int write_pointer=0;
        int check_pointer=0;
        while(check_pointer<chars.size()){
            char currentChar=chars[check_pointer];
            int cnt=0;
            while(check_pointer<chars.size()&&chars[check_pointer]==currentChar){
                check_pointer++;
                cnt++;
            }
            chars[write_pointer]=currentChar;
            write_pointer++;
            if(cnt>1){
                string cntStr=to_string(cnt);
                for(int i=0;i<cntStr.size();i++){
                    chars[write_pointer]=cntStr[i];
                    write_pointer++;
                }
            }
        }
        return write_pointer;
    }
};