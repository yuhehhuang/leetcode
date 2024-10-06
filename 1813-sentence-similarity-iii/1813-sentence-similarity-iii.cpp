class Solution {
public:
    vector<string>convert(string sentence){
        sentence+=" ";
        vector<string>ans;
        string word="";
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]==' '){
                ans.push_back(word);
                word="";
            }
            else{
                word+=sentence[i];
            }
        }
        return ans;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1.size()<sentence2.size()){
            swap(sentence1,sentence2);
        }
        vector<string>vx,vy;
        vx=convert(sentence1);
        vy=convert(sentence2);
        int l=0;
        // common prefix
        for(int i=0;i<vy.size();i++){
            if(vx[i]==vy[i]){
                l++;
            }
            else{
                break;
            }
        }
        int index=vx.size()-1;//長sentence目前指在哪
        int r=vy.size();//紀錄短sentence的common suffix的index
        //common suffix
        for(int i=vy.size()-1;i>=0;i--){
            if(vy[i]==vx[index]){
                index--;
                r=i;
            }
            else{
                break;
            }
        }
        return l>=r;
    }
};