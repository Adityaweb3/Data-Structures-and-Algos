// Problem Link : https://neetcode.io/problems/evaluate-reverse-polish-notation

static unordered_set<string> operations({"+", "-", "*", "/"});

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto t : tokens) {
            if (operations.find(t) == operations.end()) st.push(stoi(t));
            else {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                if (t == "+") st.push(a + b);
                else if (t == "-") st.push(a - b);
                else if (t == "*") st.push(a * b);
                else st.push(a / b);
            }
        }
        return st.top();
    }
};
