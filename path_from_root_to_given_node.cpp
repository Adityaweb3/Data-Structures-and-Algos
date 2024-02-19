// Problem Link : https://www.codingninjas.com/studio/problems/path-in-a-tree_3843990


bool path(TreeNode <int>*root , vector<int>&res , int x){
	if(!root){
		return false ;
	}

	res.push_back(root->data) ;
	if(root->data==x){
		return true ;
	}

	if(path(root->left , res, x) || path(root->right , res , x)){
		return true ;
	}

	else {
		res.pop_back() ;
		return false ;
	}
	

	 
	
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int>res ;

	if(path(root , res ,x)==true){
		return res ;
	}

	else {
		return {-1} ;
	}
}