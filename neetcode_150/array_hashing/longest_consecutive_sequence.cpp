// Problem Link : https://neetcode.io/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size() ; 
        unordered_set<int>s ; 

        for(auto num : nums){
            s.insert(num) ; 
        }

        int ans = 0 ; 

        for(auto num : nums){
            if(!s.count(num-1)){
                int curr = num ; 
                int maxi = 1 ; 

                while(s.count(curr+1)){
                    maxi++ ; 
                    curr++ ; 
                }

                ans = max(ans , maxi) ; 
            }
        }

        return ans ; 
    }
};
