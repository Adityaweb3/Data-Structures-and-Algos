#include <bits/stdc++.h> 
void bubbleSort(vector<int>& arr, int n)
{   
    // Write your code here.
    int i = 0 ; 
    int j = 0 ; 
    bool swapped ; 

    for(int i = 0 ; i<n-1; i++){
        swapped = false ;

        for(int j = 0 ; j<n-i-1 ; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]) ; 
                swapped = true ; 
            }
        }

        if(swapped==false){
            break ; 
        }
    }
}