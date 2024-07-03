// Problem Link : https://www.naukri.com/code360/problems/sum-of-minimum-and-maximum-elements-of-all-subarrays-of-size-k_1171047

#include <bits/stdc++.h> 
long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
	// Write your code here.
	long long sum = 0 ; 
	deque<int>S(k) , G(k) ; 
	int i = 0 ;
	for(i=0; i<k ;i++){
		while(!S.empty() && nums[S.back()]>=nums[i]){
			S.pop_back() ;
		}

		while(!G.empty() && nums[G.back()]<=nums[i]){
			G.pop_back() ;
		}
		S.push_back(i) ; 
		G.push_back(i) ;
	}

	for( ; i<n ; i++){
		sum+=nums[S.front()] + nums[G.front()] ; 

		while(!S.empty() && S.front()<=i-k){
			S.pop_front() ;
		}
		while(!G.empty() && G.front()<=i-k){
			G.pop_front();
		}

		while(!S.empty() && nums[S.back()]>=nums[i]){
			S.pop_back() ;
		}

		while(!G.empty() && nums[G.back()]<=nums[i]){
			G.pop_back() ;
		}

		S.push_back(i) ; 
		G.push_back(i); 
	}
	sum += nums[S.front()] + nums[G.front()];
	return sum ; 

}
