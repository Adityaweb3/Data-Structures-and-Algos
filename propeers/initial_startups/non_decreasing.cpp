/*You have been given an integer array/list 'ARR' of size 'N'. 
Write a solution to check if it could become non-decreasing by modifying at most 1 element.
We define an array as non-decreasing, if ARR[i] <= ARR[i + 1] 
holds for every i (0-based) such that (0 <= i <= N - 2).*/

#include <bits/stdc++.h> 
bool isPossible(int *arr, int n)
{
    int count = 0;
    
    for (int i = 0; i < n-1; i++) {
        if (arr[i] > arr[i + 1]) {
            
            count++;
            if (count > 1) {
                return false;
            }
            
            if (i > 0 && arr[i - 1] > arr[i + 1]) {
                arr[i + 1] = arr[i]; 
            } else {
                arr[i] = arr[i + 1]; 
            }
        }
    }
    return true;

     
}