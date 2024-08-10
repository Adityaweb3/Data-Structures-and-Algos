// Problem Link : https://www.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/

bool solve(Node *root , int &count , int &node , int &val){
    if(root==NULL){
        return 0 ; 
    }
    
    if(root->data==node){
        return 1; 
    }
    
    int l = solve(root->left , count , node , val) ; 
    int r = solve(root->right , count , node , val) ; 
    
    if(l|| r){
        count-- ; 
        if(count==0){
            val = root->data ; 
        }
        return 1 ; 
    }
    
    return 0 ;
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    int count = k ; 
    int val = -1 ; 
    
    solve(root , count , node , val) ; 
    return val ; 
}
