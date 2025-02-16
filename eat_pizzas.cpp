// Problem link : https://leetcode.com/problems/eat-pizzas/

 long long maxWeight(vector<int>& pizzas) {
        int n = pizzas.size() ; 
        long long ans = 0 ; 
        int count = n/4 ; 
        int res = 1 ;
        int countOdd = (count+1)/2 ; 
        int countEven = count/2 ; 
        priority_queue<int>pq(pizzas.begin() , pizzas.end()) ; 
        while(!pq.empty() && countOdd){
            ans+=pq.top() ; 
            pq.pop() ; 
            countOdd-- ; 
        }
        while(!pq.empty() && countEven){
            pq.pop() ; 
            ans+=pq.top() ; 
            pq.pop() ; 
            countEven-- ; 
        }
        return ans ; 
    }