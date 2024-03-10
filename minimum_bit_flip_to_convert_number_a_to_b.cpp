// Problem Link : https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/

int minBitFlips(int start, int goal) {
        int ans = start^goal ; 
        return __builtin_popcount(ans);
}