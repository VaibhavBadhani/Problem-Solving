class TrieNode {
public:
    TrieNode* children[26];
    int shortest;
    TrieNode(int x) : shortest(x){
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};
class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
       TrieNode* root = new TrieNode(0);
        int n = wordsContainer.size();
        for(int i = 0 ; i < n; i++){
            string word = wordsContainer[i];
            if(wordsContainer[root->shortest].size()> word.size()) 
            { 
                root->shortest = i;
            }
            TrieNode* curr = root;
            
            for(int j = word.size() -1; j>=0; j--){ 
                int c = word[j]-'a'; 
                if(!curr->children[c]){
                    curr->children[c] = new TrieNode(i);
                }
                curr = curr->children[c];
                
                if( wordsContainer[curr -> shortest].size() > word.size()) curr->shortest = i; 
            }
        }
        vector<int> ans;
        for(string word: wordsQuery){
            TrieNode* curr = root;
            for(int j = word.size()-1; j>=0; j--){
                int c =  word[j]-'a';
                if(!curr->children[c]){
                    break;
                }
                curr = curr->children[c];
            }
            ans.push_back(curr->shortest);
        }
        return ans;
    }
}; 