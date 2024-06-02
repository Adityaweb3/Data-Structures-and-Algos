// Problem link : https://leetcode.com/problems/count-days-without-meetings/description/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        
        vector<vector<int>> ans;
        
        int n=arr.size();
        
        int start=arr[0][0], end=arr[0][1];
        for(int i=1;i<n;i++){
            int starti=arr[i][0], endi=arr[i][1];
            
            if(starti>end){
                ans.push_back({start,end});
                start=starti;
            }
            end=max(end,endi);
        }
        ans.push_back({start,end});
        
        return ans;
    }
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<vector<int>> ans = merge(meetings);
        
        int res = 0;
        for(auto i : ans){
            int start = i[0], end = i[1];
            res += (end - start +1);
        } 
        
        return days-res;
    }
};