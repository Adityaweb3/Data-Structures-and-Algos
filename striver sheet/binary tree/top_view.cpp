// You are given a Binary Tree of 'n' nodes.
// The Top view of the binary tree is the set of nodes visible when we see the tree from the top.
// Find the top view of the given binary tree, from left to right.


vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    vector<int>res ; 
    if(root==NULL){
        return res ; 
    }
    queue<pair<TreeNode<int>*, int>>q ; 
    map<int,int>mp ; 
    q.push({root , 0}) ; 
    while(q.empty()==false){
        auto p = q.front() ;
        TreeNode<int>*curr = p.first ; 
        int hd = p.second ; 
        if(mp.find(hd)==mp.end()){
            mp[hd]=curr->data ; 
        }
        q.pop() ; 
        if(curr->left){
            q.push({curr->left , hd-1}) ;
        }
        if(curr->right){
            q.push({curr->right , hd+1}) ; 
        }
    }

    for(auto i :mp){
        res.push_back(i.second) ; 
    }

    return res ; 

   
}