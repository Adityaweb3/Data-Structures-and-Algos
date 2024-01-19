// You are given a connected undirected graph. Perform a Depth First Traversal of the graph.
// Note: Use the recursive approach to find the DFS traversal of the graph 
// starting from the 0th vertex from left to right according to the graph.


class Solution {
    
  private :
   void dfs (int node , vector<int>&res , vector<int>adj[] , int vis[]){
       vis[node] =1 ;
       res.push_back(node) ;
       for(auto it : adj[node]){
           if(!vis[it]){
               dfs(it , res , adj , vis) ;
           }
       }
   }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0} ;
        int start = 0 ;
        vector<int>ls ;
        dfs(start , ls , adj , vis) ;
        return ls ;
        
    }
};
