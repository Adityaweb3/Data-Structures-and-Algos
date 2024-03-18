// Problem Link : https://leetcode.com/problems/total-cost-to-hire-k-workers/

long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size() ; 
        priority_queue<int , vector<int> , greater<int>>pq1 , pq2 ; 
        long long ans = 0 ; 
        int h = 0 ; int i =0 ; int j=n-1 ; 

        while(h<k){
            while(pq1.size()<candidates && i<=j){
                pq1.push(costs[i++]) ;
            }
            while(pq2.size()<candidates && j>=i){
                pq2.push(costs[j--]) ;
            }

            int a = pq1.size() ?pq1.top() :INT_MAX ; 
            int b = pq2.size() ? pq2.top() : INT_MAX ; 

            if(a<=b){
                ans+=a ; 
                pq1.pop() ;
            }

            else {
                ans+=b ; 
                pq2.pop() ;
            }

            h++ ; 
        }

        return ans ;
    }