// Problem Link : https://www.interviewbit.com/problems/capacity-to-ship-packages-within-b-days/

bool isPossible(vector<int>&arr , int mid , int d){
    int count =1 ; 
    int curr = 0 ; 
    
    for(int i = 0 ; i<arr.size() ; i++){
        if(arr[i]>mid){
            return 0 ;
        }
        
        if(curr+arr[i]<=mid){
            curr+=arr[i] ;
        }
        else {
            count++ ; 
            curr = arr[i] ; 
        }
    }
    
    return count<=d ; 
}

int Solution::solve(vector<int> &A, int B) {
    int low =1 ; 
    int high = 0 ; 
    
    for(auto i : A){
        high+=i ; 
    }
    
    while(low<=high){
        int mid = low +(high-low)/2 ; 
        
        if(isPossible(A , mid , B)){
            high = mid-1 ; 
        }
        else {
            low = mid+1 ;
        }
    }
    
    return low ;
}