// Problem Link : https://leetcode.com/problems/k-radius-subarray-averages/description/

vector<int> getAverages(vector<int>& nums, int k) {
         int n = nums.size();
        
        if(k == 0)
            return nums;
    
        vector<int> res(n, -1);
        
        if(n < 2*k + 1)
            return res;
        
        vector<long long> pre(n, 0);
        pre[0] = nums[0];
        
        for(int i = 1; i<n; i++) {
            pre[i] = pre[i-1] + nums[i];
            
        }

        for(int i = k; i<n-k; i++) {
            
            int left  = i-k;
            int right = i+k;
            
            long long sum = pre[right];
            
            if(left > 0)
                sum -= pre[left-1];
            
            
            int avg = sum/(2*k+1);
            
            res[i] = avg;
            
            
        }
        
        return res;

    }