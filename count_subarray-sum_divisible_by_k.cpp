// Problem Link : https://leetcode.com/problems/subarray-sums-divisible-by-k/

 int subarraysDivByK(vector<int>& nums, int k) {
      int ans = 0;
      unordered_map<int,int>mp;
      int sum = 0;
      mp[0]++;
      for(auto x:nums)
      {
        sum+=x;
        if(mp[(sum%k+k)%k]>0)
        {
        ans+=mp[(sum%k+k)%k];
        }
        mp[(sum%k+k)%k]++;
      }
      return ans;  
    }