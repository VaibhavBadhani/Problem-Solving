class TrieNode{
    public:
    TrieNode* child[26];
    bool isend;
    TrieNode(){
        for(auto& itr: child){
            itr = NULL;
        }
        isend= false;
    }
};
class Solution {
public:
    TrieNode* root;
    void insert(string word){
        int n = word.size();
        TrieNode* top = root;
        for(int i =0;i<n;i++){
            if(top->child[word[i]-'a']==NULL){
                top->child[word[i]-'a']=new TrieNode();
            }
            top = top->child[word[i]-'a'];
        }
        top->isend = true; 
    }
    string search(string s){
        TrieNode* top = root;
        string ans;
        for(int i =0;i<s.length();i++){
            if(top->child[s[i]-'a']==NULL) break;
            ans+=s[i];
            top = top->child[s[i]-'a'];
            if(top->isend==true) return ans;
        }
        return s;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new TrieNode();
        for(auto& word:dictionary){
            insert(word);
        }
        string ans = "";
        string w ="";
        istringstream s(sentence);
        for(;s>>w;){
            ans+=search(w);
            ans+=' ';
        }
        ans.pop_back();
        return ans;
    }
};