// Problem Link : https://neetcode.io/problems/jump-game

class Solution {
public:
    bool canJump(vector<int>& nums) {
       int n = nums.size()-1 ; 
        int lastPos = n ; 

        for(int i = n-1 ; i>=0 ; i--){
            if(i+nums[i]>=lastPos){
                lastPos = i ;
            }
        }

        return lastPos ==0 ; 
    }
};
