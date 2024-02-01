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