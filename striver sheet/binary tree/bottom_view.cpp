// You are given a 'Binary Tree'.
// Return the bottom view of the binary tree.


vector<int> bottomView(TreeNode<int> * root){
    // Write your code here.
    vector<int>ans ; 
    if(root==NULL){
        return ans ;
    }

    if(!root->left && !root->right){
        return {root->data} ;
    }

    map<int,int>mp ;
    queue<pair<TreeNode<int>* , int>>q ;
    q.push({root, 0}) ;

    while(!q.empty()){
        TreeNode<int>*curr = q.front().first ;
        int level = q.front().second ;
        q.pop() ;
        mp[level]= curr->data ;

        if(curr->left){
            q.push({curr->left ,level-1}) ;
        }

        if(curr->right){
            q.push({curr->right , level+1}) ;
        }

    }

    for(auto it : mp){
        ans.push_back(it.second) ;
    }

    return ans ;

}