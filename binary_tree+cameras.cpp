// Problem Link : https://leetcode.com/problems/binary-tree-cameras/

class Solution {
public:
   int cam = 0 ; 
   int camera(TreeNode *root){
    if(!root){
        return 0 ;
    }
    int l = camera(root->left);
    int r = camera(root->right) ; 

    if(l==-1 || r==-1){
        cam++ ; 
        return 1 ; 
    }

    if(l==1 || r==1){
        return 0 ; 
    }

    return -1 ; 
   }
    int minCameraCover(TreeNode* root) {
        if(camera(root)==-1){
            return cam+1 ; 
        }

        return cam ; 
    }
};