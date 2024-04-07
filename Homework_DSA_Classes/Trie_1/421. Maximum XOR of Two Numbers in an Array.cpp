class TrieNode{
    public:
    TrieNode* right;
    TrieNode* left;
    TrieNode(){
        right=NULL;
        left=NULL;
    }
};
class Solution {
public:
    TrieNode* root;
    int findMaximumXOR(vector<int>& nums) {
        root = new TrieNode();
        int maxXOR = 0;
         for(auto num: nums){
            TrieNode* cur = root; 
			TrieNode* q = root; 
            int curXOR = 0;
            for(int h=31; h>=0; h--){ 
                if((num & (1<<h))==0){
                    cur = cur->left ? cur->left : cur->left = new TrieNode(); 
                    curXOR |= q->right ? 1<<h : 0;
                    q = q->right ? q->right : q->left; 
                }
                else{
                    cur = cur->right ? cur->right : cur->right = new TrieNode();
                    curXOR |= q->left ? 1<<h : 0;
                    q = q->left ? q->left : q->right;
                }
            }
            maxXOR = max(maxXOR,curXOR);
        }
        return maxXOR;
    }
};