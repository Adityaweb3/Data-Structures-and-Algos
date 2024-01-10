// You are given a Binary Tree.



// Return the length of the diameter of the tree.




int height(TreeNode<int>*root , int &ans){
    if(root==NULL){
        return 0 ;
    }

    int lh = height(root->left ,ans) ; 
    int rh = height(root->right , ans) ; 

    ans = max(ans , lh+rh) ; 

    return max(lh , rh)+1 ; 


}
int diameterOfBinaryTree(TreeNode<int> *root){
	// Write Your Code Here.
    int ans = 0 ;
    height(root , ans) ; 
    return ans ; 
}
