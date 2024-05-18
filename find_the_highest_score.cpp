// Problem Link  : https://www.geeksforgeeks.org/problems/find-the-highest-number2259/1

 int findPeakElement(vector<int>& arr) 
    {
        // Code here.
        int n = arr.size() ; 
        if(n==1){
            return arr[0] ; 
        }
        
        if(arr[0]>arr[1]){
            return arr[0] ; 
        }
        
        if(arr[n-1]>arr[n-2]){
            return arr[n-1] ; 
        }
        
        int low = 1 ; 
        int high = n-2 ; 
        
        while(low<=high){
            int mid = (low+high)/2 ; 
            
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                return arr[mid] ;
            }
            
            else if(arr[mid]>arr[mid-1]){
                low = mid+1 ;
            }
            else {
                high = mid-1 ; 
            }
        }
        return -1 ; 
    }