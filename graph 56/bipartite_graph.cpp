//Problem Link : https://leetcode.com/problems/is-graph-bipartite/description/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size() ; 
        vector<int>color(n,0) ; 

        for(int i = 0 ; i<n ; i++){
            if(color[i]!=0){
                continue ;
            }

            queue<int>q ; 
            q.push(i) ; 
            color[i]= 1 ; 


            while(!q.empty()){
                int curr = q.front() ; 
                q.pop() ; 

                for(auto adjN : graph[curr]){
                    if(color[adjN]==0){
                        color[adjN]= -color[curr] ;
                        q.push(adjN) ;
                    }
                    else if(color[adjN]!=-color[curr]){
                        return false ;
                    }
                }
            }
        }

        return true ;
    }
};
