// Problem Link : https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

class Solution {
public:
    Node* connect(Node* root) {
         if(root==NULL){
            return NULL ;
        }
        queue<Node *>q ; 
        q.push(root) ; 
        while(!q.empty()){
            int n = q.size() ; 
            Node *prev = NULL ; 
            for(int i = 1; i<=n ; i++){
                Node *curr = q.front() ; 
                q.pop() ; 
                curr->next = prev ; 

                if(curr->right){
                    q.push(curr->right) ;
                }

                if(curr->left){
                    q.push(curr->left) ;
                }

                prev = curr ; 
            }
        }

        return root ;
        
    }
};