// You have been given a Binary Tree of distinct integers and two nodes ‘X’ and ‘Y’. 
// You are supposed to return the LCA (Lowest Common Ancestor) of ‘X’ and ‘Y’.
// The LCA of ‘X’ and ‘Y’ in the binary tree is the shared ancestor 
// of ‘X’ and ‘Y’ that is located farthest from the root.


int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    if(root==NULL){
        return -1 ; 
    }

    if(root->data==x || root->data==y){
        return root->data ; 
    }

    int lh = lowestCommonAncestor(root->left , x,y) ; 
    int rh = lowestCommonAncestor(root->right , x , y) ; 

    if(lh!=-1 && rh!=-1){
        return root->data ; 
    }

    return (lh!=-1) ? lh : rh ;
}