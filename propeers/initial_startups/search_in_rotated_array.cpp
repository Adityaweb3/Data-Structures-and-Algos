int search(int* A, int n, int key) {
    // Write your code here.
    int l = 0 ; 
    int h = n-1 ; 
     while(l<=h){
            int mid = (l+h)/2 ;
            
            if(A[mid]==key){
                return mid ;
            }
            
            else if(A[mid]>=A[l]){
                if(key>=A[l] && key<A[mid]){
                    h = mid-1 ;
                }
                
                else {
                    l = mid+1 ;
                }
            }
            
            else {
                if(key>A[mid] && key<=A[h]){
                    l = mid+1 ;
                }
                else {
                    h = mid-1 ;
                }
            }
        }
        
        return -1 ;
}