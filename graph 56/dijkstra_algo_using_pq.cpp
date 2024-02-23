// Problem Link : https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

 vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        
        vector<int> distTo(V, INT_MAX);

        
        distTo[S] = 0;
        pq.push({0, S});

        
        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            
            for (auto it : adj[node])
            {
                int v = it[0];
                int w = it[1];
                if (dis + w < distTo[v])
                {
                    distTo[v] = dis + w;
    
                    
                    pq.push({dis + w, v});
                }
            }
        }
        
        return distTo;
    }