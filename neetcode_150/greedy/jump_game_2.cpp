// Problem Link : https://neetcode.io/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        for(int i =0 ; i<nums.size()-1 ; i++){
            nums[i]= max(nums[i]+i , nums[i-1]) ; 

        }
        int jumps =0 ; 
        int i =0 ; 

        while(i<nums.size()-1){
            jumps++ ; 
            i = nums[i] ; 
        }

        return jumps ;
    }
};
