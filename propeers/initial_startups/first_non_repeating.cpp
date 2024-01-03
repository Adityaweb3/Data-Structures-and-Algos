// Ninja is now bored with numbers and is now playing with characters but hates 
// when he gets repeated characters. Ninja is provided a string, and 
// he wants to return the first unique character in the string.
// The string will contain characters only from the English alphabet set, 
// i.e., ('A' - 'Z') and ('a' - 'z'). If there is no non-repeating character, 
// print the first character of the string. If there is no non-repeating character, 
// return the first character of the string.

#include <bits/stdc++.h> 
char firstNonRepeatingCharacter(string str) {

  // Write your code here
  unordered_map<char, int> charCount;

    
    for (char ch : str) {
        charCount[ch]++;
    }

   
    for (char ch : str) {
        if (charCount[ch] == 1) {
            return ch; 
        }
    }

   
    if (!str.empty()) {
        return str[0];
    }

    
    return '\0';
  


}
