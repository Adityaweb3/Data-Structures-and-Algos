// Problem Link : https://leetcode.com/problems/evaluate-boolean-binary-tree/description/

bool evaluateTree(TreeNode* root) {
        if(root->left==NULL && root->right==NULL){
            return root->val ; 
        }
          
        if(root->val ==2){
            return evaluateTree(root->left) || evaluateTree(root->right) ; 
        }
        else if(root->val == 3){
            return evaluateTree(root->left) && evaluateTree(root->right) ; ;  
        }

        return false ; 

        
    }