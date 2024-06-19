// Problem link : https://www.naukri.com/code360/problems/count-subarrays-with-given-xor_1115652

#include <bits/stdc++.h>

int subarraysXor(vector<int> &a, int k)
{
    
    int n = a.size(); 
    int r= 0;
    map<int, int> mp ;
    mp[r]++; 
    int count = 0;

    for (int i = 0; i < n; i++) {
        
        r = r ^ a[i];

        
        int x = r ^ k;

        
        count += mp[x];

        
        mp[r]++;
    }
    return count;
}