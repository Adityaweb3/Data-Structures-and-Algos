// problems_link : https://www.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/1

vector<int> noSibling(Node* root)
{
    vector<int>ans ; 
    set<int>ans2 ; 
    
    if(!root){
        return ans ;
    }
    
    queue<Node *>q ; 
    q.push(root) ; 
    
    while(!q.empty()){
        int n = q.size() ; 
        
        for(int i = 0 ; i<n ; i++){
            Node *temp = q.front() ; 
            if(temp->left && temp->right){
                q.push(temp->left) ; 
                q.push(temp->right) ;
            }
            
            else if(temp->right) {
                q.push(temp->right) ; 
                ans2.insert(temp->right->data) ;
            }
            
            else if(temp->left){
                q.push(temp->left) ; 
                ans2.insert(temp->left->data) ;
            }
            
            q.pop() ;
        }
    }
    
    if(ans2.size()==0){
        return {-1} ;
    }
    
    for(auto it : ans2){
        ans.push_back(it) ;
    }
    
    return ans ;
}