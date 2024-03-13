// Problem Link : https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

class Solution {
public:
    bool isLeaf(Node* root){
        return root && (!root->left && !root->right);
    }
    void leftBound(Node* root,vector<int>&ans){
        Node* t = root->left;
        while(t){
            if(!isLeaf(t)) ans.push_back(t->data);
            if(t->left) t = t->left;
            else t = t->right;
        }
    }
    void rightBound(Node* root,vector<int>&ans){
        Node* t = root->right;
        vector<int>v;
        while(t){
            if(!isLeaf(t)) v.push_back(t->data);
            if(t->right) t = t->right;
            else t = t->left;
        }
        for(int i=v.size()-1;i>=0;i--) ans.push_back(v[i]);
    }
    void addLeaf(Node* root,vector<int>&ans){
        if(isLeaf(root)){
            ans.push_back(root->data);
            return;
        }
        if(root->left) addLeaf(root->left,ans);
        if(root->right) addLeaf(root->right,ans);
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(isLeaf(root)) return {1};
        ans.push_back(root->data);
        leftBound(root,ans);
        addLeaf(root,ans);
        rightBound(root,ans);
        return ans;
    }
};