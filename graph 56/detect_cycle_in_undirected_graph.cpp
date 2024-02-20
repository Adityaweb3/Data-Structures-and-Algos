// Problem Link : https://www.codingninjas.com/studio/problems/detect-cycle-in-an-undirected-graph_758967
class Graph {

public:
    bool detect(int src , vector<int>adj[], int vis[]){
        vis[src]= 1 ;
        queue<pair<int , int>>q ; 
        q.push({src , -1}) ; 

        while(!q.empty()){
            int node = q.front().first ; 
            int parent = q.front().second ; 
            q.pop() ; 

            for(auto i : adj[node]){
                if(!vis[i]){
                    vis[i]= 1 ;
                    q.push({i , node}) ;
                }

                else if(parent != i){
                    return true ;
                }
            }
        }

        return false ;
    }
    bool detectCycle(int V, vector<int> adj[]) {
        // Write your code here.
        int vis[V]= {0} ; 

        for(int i =0 ; i<V ; i++){
            if(!vis[i]){
                if(detect(i , adj , vis)==true){
                    return true ;
                }
            }
        }

        return false ;

    }
};