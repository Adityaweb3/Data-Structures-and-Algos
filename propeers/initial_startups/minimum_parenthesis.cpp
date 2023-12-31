/*Given a string "pattern", which contains only two types of characters ‘(’, ‘)’.

Your task is to find the minimum number of parentheses either ‘(’, ‘)’ 
we must add the parentheses in string ‘pattern’ and the resulted string is valid.
Condition for valid string-
Every opening parenthesis ‘(’ must have a correct closing parenthesis ‘)’.
Example - ‘(()(()))’, ‘()()()’, ‘((()))’ are valid string, and ‘(((’, ‘(()’, ‘)(())’ are invalid string.*/

#include <bits/stdc++.h> 
int minimumParentheses(string pattern) {
    // Write your code here.
    // pattern is the given string.
    int open = 0 ; 
    int close = 0 ; 

    for(int i = 0 ; i<pattern.length() ; i++){
        if(pattern[i]=='('){
            open++ ; 
        }

        else {
            if(open==0){
                close++ ;
            }
            else {
                open-- ; 
            }
        }
    }

    return (open+close) ; 
}