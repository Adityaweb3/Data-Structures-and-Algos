// Problem link : https://www.geeksforgeeks.org/problems/single-valued-subtree/1

bool solve(Node *root , int &count){
    if(root==NULL){
        return true ; 
    }
     bool l = solve(root->left , count) ; 
     bool r = solve(root->right , count) ; 
     
     if(l==false || r==false){
         return false ; 
     }
     if(root->left && root->left->data!=root->data){
         return false ; 
     }
     if(root->right && root->right->data!=root->data){
         return false ; 
     }
     
     count++ ; 
     return true ; 
}
int singlevalued(Node *root)
{
    //code here
    int count =0; 
    solve(root , count) ; 
    return count ; 
}