class TrieNode{
    public:
    TrieNode* link[2];
    int cnt ;
    TrieNode(){
        for(auto& itr :link){
            itr = NULL;
        }
        cnt = 0;
    }
};
class Solution {
public:
    TrieNode* root;
    const int maxi = 14;
    void insert(int num){
        TrieNode* top = root;
        for(int i =14;i>=0;i--){
            int mask = 1<<i;
            int bit =(num&mask)>0?1:0;
            if(top->link[bit]==NULL){
                top->link[bit]=new TrieNode();
            }
            top=top->link[bit];
            top->cnt++;
        }
    }
    int count(TrieNode* node,int high ,int val,int ind){
        
        if(node==NULL)return 0;
        if(ind<0){
            return node->cnt;
        }
        int bitv = (val&(1<<ind))>0?1:0;
        int bith = (high&(1<<ind))>0?1:0;
        int ans =0;
        if(bitv==0){
            if(bith==0){
                ans= count(node->link[0],high,val,ind-1);
            }
            else{
                if(node->link[0]!=NULL){
                    ans+=node->link[0]->cnt;
              }
                ans +=count(node->link[1],high,val,ind-1);
            }
        }
        else{
            if(bith==0){
                ans= count(node->link[1],high,val,ind-1);
            }
            else{
                 if(node->link[1]!=NULL){
                     ans+=node->link[1]->cnt;
                 }
                ans+=count(node->link[0],high,val,ind-1);
            }
        }
        return ans;
    }
    int countPairs(vector<int>& nums, int low, int high) {
        root = new TrieNode();
        int counto=0;
        for(auto& itr:nums){
            counto +=count(root,high,itr,14);
            counto -=count(root,low-1,itr,14);
            insert(itr);
        }
        return counto;
    }
};