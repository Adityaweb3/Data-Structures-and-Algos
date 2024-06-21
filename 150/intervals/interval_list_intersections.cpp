// Problem Link : https://leetcode.com/problems/interval-list-intersections/

 vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0 ; 
        int j = 0 ; 
        vector<vector<int>>ans ; 
        while(i<firstList.size() && j<secondList.size()){
            int l = max(firstList[i][0] , secondList[j][0]) ; 
            int r = min(firstList[i][1] , secondList[j][1]) ; 
            if(l<=r){
                ans.push_back({l,r}); 
            }
            if(firstList[i][1]<=secondList[j][1]){
                i++ ; 
            }
            else {
                j++ ; 
            }
        }

        return ans ; 
    }