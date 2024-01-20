// Given a sorted and rotated array A of N elements which is rotated at some point, 
// and may contain duplicates and given an element key. 
// Check whether the key exist in the array A or not.

 bool search(vector<int>& arr, int target) {
        int low = 0 ; 
        int high = arr.size()-1 ;

        while(low<=high){
            int mid = low +(high-low)/2 ;

            if(arr[mid]==target){
                return true ;
            }

            if(arr[low]==arr[mid] && arr[mid]== arr[high]){
                low = low+1 ;
                high = high-1 ;
                continue ;
            }

            if(arr[low]<=arr[mid]){
                if(arr[low]<=target && arr[mid]>=target){
                    high = mid-1 ;
                }
                else {
                    low = mid+1 ;
                }
            }

            else {
                if(arr[mid]<=target && arr[high]>=target){
                    low = mid+1 ;
                }
                else {
                    high = mid-1 ;
                }
            }
        }

        return false ;
        
    }