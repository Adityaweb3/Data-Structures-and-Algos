// Problem Link : https://leetcode.com/problems/all-possible-full-binary-trees/

class Solution {
public:
    vector<TreeNode*>solve(int n , unordered_map<int , vector<TreeNode*>>&mp){
        if(n%2==0){
            return {} ;
        }
        if(n==1){
            TreeNode *node = new TreeNode(0) ; 
            return{node} ; 
        }
        if(mp.find(n)!=mp.end()){
            return mp[n] ; 
        }
        vector<TreeNode *>res ; 
        for(int i =1 ; i<n ; i+=2){
            vector<TreeNode *>leftBT = allPossibleFBT(i) ; 
            vector<TreeNode *>rightBT = allPossibleFBT(n-i-1) ; 

            for(auto &l : leftBT){
                for(auto &r : rightBT){
                    TreeNode *root = new TreeNode(0) ; 
                    root->left = l ; 
                    root->right=r ; 
                    res.push_back(root) ; 
                }
            }
        }
        return mp[n]=res ; 
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int , vector<TreeNode*>>mp ; 
        return solve(n , mp) ; 
    }
};