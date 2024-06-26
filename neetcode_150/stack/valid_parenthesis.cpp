// Problem Link : https://neetcode.io/problems/validate-parentheses

class Solution {
public:
    bool isValid(string s) {
         stack<char> st;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        } else if (!st.empty() &&
                   ((s[i] == ')' && st.top() == '(') ||
                    (s[i] == '}' && st.top() == '{') ||
                    (s[i] == ']' && st.top() == '['))) {
            st.pop();
        } else {
            return false;
        }
    }

    return st.empty(); 
    }
};
