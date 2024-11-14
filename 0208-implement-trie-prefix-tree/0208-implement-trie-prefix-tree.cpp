class Trie {
private:
    bool isEnd;
    Trie* next[26];
public:
    Trie() {
        isEnd=false;
        memset(next,0,sizeof(next));
    }
    
    void insert(string word) {
        Trie* node=this;
        for(int i=0;i<word.size();++i){
            if(node->next[word[i]-'a']==NULL){
                node->next[word[i]-'a']=new Trie();
            }
            node=node->next[word[i]-'a'];
        }
        node->isEnd=true;
    }
    
    bool search(string word) {
        Trie* node=this;
        for(int i=0;i<word.size();++i){
            node=node->next[word[i]-'a'];
            if(node==NULL){
                return false;
            }
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie*node=this;
        for(int i=0;i<prefix.size();++i){
            node=node->next[prefix[i]-'a'];
            if(node==NULL){
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */