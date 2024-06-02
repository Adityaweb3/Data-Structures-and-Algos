// Problem link : https://leetcode.com/problems/count-days-without-meetings/description/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        
        vector<vector<int>> ans;
        
        int n=arr.size();
        
        int s=arr[0][0], e=arr[0][1];
        for(int i=1;i<n;i++){
            int si=arr[i][0], ei=arr[i][1];
            
            if(si>e){
                ans.push_back({s,e});
                s=si;
            }
            e=max(e,ei);
        }
        ans.push_back({s,e});
        
        return ans;
    }
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<vector<int>> ans = merge(meetings);
        
        int res = 0;
        for(vector<int> d : ans){
            int start = d[0], end = d[1];
            res += (end - start +1);
        } 
        
        return days-res;
    }
};