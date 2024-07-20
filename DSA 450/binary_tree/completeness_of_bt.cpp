// Problem link : https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/

bool isCompleteTree(TreeNode* root) {
        queue<TreeNode *>q ; 
        q.push(root) ; 
        bool flag = false ; 

        while(!q.empty()){
            TreeNode *curr = q.front() ; 
            q.pop() ; 

            if(curr==NULL){
                flag=true ; 
            }
            else {
                if(flag==true){
                    return false ; 
                }
                q.push(curr->left); 
                q.push(curr->right); 
            }
        }
        return true ; 
    }