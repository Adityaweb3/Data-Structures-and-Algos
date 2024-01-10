// You have been given a Binary Tree of integers. 
// You are supposed to return the level order traversal of the given tree.

vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    vector<int>res ;
    if(root==NULL){
        return res ; 
    }

    queue<BinaryTreeNode<int>*>q ; 
    q.push(root) ; 

    while(!q.empty()){
        BinaryTreeNode<int>*curr = q.front() ; 
        q.pop() ; 

        res.push_back(curr->val) ; 
        if(curr->left){
            q.push(curr->left) ; 
        }

        if(curr->right){
            q.push(curr->right) ; 
        }
    }
    return res ; 
}