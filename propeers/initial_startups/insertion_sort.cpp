/*You are given ‘N’ integers in the form of an array ‘ARR’. 
Print the sorted array using the insertion sort.*/

#include <bits/stdc++.h> 
void insertionSort(int n, vector<int> &arr){
    // Write your code here.
    int i , j , key ; 

    for(int i =1 ; i<n ; i++){
        key = arr[i] ; 
        j = i-1 ; 

        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j] ; 
            j = j-1 ; 
        }

        arr[j+1]=key ; 
    }
}