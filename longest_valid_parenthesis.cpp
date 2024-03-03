// Problem Link : https://leetcode.com/problems/longest-valid-parentheses/description/

// if bracket is open then store it's index in stack . if bracket is closed then pop the top element and check if stack is empty 
// if stack is empty then just push the index or else find the max length .

int longestValidParentheses(string s) {
        stack<int>st ; 
        st.push(-1) ;
        int maxi = 0 ; 

        for(int i = 0 ; i<s.size() ; i++){
            if(s[i]=='('){
                st.push(i) ;
            }

            else {
                st.pop() ; 

                if(st.empty()){
                    st.push(i) ;
                }

                else {
                    maxi = max(maxi , i-st.top());
                }
            }
        }

        return maxi ;
    }