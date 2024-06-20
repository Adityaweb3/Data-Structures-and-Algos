// Problem Link : https://www.naukri.com/code360/problems/allocate-books_1090540

// answer will be between maxi and sumation of array . 

int isFind(vector<int>&arr , int mid){
    int student =1 ; 
    int pages = 0 ; 

    for(int i=0 ; i<arr.size() ; i++){
        if(pages+arr[i]<=mid){
            pages+=arr[i] ; 
        }
        else {
            student++ ; 
            pages= arr[i] ; 
        }
    }

    return student ; 
}

int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m>n){
        return -1 ;
    }
    int high =0 ; 
    int low = INT_MIN ; 
    for(int i=0 ; i<n ; i++){
        high+=arr[i] ; 
        low = max(low, arr[i]) ; 
    }

    while(low<=high){
        int mid = low+(high-low)/2 ;

        int student = isFind(arr , mid) ; 

        if(student>m){
            low = mid+1 ; 
        }
        else {
            high = mid-1 ; 
        }
    }

    return low ; 
}