// Problem Link : https://leetcode.com/problems/majority-element/

int majorityElement(vector<int>& nums) {
        int count = 0 ; 
        int major = 0 ; 

        for(int num : nums){
            if(count==0){
                major = num ; 
            }

            if(num==major){
                count++ ; 
            }
            else {
                count-- ; 
            }
        }

        return major ; 
    }