// Problem Link : https://www.geeksforgeeks.org/problems/minimum-absolute-difference-in-bst-1665139652/1

class Solution
{
    public:
    int ans = INT_MAX ; 
    
    void inorder(Node *root , int &prev){
        if(root==NULL){
            return ; 
        }
        
        inorder(root->left , prev) ; 
        
        if(prev!=-1){
            ans = min(ans , abs(root->data-prev)) ; 
        }
        prev = root->data ; 
        inorder(root->right , prev) ;
    }
    int absolute_diff(Node *root)
    {
        //Your code here
        int prev = -1 ; 
        inorder(root , prev); 
        
        return ans ; 
    }
};