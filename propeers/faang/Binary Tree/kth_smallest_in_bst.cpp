// You have been given a Binary Search Tree of integers. You are supposed to return the k-th (1-indexed) 
// smallest element in the tree.

void inorder(TreeNode <int>*root , vector<int>&res){
    if(root==NULL){
        return ;
    }

    inorder(root->left , res);
    res.push_back(root->data) ;
    inorder(root->right ,res) ; 
}

int kthSmallest(TreeNode<int> *root, int k)
{
    //  Write the code here.

    vector<int>res ; 

    inorder(root ,res) ; 


    return res[k-1] ; 
}