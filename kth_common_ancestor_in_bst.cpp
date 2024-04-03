// Problem Link : https://www.geeksforgeeks.org/problems/kth-common-ancestor-in-bst/1

 int kthCommonAncestor(Node *root, int k,int x, int y)
    {
        // your code goes here
        Node *temp = root ; 
        vector<int>ans ; 
        while(temp){
            ans.push_back(temp->data) ; 
              if(temp->data>x and temp->data>y){
                temp=temp->left;
            }
            else if(temp->data<x and temp->data<y){
                temp=temp->right;
            }
            else{
                break;
            }
        }
        
        if(ans.size()<k) return -1;
        return ans[ans.size()-k];
    }