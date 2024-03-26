
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s = "";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* currnode = q.front();
            q.pop();
            if(currnode==NULL) s.append("#,");
            else {
                s.append(to_string(currnode->val)+',');
            }
            if(currnode!=NULL){
                q.push(currnode->left);
                q.push(currnode->right);
            }
        }
        cout<<s;
        return s;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        queue<TreeNode*> q;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#"){
                node->left=NULL;
            }
            else{
                TreeNode* leftnode = new TreeNode(stoi(str));
                node->left= leftnode;
                q.push(leftnode);
            }
            getline(s,str,',');
            if(str=="#"){
                node->right=NULL;
            }
            else{
                TreeNode* rightnode = new TreeNode(stoi(str));
                node->right= rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));