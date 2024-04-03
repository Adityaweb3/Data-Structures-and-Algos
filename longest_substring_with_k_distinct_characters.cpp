// Problem Link : https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

 int longestKSubstr(string s, int k) {
    // your code here
    int l=0,r=0,maxLen=-1;
      map<char,int>mp;
      while(r<s.size()) {
          mp[s[r]]++;
          if(mp.size()>k) {
              mp[s[l]]--;
              if(mp[s[l]]==0) mp.erase(s[l]);
              l++;
          }
          if(mp.size()==k) {
              maxLen = max(maxLen,r-l+1);
          }
          r++;
      }
      return maxLen;
    }