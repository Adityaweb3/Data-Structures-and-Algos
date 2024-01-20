// Given an array arr[] of distinct integers of size N and a value sum, 
// the task is to find the count of triplets (i, j, k), 
// having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) smaller than the given value sum.


long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    sort(arr , arr+n) ;
	    int count = 0 ;
	    for(int i = 0 ; i<n-2 ; i++){
	        int j= i+1 ;
	        int k = n-1 ;
	        
	        while(j<k){
	              long long x=arr[i]+arr[j]+arr[k];
	            if(x<sum){
	                count+=(k-j);
	                j++;
	            }
	            else{
	                k--;
	            }
	        }
	    }
	    
	    return count ;
	}