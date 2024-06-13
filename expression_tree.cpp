// Problem link : https://www.geeksforgeeks.org/problems/expression-tree/

int evalTree(node* root) {
        // Your code here
        if(root==NULL){
            return 0 ; 
        }
        if(root->left==NULL && root->right==NULL){
            return stoi(root->data) ; 
        }
        int left = evalTree(root->left) ; 
        int right = evalTree(root->right) ; 
        if(root->data=="+"){
            return left+right ; 
        }
        
        if(root->data=="-"){
            return left-right ; 
        }
        if(root->data=="*"){
            return left*right ; 
        }
        if(root->data=="/"){
            return left/right ; 
        }
        
        return -1 ; 
    }