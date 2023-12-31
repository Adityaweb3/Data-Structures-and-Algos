/*You have been given a text message. You have to return the Run-length Encoding of the given message.
Run-length encoding is a fast and simple method of encoding strings. 
The basic idea is to represent repeated successive characters as the character and a single count. 
For example, the string "aaaabbbccdaa" would be encoded as "a4b3c2d1a2".*/

#include <bits/stdc++.h> 
string encode(string &message)
{
    //   Write your code here.
    int n = message.length() ; 
    string ans = "" ; 
    int count = 1; 

    for(int i = 0 ; i<n-1 ; i++){
        if(message[i]==message[i+1]){
            count =count+1 ; 

        }

        else {
            ans+=message[i] ; 
            ans+=to_string(count) ; 
            count =1 ; 
        }


    }
    ans+=message[n-1] ; 
    ans+=to_string(count) ; 

    return ans ;

}