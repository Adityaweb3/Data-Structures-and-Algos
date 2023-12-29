/*You are given an array Arr consisting of N integers. You need to find the equilibrium index of the array.

An index is considered as an equilibrium index if the sum of elements of the array to the left of that index is equal to the sum of elements to the right of it.

Note:

1. The array follows 0-based indexing, so you need to return the 0-based index of the element.
2. Note that the element at the equilibrium index won’t be considered for either left sum or right sum.
3. If there are multiple indices which satisfy the given condition, then return the left-most index i.e if there are indices i,j,k…. which are equilibrium indices, return the minimum among them
4. If no such index is present in the array, return -1.
*/

#include <bits/stdc++.h> 
int findEquilibriumIndex(vector<int> &arr) {
    
    int prefix = 0;
    int suffix = 0;

    
    for (int num : arr) {
        suffix += num;
    }

    for (int i = 0; i < arr.size(); i++) {
        suffix -= arr[i];  

       
        if (prefix == suffix) {
            return i;
        }

        
        prefix += arr[i];
    }
    return -1;
    
}