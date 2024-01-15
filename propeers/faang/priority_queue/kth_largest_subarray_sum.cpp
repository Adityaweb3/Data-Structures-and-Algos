// Given an array of integers, find the Kth largest sum subarray For example, 
// given the array [1, -2, 3, -4, 5] and K = 2, the 2nd largest sum subarray would be [3, -4, 5], 
// which has a sum of 4.
// Please note that a subarray is the sequence of consecutive elements of the array.


int getKthLargest(vector<int> &Arr, int K)
{
	//	Write your code here.
	int N= Arr.size() ; 
	 priority_queue<int , vector<int> , greater<int>>pq ; 
        
        for(int i =0 ; i<N ; i++){
            int sum = 0 ; 
            
            for(int j = i ; j<N ; j++){
                sum+=Arr[j] ; 
                
                if(pq.size()<K){
                    pq.push(sum) ; 
                }
                
                else if(sum>pq.top()){
                    pq.pop() ; 
                    pq.push(sum) ; 
                }
            }
        }
        
        
        return pq.top() ; 
}