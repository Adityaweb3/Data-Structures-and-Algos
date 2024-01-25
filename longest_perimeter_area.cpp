// You are given an array of positive integers ‘ARR’ of size ‘N’. 
// The task is to return the largest perimeter of a triangle with a non-zero area, having any three elements of ‘ARR’ as its sides. 
// If it’s impossible to form such a triangle, return 0


#include <bits/stdc++.h> 
int maxPerimeterTriangle(vector<int>& nums, int n) {
    // Write your code here.
     sort(nums.begin() , nums.end()) ;
        for(int i = nums.size()-1 ; i>=2 ; i--){

            if(nums[i-1]+nums[i-2]>nums[i]){
                return nums[i-1]+nums[i-2]+nums[i] ;
            }
        }

        return 0 ; 
}