/*Given an array 'arr' with 'n' elements, 
the task is to rotate the array to the left by 'k' steps, where 'k' is non-negative.*/


#include <bits/stdc++.h> 
vector<int> rotateArray(vector<int>arr, int k) {
    // Write your code here.
    int n = arr.size() ; 
    k = k%n ; 

    if(k!=0){
        reverse(arr.begin() , arr.begin()+k) ;
        reverse(arr.begin()+k , arr.end()) ; 
        reverse(arr.begin() , arr.end()) ; 

    }

    

    return arr ; 
}