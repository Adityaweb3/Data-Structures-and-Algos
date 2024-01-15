// You have been given a binary tree of integers. You are supposed to find the left view of the binary tree. 
// The left view of a binary tree is the set of all nodes that are visible 
// when the binary tree is viewed from the left side.

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int>res ; 

    if(root==NULL){
        return res ; 
    }
    queue<TreeNode<int>*>q ; 
    q.push(root) ; 

    while(!q.empty()){
        int n = q.size() ; 
        for(int i = 0 ; i<n ; i++){
           TreeNode<int>*curr= q.front() ; 
           q.pop() ; 
           
           if(i==0){
               res.push_back(curr->data) ; 
           }
           
           if(curr->left){
               q.push(curr->left) ;
           }
           if(curr->right){
               q.push(curr->right) ;
           }
        }
    }

    return res ; 


}