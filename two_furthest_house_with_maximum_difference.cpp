// Problem link : https://leetcode.com/problems/two-furthest-houses-with-different-colors/description/

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int x = 0 ; 
        int y = colors.size() ; 

        for(int i = 0 ; i<colors.size() ; i++){
            if(colors[0]!=colors[i]){
                x = i ;
            }
        }

        for(int i =colors.size()-1 ; i>=0 ; i--){
            if(colors[colors.size()-1]!=colors[i]){
                y = (colors.size()-1)-i ; 
            }
        }

        return (x>y)?x : y ; 
    }
};