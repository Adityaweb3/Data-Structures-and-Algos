// Problem Link : https://www.interviewbit.com/problems/woodcutting-made-easy/

bool isPossible (vector<int>&A , int mid , int B){
    int curr = 0 ; 
    for(int i = 0 ; i<A.size() ; i++){
        if(A[i]>=mid){
            curr+=(A[i]-mid) ; 
            
            if(curr>=B){
                return true; 
            }
        }
    }
    
    return false ;
}

int Solution::solve(vector<int> &A, int B) {
    int low= INT_MAX ; 
    int high =INT_MIN ; 
    int ans = -1 ;
    
    for(int i = 0 ; i<A.size() ; i++){
        low = min(low , A[i]) ; 
        high = max(high , A[i]) ; 
    }
    
    while(low<=high){
        int mid = low +(high-low)/2 ; 
        if(isPossible(A , mid , B)){
            low = mid+1 ;
            ans= mid ;
        }
        
        else {
            high = mid-1 ; 
        }
    }
    
    return ans ; 
}
