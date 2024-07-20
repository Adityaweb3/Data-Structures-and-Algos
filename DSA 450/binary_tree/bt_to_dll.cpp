// Problem link : https://www.geeksforgeeks.org/problems/binary-tree-to-dll/1

 void inorder(Node*root , vector<int>&ans){
        if(root==NULL){
            return ;
        }
        inorder(root->left , ans) ; 
        ans.push_back(root->data);
        inorder(root->right , ans) ; 
    }
    
    Node *dL(vector<int>&ans){
        int n = ans.size() ; 
        if(n==0){
            return NULL ; 
        }
        
        Node *head = new Node(ans[0]) ; 
        Node *temp = head ; 
        
        for(int i = 1 ; i<n ; i++){
            Node *newNode = new Node(ans[i]) ; 
            temp->right = newNode ; 
            newNode->left = temp ; 
            temp = temp->right ; 
        }
        return head ; 
    }
    Node * bToDLL(Node *root)
    {
        // your code here
        vector<int>ans ; 
        inorder(root , ans) ; 
        Node *curr = dL(ans) ; 
        return curr ; 
    }