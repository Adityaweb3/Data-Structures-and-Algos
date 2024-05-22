// Problem Link : https://neetcode.io/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans ; 
        int n = temperatures.size() ; 
        stack<int>st ; 
        st.push(n-1) ; 
        ans.push_back(0) ; 

        for(int i = n-2 ; i>=0 ; i--){
            while(!st.empty() && (temperatures[st.top()]<=temperatures[i])){
                st.pop() ; 
            }

            int ng= st.empty()?0 : st.top()-i ; 
            ans.push_back(ng) ; 
            st.push(i) ; 
        }

        reverse(ans.begin() , ans.end()) ; 
        return ans ; 
    }
};
