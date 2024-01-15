// You have been given a Binary Tree of 'N' nodes, 
//where the nodes have integer values. Your task is to print the zigzag traversal of the given tree.

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
   vector<int>res ; 
   if(root==NULL){
       return res ; 
   }
   queue<BinaryTreeNode<int>*>q ; 
   stack<int>st ; 
   bool reverse = false ; 


   q.push(root) ; 

   while(!q.empty()){
       int count =q.size() ; 

       for(int i = 0 ; i<count ; i++){
           BinaryTreeNode<int> *curr = q.front() ; 
           q.pop() ; 

           if(!reverse){
               res.push_back(curr->data) ; 
           }

           else {
               st.push(curr->data) ; 
           }

           if(curr->left){
               q.push(curr->left) ; 

           }

           if(curr->right){
               q.push(curr->right) ; 
           }
       }

       if(reverse){
           while(st.empty()==false){
               res.push_back(st.top());
               st.pop() ; 
           }
       }

       reverse = !reverse ; 


   }

   return res ; 


}

