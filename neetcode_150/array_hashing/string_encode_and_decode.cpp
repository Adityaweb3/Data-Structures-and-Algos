// Problem Link : https://neetcode.io/problems/string-encode-and-decode

class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "" ; 
        for(auto str : strs){
            encoded+=to_string(str.length())+'#'+str ;
        }

        return encoded ; 
    }

    vector<string> decode(string s) {
        vector<string>ans ; 
        int i = 0 ; 
        while(i<s.length()){
            int pos = s.find('#' , i) ; 
            int len = stoi(s.substr(i, pos - i)) ; 
            i= pos+1 ; 
            ans.push_back(s.substr(i , len)) ; 
            i+=len ; 
        }

        return ans;
    }
};
