class TrieNode {
    public:
       TrieNode* childs[26];
       bool isend ;
       TrieNode(){
          isend= false;
          for(auto& itr:childs){
            itr= NULL;
          }
       }
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *top = root;
        for(auto it:word){
            int x = it-'a';
            if(top->childs[x]==NULL){
                top->childs[x]= new TrieNode();
            }
            top = top->childs[x];
        }
        top->isend = true;
    }
    
    bool search(string word) {
        TrieNode* top = root;
        for(auto it:word){
            int x = it-'a';
            if(top->childs[x]==NULL){
                return false;
            }
            top=top->childs[x];
        }
        return top->isend;
    }
    
    bool startsWith(string prefix) {
        TrieNode* top = root;
        for(auto& it:prefix){
            int x = it-'a';
            if(top->childs[x]==NULL){
                return false;
            }
            top = top->childs[x];
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