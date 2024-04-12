class TrieNode {
public:
    int n;
    int s;
    TrieNode* child[2];
    
    TrieNode(){
        n=0;
        s=0;
        child[0] = NULL;
        child[1] = NULL;
    }
};
class Solution {
public:
    TrieNode* root;
     int val(TrieNode* root, int num, int ind){
        for( int i = 31; i >= 0; i--){
            int bit =  (num >> i)&1;
        
            if (root->child[bit] == NULL){
                return 0;
            }
            root = root->child[bit];
        }
        return (((root->n) * ind) - (root->s));
    }
    void insert(TrieNode* root, int num, int ind){
        for( int i = 31; i >= 0; i--){
            int bit =  (num >> i)&1 ;
            if ( root->child[bit] == NULL){
                root->child[bit] = new TrieNode();
            }
            root = root->child[bit];
        }
        root->s += ind;
        root->n++;
    }
    int countTriplets(vector<int>& arr) {
        root = new TrieNode();
        int ans=0;
        int x = 0;
        for ( int i = 0 ; i < arr.size(); i++){
            insert(root, x, i);
            x ^= arr[i];
            ans += val(root, x, i);
        }
        return ans;
    }
};