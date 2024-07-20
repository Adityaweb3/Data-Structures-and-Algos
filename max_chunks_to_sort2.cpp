// Problem Link : https://leetcode.com/problems/max-chunks-to-make-sorted-ii/description/

int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size() ; 
        int count = 0 ;
        vector<int>left(n,0) ; 
        left[0]=arr[0] ; 

        for(int i =1 ; i<n ; i++){
            left[i]= max(left[i-1], arr[i]) ; 
        }

        vector<int>right(n , 0) ; 
        right[n-1]=arr[n-1] ; 

        for(int i =n-2 ; i>=0; i--){
            right[i]= min(arr[i] , right[i+1]) ; 
        }

        for(int i = 0 ; i<n-1 ; i++){
            if(left[i]<=right[i+1]){
                count++ ; 
            }
        }

        count++ ; 

        return count ; 
    }
};