// Problem link : https://leetcode.com/problems/magnetic-force-between-two-balls/description/

bool isPossible(vector<int>& position , int mid , int m ){
    int n = position.size() ; 
    int count=1 ; 
    int prev = position[0] ; 
    for(int i =1 ; i<n ; i++){
        if(position[i]-prev>=mid){
            count++ ; 
            if(count==m){
                return 1 ;
            }
            prev = position[i] ; 
        }
        else {
            continue ; 
        }
    }

    return 0 ;
   }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size() ; 
        sort(position.begin() , position.end()) ; int low = 1 ; 
        int high = position[n-1]-position[0] ; 

        while(low<=high){
            int mid = low+(high-low)/2 ; 

            if(isPossible(position , mid , m)){
                low = mid+1 ; 
            }
            else{
                high = mid-1 ; 
            }
        }

        return low-1 ; 
    }