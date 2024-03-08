// Problem Link : https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

class Solution {
    unordered_map<TreeNode* , TreeNode*>parent ; 

    void preorder(TreeNode *root , TreeNode *par){
        if(!root){
            return ; 
        }

        parent[root]= par ; 
        preorder(root->left , root) ; 
        preorder(root->right, root) ; 
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        preorder(root , NULL) ; 

        queue<TreeNode*>q ; 
        q.push(target) ; 
        unordered_set<TreeNode*>visited ; 

        while(!q.empty() && k){
            k-=1 ; 
            int n = q.size() ; 
            for(int i = 0 ; i<n ; i++){
                TreeNode *curr = q.front() ; 
                q.pop() ; 
                visited.insert(curr) ; 

                if(!visited.count(curr->left) && curr->left){
                    q.push(curr->left) ; 
                }

                if(!visited.count(curr->right) && curr->right){
                    q.push(curr->right) ; 
                }
                if(!visited.count(parent[curr]) && parent[curr]){
                    q.push(parent[curr]) ; 
                }
            }
        }

        vector<int>ans ; 

        while(!q.empty()){
            TreeNode *curr = q.front() ; 
            q.pop() ; 
            ans.push_back(curr->val) ; 
        }

        return ans ; 
    }
};