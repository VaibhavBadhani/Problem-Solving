int osum = root->data;
       int esum = 0;
       queue<Node*>q;
       q.push(root);
       int flag = 0;
       while(!q.empty()){
           int n = q.size();
           for(int i =0;i<n;i++){
               Node* node = q.front();
               q.pop();
               if(node->left){
                   if(flag==0){
                       esum += node->left->data;
                   }
                   else{
                       osum += node->left->data;
                   }
                   q.push(node->left);
               }
               if(node->right){
                   if(flag==0){
                       esum += node->right->data;
                   }
                   else{
                       osum += node->right->data;
                   }
                   q.push(node->right);
               }
           }
           flag= !flag;
       }
       return osum -esum;