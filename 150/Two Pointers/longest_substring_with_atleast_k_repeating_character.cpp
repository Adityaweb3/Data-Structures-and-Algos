// Problem link : https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/

int longest(string s, int k , int start , int end){
    if(end-start+1<k){
        return 0 ; 
    }

    int count[256]={0} ; 
    for(int i = start ; i<end ; i++){
        count[s[i]-'a']++; 
    }

    for(int i= start ; i<end ; i++){
        if(count[s[i]-'a']<k){
            int left = longest (s , k , start , i) ; 
            int right= longest(s , k , i+1 , end) ; 
            return max(left , right) ;
        } 
    }

    return end-start ; 
   }
    int longestSubstring(string s, int k) {
        return longest(s , k , 0 , s.length()) ; 
    }