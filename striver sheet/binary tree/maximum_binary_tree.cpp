// Problem link : https://leetcode.com/problems/maximum-binary-tree/description/

int maxi (vector<int>&nums , int s , int e){
    int ans = -1 ; 
    int max = INT_MIN ; 

    for(int i =s ; i<=e ; i++){
        if(nums[i]>max){
            ans = i ; 
            max = nums[i] ;  
        }
    }
    return ans ; 
   }
    TreeNode *construct(vector<int>&nums , int s , int e){
        if(s>e){
            return NULL ; 
        }

        if(s==e){
            return new TreeNode(nums[s]) ; 
        }
        int index = maxi(nums , s , e) ; 
        TreeNode *root= new TreeNode(nums[index]) ; 
        root->left = construct(nums , s , index-1) ; 
        root->right = construct(nums , index+1 , e) ; 
        return root ; 
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode *root= construct(nums , 0 , nums.size()-1) ; 
        return root ; 
    }