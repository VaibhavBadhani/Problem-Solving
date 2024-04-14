
struct Node{
    public:
    Node* links[26];
    bool flag=false;
    vector<int> prefix;
    
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }

    void putwords(char ch,Node* node){
         links[ch-'a']=node;
    }

    Node* get(char ch){
          return links[ch-'a'];
    }

};


class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
    }
    vector<vector<string>> ans;
    void insert(string& word,int idx) {
        Node* node=root;

        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->putwords(word[i],new Node());
            }
            node=node->get(word[i]);
            node->prefix.push_back(idx);
        }
        node->flag=true;
    }
    
    void search(string& word,vector<string>& contact) {
        Node* node=root;
        vector<string> temp;
        int i;
        for( i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                break;
            }
            node=node->get(word[i]);
            for(auto it:node->prefix){
                temp.push_back(contact[it]);
            }
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
            temp.clear();
        }
        temp.clear();
        temp.push_back("0");
        for(int j=i;j<word.size();j++) ans.push_back(temp);
        
        return;
    }
    
    
};

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contacts[], string s)
    {
        // code here
        Trie t;
        unordered_set<string> set;
        for(int i=0;i<n;i++)set.insert(contacts[i]);
        vector<string> contact;
        for(auto it:set)contact.push_back(it);
        
        for(int i=0;i<contact.size();i++)t.insert(contact[i],i);
        t.search(s,contact);
        return t.ans;
        
    }
};