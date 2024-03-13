// Problem Link : https://leetcode.com/problems/binary-search-tree-iterator/

class BSTIterator {
private : 

stack<TreeNode *>st ; 

public:
    BSTIterator(TreeNode* root) {
        pushAll(root) ;
    }
    
    int next() {
        TreeNode *curr=st.top() ;
        st.pop() ; 
        pushAll(curr->right) ;
        return curr->val ; 
        
    }
    
    bool hasNext() {
        return !st.empty() ;
    }
    private : 
    void pushAll(TreeNode *root){
        for( ; root!=NULL ; st.push(root)  , root= root->left) ; 
    }
};
