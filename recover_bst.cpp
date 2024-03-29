// Problem Link : https://leetcode.com/problems/recover-binary-search-tree/description/


class Solution {
private : 
TreeNode* first ; 
TreeNode* last ; 
TreeNode* middle ; 
TreeNode* prev ; 

private : 

void inorder(TreeNode *root){
    if(root==NULL){
        return ; 
    }

    inorder(root->left) ; 

    if(prev!=NULL && prev->val>root->val){
        if(first==NULL){
            first = prev ; 
            middle = root ; 
        }

        last = root ; 
    }

    prev = root ; 
    inorder(root->right) ; 
}
public:
    void recoverTree(TreeNode* root) {
        first=middle=last=NULL ; 
        prev = new TreeNode(INT_MIN) ; 
        inorder(root) ; 
        if(first && last){
            swap(first->val , last->val) ; 
        }

        else if(first && middle){
            swap(first->val , middle->val) ; 
        }
    }
};