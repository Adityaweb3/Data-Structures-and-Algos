// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s ; 
        int ans = 0;
        for(auto i : nums){
            s.insert(i) ;
        }
        
        for(auto num : nums){
            if(!s.count(num-1)){
                int currNum = num ;
                int curr = 1 ;

                while(s.count(currNum+1)){
                    currNum +=1 ; 
                    curr += 1;
                }

                ans = max(ans , curr) ;
            }
        }

        return ans ;
    }
};