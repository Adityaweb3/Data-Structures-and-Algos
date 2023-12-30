/*Given the root of a binary tree, return the inorder traversal of its nodes' values.*/


/* Recursive*/

void inorder(TreeNode *root , vector<int>&res){
    if(root==NULL){
        return ; 
    }

    inorder(root->left , res) ; 
    res.push_back(root->data) ; 
    inorder(root->right , res) ; 
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int>res ;

    inorder(root , res) ;
    return res ; 
}


/*Iterative*/

 vector<int> inorderTraversal(TreeNode* root) {
       vector<int>res ; 
       stack<TreeNode *>st ;
       TreeNode *curr = root ; 

       while(curr != NULL || !st.empty()){

           while(curr!=NULL){
               st.push(curr) ; 
               curr = curr->left ; 
           }

           curr = st.top() ;
           st.pop() ; 
           res.push_back(curr->val) ; 
           curr = curr->right ; 

       }

       return res; 
        
    
    }