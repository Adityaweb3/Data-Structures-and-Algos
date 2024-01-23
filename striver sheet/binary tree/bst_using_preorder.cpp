// Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), 
// construct the tree and return its root.

// It is guaranteed that there is always possible to find a binary search tree with 
// the given requirements for the given test cases.

// A binary search tree is a binary tree where for every node, 
// any descendant of Node.left has a value strictly less than Node.val, and any descendant of 
// Node.right has a value strictly greater than Node.val.
// A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, 
// then traverses Node.right.


TreeNode* solve(vector<int>&preorder , int mini , int maxi , int &i){
        if(i>=preorder.size()){
            return NULL ;
        }

        if(preorder[i]<mini || preorder[i]>maxi){
            return NULL ;
        }

        TreeNode *curr = new TreeNode(preorder[i++]) ;
        curr->left = solve(preorder , mini , curr->val, i) ;
        curr->right = solve(preorder , curr->val , maxi, i) ;

        return curr ;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0 ;

        return solve(preorder , INT_MIN , INT_MAX , i) ;
        
        
    }
 