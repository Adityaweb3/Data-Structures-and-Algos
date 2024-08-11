// Problem Link : https://leetcode.com/problems/most-frequent-subtree-sum/description/

 int solve(TreeNode *root , unordered_map<int , int>&mp){
        if(root==NULL){
            return 0 ; 
        }

        int l = solve(root->left , mp) ; 
        int r = solve(root->right , mp) ; 

        int curr = root->val ; 

        mp[l+r+curr]++ ; 

        return (l+r)+curr ; 


    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>ans ; 
        unordered_map<int , int>mp ; 
        solve(root , mp) ; 
        int freq = INT_MIN ; 
        for(auto i : mp){
            if(i.second>freq){
                freq = i.second ; 
            }
        }

        for(auto i : mp){
            if(i.second ==freq){
                ans.push_back(i.first) ; 
            }
        }

        return ans ; 
    }