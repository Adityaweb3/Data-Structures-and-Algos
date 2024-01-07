// Given a binary tree, determine if it is 
// height-balanced
// A height-balanced binary tree is a binary tree in 
//which the depth of the two subtrees of every node never differs by more than one.


class Solution {
public:
   
   int Height(TreeNode *root){
       if(root==NULL){
           return 0 ; 
       }

       int lh = Height(root->left) ; 
       int rh = Height(root->right) ; 

       if(lh ==-1 || rh==-1 || abs(lh-rh)>1){
           return -1 ; 
       }

       return max(lh , rh) +1 ; 
   }
     
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true ; 
        }

        if(Height(root)==-1){
            return false ; 
        }

        return true ; 
    }
};