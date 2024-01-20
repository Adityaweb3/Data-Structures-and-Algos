// Given an array Arr[] of size L and a number N, 
// you need to write a program to find if there exists a pair of elements in the array whose difference is N.

bool findPair(int arr[], int size, int n){
    //code
    sort(arr, arr+size) ; 
    
     int i = 0, j = 1;
        while (i < size && j < size) {
            if (arr[j] - arr[i] == n && j != i) {
                return true;
            }
            if (arr[j] - arr[i] > n) {
                i++;
            } else {
                j++;
            }
        }
        return false;
    
}