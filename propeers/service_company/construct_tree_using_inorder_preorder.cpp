class Solution {
public:
   int pre_index = 0 ; 
    TreeNode *construct(vector<int>&inorder , vector<int>&preorder, int is , int ie){
        if(is>ie){
            return NULL ; 
        }

        TreeNode* root = new TreeNode(preorder[pre_index++]) ; 

        if(is==ie){
            root->left =NULL ; 
            root->right = NULL ; 
            return root ; 
        }

        int in_index ; 
        for(int i = is ; i<=ie ; i++){
            if(inorder[i]==root->val){
                in_index = i ; 
                break ;
            }
        }

        root->left = construct(inorder , preorder , is , in_index-1) ;
        root->right = construct(inorder , preorder , in_index+1 , ie) ;
        return root ;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n= preorder.size() ;

       TreeNode *root = construct(inorder, preorder , 0 , n-1) ;
        return root ;
        
    }
};