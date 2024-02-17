// Problem Link : https://leetcode.com/problems/delete-node-in-a-bst/description/
class Solution {
public:
    TreeNode *getSucc(TreeNode *root){
        root = root->right ; 
        while(root!=NULL && root->left!=NULL){
            root = root->left ; 
        }

        return root ;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL ;
        }

        if(root->val >key){
            root->left = deleteNode (root->left , key) ;
        }

        else if(root->val <key){
            root->right = deleteNode (root->right , key) ;
        }

        else {
            if(root->left==NULL){
                TreeNode* temp = root->right ; 
                delete root ; 
                return temp ;
            }

            else if(root->right==NULL){
                TreeNode *temp = root->left ; 
                delete root ; 
                return temp ;
            }

            else {
                TreeNode *succ = getSucc(root) ;
                root->val = succ->val ; 
                root->right = deleteNode(root->right , succ->val) ;
            }

            
        }

        return root ;
    }
};