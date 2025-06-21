bool isvalid(int mid , vector<int>&arr , int k){
    int n = arr.size() ; 
    for(int i=0 ; i<n ; i++){
        int mini = arr[i] ; 
        int count= 0 ;

        for(int j = 0 ; j<i ; j++){
            count+=arr[j] ;
        }
        for(int j=i+1 ; j<n ; j++){
            if(arr[j]>mini+k){
                count+=(arr[j]-(mini+k)) ; 
            }
        }

        if(count<=mid){
            return true ; 
        }
    }
    return false ; 
}
int minimumDeletions(string word, int k) {
    unordered_map<char , int>mp ; 
    for(int i = 0 ; i<word.size() ; i++){
        mp[word[i]]++ ; 
    }
    vector<int>res ; 
    for(auto i : mp){
        res.push_back(i.second) ; 
    }
    sort(res.begin() , res.end()) ; 
    int low = 0 ; 
    int high = word.size() ; 
    int ans = INT_MAX ; 
    while(low<=high){
        int mid = low+(high-low)/2 ; 
        if(isvalid(mid , res , k)){
            ans = mid ; 
            high = mid-1 ; 
        }
        else {
            low = mid+1 ; 
        }
    }
    return ans ; 
}