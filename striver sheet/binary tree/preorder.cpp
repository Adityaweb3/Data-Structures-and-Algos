// Given the root of a binary tree, return the preorder traversal of its nodes' values

 vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res ;
        if(root==NULL){
            return res ;
        }
        stack<TreeNode *>st ;
        st.push(root) ;

        while(st.empty()==false){
            TreeNode *curr = st.top() ;
            st.pop() ; 
            res.push_back(curr->val) ;


            if(curr->right){
                st.push(curr->right) ;
            }

            if(curr->left){
                st.push(curr->left) ;
            }
        }

        return res ;
        
    }