/*Reverse the given string word-wise. The last word in the given string should come at 1st place, 
the last-second word at 2nd place, and so on. Individual words should remain as it is.*/

#include <iostream>
using namespace std;

string reverseStringWordWise(string input)
{
    //Write your code here
    int n = input.size() ; 
    int i = 0 ; 
    string ans = "" ; 

    while(i<n){
        string temp = "" ; 
        while(input[i]==' ' && i<n){
            i++ ; 

        }
        while(input[i]!=' ' and i<n){
            temp+=input[i] ; 
            i++ ; 
        }

        if(temp.size()>0){
            if(ans.size()==0){
                ans = temp ; 
            }
            else {
                ans = temp + ' ' + ans ; 
            }
        }
    } 

    return ans ; 
    
}

int main()
{
    string s;
    getline(cin, s);
    string ans = reverseStringWordWise(s);
    cout << ans << endl;
}