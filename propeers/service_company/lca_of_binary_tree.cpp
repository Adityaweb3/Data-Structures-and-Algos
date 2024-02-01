// Problem Link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root==NULL){
            return NULL;
        }
        if(root == p || root== q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left != NULL && right== NULL){
            return left;
        }
        if(left == NULL && right != NULL){
            return right;
        }
        if(left == NULL && right == NULL){
            return NULL;
        }
        if(left != NULL && right != NULL){
            return root;
        }

        return NULL;   
        
    }
};