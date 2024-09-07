// Problem link : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

class Codec {
public:

     TreeNode *create(string &s){
        if(s.size()==0){
            return NULL ; 
        }

        int index = s.find(" ") ; 
        string val = s.substr(0, index) ; 
        s = s.substr(index+1) ; 

        if(val=="N"){
            return NULL ; 
        }

        TreeNode *root=new TreeNode(stoi(val)) ; 
        root->left = create(s) ; 
        root->right = create(s) ; 
        return root ; 
     }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){
            return "N " ; 
        }

        string temp = to_string(root->val)+" " ; 
        temp+=serialize(root->left) ; 
        temp+=serialize(root->right) ; 

        return temp ; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string s = data ; 
        return create(s) ; 
    }
};
