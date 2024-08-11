// Problem link : https://www.geeksforgeeks.org/problems/longest-consecutive-sequence-in-binary-tree/1

void solve(Node *node , int &maxi , int temp , int parent){
        if(node==NULL){
            return ; 
        }
        
        if(node->data==parent+1){
            temp++ ; 
        }
        else {
            temp =1 ; 
        }
        
        maxi = max(maxi , temp) ; 
        
        solve(node->left, maxi , temp, node->data) ; 
        solve(node->right , maxi , temp , node->data) ; 
        return ; 
    }
    
    int longestConsecutive(Node* root)
    {
         //Code here
         int maxi = 1 ; 
         solve(root->left , maxi , 1 , root->data) ; 
         solve(root->right , maxi , 1 , root->data) ; 
         
         if(maxi<2){
             return -1 ; 
         }
         
         return maxi ;
    }