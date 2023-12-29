#include <bits/stdc++.h> 
int findSecondLargest(int n, vector<int> &arr)
{
    // Write your code here.
    int maxi = INT_MIN; 
    int maxi2 = INT_MIN ; 

    for(int i =0 ; i<n ; i++){
        if(arr[i]>maxi){
            maxi2 = maxi ; 
            maxi = arr[i] ; 
        }

        else if (arr[i]<maxi && arr[i]>maxi2){
            maxi2 = arr[i] ; 
        }
    }

    if(maxi2 ==INT_MIN){
        return -1 ; 
    }

    return maxi2 ; 

    
}