// Problem link : https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/

class Solution {
public:

    vector<int>merge(vector<int>&res1 , vector<int>&res2){
        int i =0 ; 
        int j =0 ; 
        int n = res1.size() ; 
        int m = res2.size() ; 
        vector<int>ans ; 

        while(i<n && j<m){
            if(res1[i]<res2[j]){
                ans.push_back(res1[i]) ;  
                i++ ; 
            }

            else if(res1[i]>res2[j]){
                ans.push_back(res2[j]) ; 
                j++ ;  
            }
            else {
                ans.push_back(res1[i]) ;  
                i++ ; 
                ans.push_back(res2[j]) ; 
                j++ ; 
            }
        }

        while(i<n){
            ans.push_back(res1[i]) ; 
            i++ ; 
        }

        while(j<m){
            ans.push_back(res2[j]) ; 
            j++ ; 
        }

        return ans ; 
    }
    void inorder(TreeNode *node , vector<int>&res){
        if(node==NULL){
            return ; 
        }

        inorder(node->left , res) ; 
        res.push_back(node->val) ; 
        inorder(node->right , res) ;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>res1 ; 
        vector<int>res2 ; 

        inorder(root1 ,res1) ; 
        inorder(root2 , res2) ; 


        return merge(res1 , res2) ; 
    }
};