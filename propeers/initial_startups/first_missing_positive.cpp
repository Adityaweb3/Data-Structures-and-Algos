/*You are given an array 'ARR' of integers of length N. 
Your task is to find the first missing positive integer in linear time and constant space. 
In other words, find the lowest positive integer that does not exist in the array. 
The array can have negative numbers as well.

For example, the input [3, 4, -1, 1] should give output 2 because it is the smallest positive number that is missing in the input array.
*/

#include <bits/stdc++.h> 
int firstMissing(int arr[], int n)
{
    // Write your code here.

    for(int i = 0 ; i<n ; i++){
        int CI = arr[i]-1 ; 
        while(arr[i]>0 && arr[i]<=n && arr[i]!=arr[CI]){
            swap(arr[i] , arr[CI]) ; 
            CI = arr[i]-1 ; 
        }
    }

    for(int i = 0 ; i<n ; i++){
        if(arr[i]!=i+1){
            return i+1 ; 
        }
    }

    return n+1 ; 
}