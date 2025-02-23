// Problem Link : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/

TreeNode *solve(vector<int>&preorder , vector<int>&postorder , int &index , int start , int end , unordered_map<int , int>&mp){
    int n = preorder.size() ; 
    if(index>=n || start>end){
        return NULL ; 
    }
    int value = preorder[index++] ; 
    TreeNode *root = new TreeNode(value) ; 
    if(start==end){
        return root ; 
    }
    int pos = mp[preorder[index]] ; 
    root->left = solve(preorder , postorder , index , start , pos , mp) ; 
    root->right = solve(preorder , postorder , index , pos+1 , end-1 ,mp) ; 
    return root ; 
}
TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    int n = preorder.size() ; 
    unordered_map<int , int>mp ; 
    for(int i = 0 ; i<n; i++){
        mp[postorder[i]]= i ; 
    }
    int index = 0 ; 
    return solve(preorder , postorder , index , 0 , n-1 , mp) ; 
}