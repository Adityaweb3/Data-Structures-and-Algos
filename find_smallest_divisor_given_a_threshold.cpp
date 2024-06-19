Problem Link : https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

bool possible(vector<int>&nums , int mid , int threshold){
    int ans =0 ; 

    for(auto i : nums){
        ans+= (i/mid)+((i % mid) != 0)  ; 
    }

    return (ans<=threshold) ; 
   }
    int smallestDivisor(vector<int>& nums, int threshold) {
       int low = 1; 
       int high = *max_element(nums.begin(), nums.end()); 

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (possible(nums, mid, threshold)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low;
    }