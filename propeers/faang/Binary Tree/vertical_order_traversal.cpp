// Given a binary tree, return the vertical order traversal of the values of the nodes of the given tree.
// For each node at position (X, Y), (X-1, Y-1) will be its left child position while (X+1, Y-1) will be
//  the right child position.
// Running a vertical line from X = -infinity to X = +infinity, now whenever this vertical line touches 
// some nodes, we need to add those values of the nodes in order starting from 
// top to bottom with the decreasing ‘Y’ coordinates.


vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int>res ; 
    if(root==NULL){
        return res ; 
    }
    queue<pair<TreeNode<int>* , int>>q ; 
    map<int , vector<int>>mp ; 

    q.push({root , 0});

    while(!q.empty()){
        auto p = q.front() ; 
        TreeNode<int>*curr = p.first ; 
        int hd = p.second ; 

        mp[hd].push_back(curr->data) ; 
        q.pop() ; 

        if(curr->left){
            q.push({curr->left , hd-1}) ; 
        }
        if(curr->right){
            q.push({curr->right , hd+1}) ; 
        }
    }

    for(auto x: mp){
        vector<int>v = x.second ; 

        for(auto i : v){
            res.push_back(i) ; 
        }
    }

    return res ; 

}