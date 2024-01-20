// Given a sorted array arr containing n elements with possibly some duplicate, 
// the task is to find the first and last occurrences of an element x in the given array.
// Note: If the number x is not found in the array then return both the indices as -1.

int firstOccurance(int arr[] , int n , int x){
        
        int low = 0 ; int high = n-1 ;
        while(low<=high){
            int mid = low + (high-low)/2 ;
            
            if(arr[mid]>x){
                high = mid-1 ;
                
            }
            
            if(arr[mid]<x){
                low = mid+1 ;
            }
            
            if(arr[mid]==x) {
                if(mid== 0 || arr[mid-1]!=x){
                    return mid ;
                }
                
                else {
                    high = mid -1 ;
                }
            }
            
            
            
        }
        
        return -1 ; 
        
        
    }

     int lastOccurance(int arr[] , int n , int x){
        
        int low = 0 ; int high = n-1 ; 
        
        while(low<=high){
            int mid = low + (high-low)/2 ;
            
            if(arr[mid]>x){
                high = mid-1 ;
                
            }
            
            if(arr[mid]<x){
                low = mid+1 ;
            }
            
            if(arr[mid]==x) {
                if(mid== 0 || arr[mid+1]!=x){
                    return mid ;
                }
                
                else {
                    low = mid+1 ;
                }
            }
            
        }
        
        return -1 ;
    }
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        
        int first = firstOccurance(arr , n , x) ;
        int last = lastOccurance(arr, n , x) ; 
        
        return {first,last} ;
    }