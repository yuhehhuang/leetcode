class Solution {
public:
    string reverseWords(string s) {
        vector<string>vec;
        for(int i=0;i<s.size();++i){
            if(s[i]!=' '){
                string tmp;
                for(i;i<s.size();++i){
                    if(s[i]!=' '){
                        tmp+=s[i];
                    }
                    else{
                        break;
                    }
                }
            vec.push_back(tmp);
            }
        }
        int left=0,right=vec.size()-1;
        while(left<right){
            string tmp =vec[left];
            vec[left]=vec[right];
            vec[right]=tmp;
            left++;
            right--;
        }
        string ans;
        for(int i=0;i<vec.size();++i){
            ans+=vec[i];
            if(i!=vec.size()-1)ans+=' ';
        }
        return ans;
    }
};