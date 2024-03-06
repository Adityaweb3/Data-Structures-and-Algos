// Problem Link : https://leetcode.com/problems/house-robber-iii/description/

 int find(TreeNode* root , unordered_map<TreeNode* , int>&mp){
       if(root==NULL){
           return 0 ; 
       }

       if(mp.find(root)!=mp.end()){
           return mp[root] ; 
       }

       int ans = root->val ; 

       if(root->left){
           ans+=find(root->left->left , mp) + find(root->left->right , mp) ; 
       }

       if(root->right){
           ans+=find(root->right->left , mp) + find(root->right->right ,mp) ; 
       }

       ans = max(ans , find(root->left ,mp)+find(root->right ,mp)) ; 

       return mp[root]= ans ; 
   }
    int rob(TreeNode* root) {
        unordered_map<TreeNode *,int>mp ; 
        return find(root , mp) ; 
    }