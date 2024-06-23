// Problem Link : https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/

  int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size() ; 
        multiset<int>st ; 

        int i = 0 ; 
        int j = 0 ; 
        int maxi = 0 ; 

        while(j<n){
            st.insert(nums[j]) ; 

            while(*st.rbegin()-*st.begin()>limit){
                st.erase(st.find(nums[i])) ; 
                i++ ; 
            }

            maxi = max(maxi , j-i+1) ;
            j++ ; 
        }

        return maxi ; 
    }