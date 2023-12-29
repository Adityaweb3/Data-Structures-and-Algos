#include <bits/stdc++.h> 

//You are given an array 'arr' of length 'n', consisting of integers.
//A subarray is a contiguous segment of an array. In other words, 
//a subarray can be formed by removing 0 or more integers 
//from the beginning and 0 or more integers from the end of an array.
//Find the sum of the subarray (including empty subarray) having maximum sum among all subarrays.
//The sum of an empty subarray is 0.


long long maxSubarraySum(vector<int> arr, int n)
{
    // Write your code here.

    long long ans = arr[0]; 
    long long maxi = arr[0]; 

    for (int i = 1; i < n; i++) {
        
        ans = max((long long)arr[i], ans + arr[i]);
        
       
        maxi = max(maxi, ans);
    }

    
    if (maxi < 0) {
        return 0;
    }

    return maxi;
}