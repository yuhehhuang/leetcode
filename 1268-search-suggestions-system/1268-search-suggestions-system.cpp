class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>>res;
        for(int i=1;i<=searchWord.size();++i){
            int num=0;//product數
            string word=searchWord.substr(0,i);
            vector<string>oneRes;
            for(int i=0;i<products.size();++i){
                if(num<3){
                    if(products[i].find(word)==0){
                        oneRes.push_back(products[i]);
                        num++;
                    }
                }
                else{
                    break;
                }
            }
            res.push_back(oneRes);
        }
        return res;
    }
};