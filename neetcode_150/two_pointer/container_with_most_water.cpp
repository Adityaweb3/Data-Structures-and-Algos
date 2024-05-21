// Problem Link : https://neetcode.io/problems/max-water-container

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0 ;
        int right = heights.size()-1 ; 
        int maxi = 0 ; 

        while(left<=right){
            int area = min(heights[left] , heights[right])*(right-left) ; 
            maxi = max(maxi , area) ; 

            if(heights[left]<heights[right]){
                left++ ; 
            }
            else {
                right-- ; 
            }
        }

        return maxi ; 
    }
};
