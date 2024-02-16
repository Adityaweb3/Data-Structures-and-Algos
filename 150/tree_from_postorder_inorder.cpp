// Problem Link : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()){
            return NULL ;
        }
        map<int , int>mp ; 

        for(int i = 0 ; i<inorder.size() ; i++){
            mp[inorder[i]] = i ;
        }


        return buildPost(inorder , 0 , inorder.size()-1 , postorder , 0 , postorder.size()-1, mp) ;
    }

    TreeNode *buildPost(vector<int>&inorder , int is , int ie , vector<int>&postorder , int ps , int pe , map<int , int>&mp){
        if(ps>pe || is>ie){
            return NULL ; 
        }
        TreeNode *root =  new TreeNode (postorder[pe]) ; 
        int inRoot = mp[postorder[pe]] ; 
        int numsLeft = inRoot-is ; 

        root->left = buildPost(inorder , is , inRoot-1 , postorder ,ps , ps+numsLeft-1 , mp) ;
        root->right = buildPost(inorder , inRoot+1 , ie , postorder ,ps+numsLeft, pe-1 , mp) ; 

        return root ;



    }