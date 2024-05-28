// Problem Link : https://leetcode.com/problems/bulls-and-cows/description/

class Solution {
public:
    string getHint(string secret, string guess) {
       int countB = 0 ; 
       unordered_map<char , int>guessM ; 
       int n = secret.size() ; 

       for(int i = 0 ; i<n ; i++){
        if(secret[i]==guess[i]){
            countB++ ; 
        }
        else {
            guessM[guess[i]]++ ; 
        }
       }

       int countC = 0 ; 
       for(int i = 0 ; i<n ; i++){
        if(secret[i]!=guess[i] && guessM[secret[i]]>0){
            countC++ ; 
            guessM[secret[i]]-- ; 
        }
       }

       string ans = to_string(countB)+"A"+to_string(countC)+"B" ; 
       return ans ;

    }
};