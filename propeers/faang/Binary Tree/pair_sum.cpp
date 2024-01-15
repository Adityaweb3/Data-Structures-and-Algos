// You are given a Binary Search Tree (BST) and a target value ‘K’. 
// Your task is to return true if there exist two nodes in the given BST 
// such that the sum of their values is equal to the given target ‘K’, else return false.


void inorder(BinaryTreeNode *root , vector<int>&res){
    if(root==NULL){
        return ; 
    }
    inorder(root->left , res) ; 
    res.push_back(root->data) ; 
    inorder(root->right , res) ; 
}
bool pairSumBst(BinaryTreeNode *root, int k)
{
    // Write your code here
    vector<int>res ; 
    inorder(root , res) ;

    if(res.size()==0){
        return false ;
    }

    int low = 0 ; 
    int high = res.size()-1; 


    while(low<high){
        int sum = res[low]+res[high] ; 

        if(sum==k){
            return true ; 
        }

        else if(sum<k){
            low++ ; 
        }

        else {
            high-- ; 
        }
    }

    return false ; 
    

}