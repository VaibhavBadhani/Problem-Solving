class TrieNode{
public:
    TrieNode* child[26];
    int count;
    TrieNode(){
        for(auto& itr: child){
            itr = NULL;
        }
        count = 0;
    }
};
class Solution {
    TrieNode* root;
public:
    vector<int>ans;
    void insert(string word) {
        TrieNode *top = root;
        for(auto it:word){
            int x = it-'a';
            if(top->child[x]==NULL){
                top->child[x]= new TrieNode();
            }
            top = top->child[x];
            top->count+=1;
        }
    }
    void search(string word){
        TrieNode* top = root;
        int val =0;
        for(auto it:word){
            int x = it-'a';
            if(top->child[x]==NULL){
                return;
            }
            top=top->child[x];
            val = val+top->count;
        }
        ans.push_back(val);
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        root = new TrieNode();
        for(auto it:words){
            insert(it);
        }
        for(auto it:words){
            search(it);
        }
        return ans;
    }
};