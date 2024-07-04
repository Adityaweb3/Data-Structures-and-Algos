// Problem Link : https://leetcode.com/problems/find-duplicate-subtrees/description/

string solve(unordered_map<string ,int>&mp , vector<TreeNode *>&res , TreeNode *root){
    if(root==NULL){
        return "N" ;
    }
    string s = to_string(root->val) + "," +solve(mp , res , root->left)+"," + solve(mp , res , root->right) ; 

    if(mp[s]==1){
        res.push_back(root) ;
    }

    mp[s]++; 

    return s ; 
   }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string , int>mp ; 
        vector<TreeNode *>res ; 
        solve(mp , res , root) ; 
        return res ; 
    }