vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int>res ;
    stack<TreeNode*>st ; 
    TreeNode *curr = root ; 

    while(curr!=NULL || !st.empty()){
        while(curr!=NULL){
            st.push(curr) ; 
        curr= curr->left ;

        }

    TreeNode *temp = st.top() ; 
    st.pop() ; 
    res.push_back(temp->data) ; 
    curr = curr->right ; 
         
    } 
   
}