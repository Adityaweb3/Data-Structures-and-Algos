// Problem Link : https://www.naukri.com/code360/problems/find-kth-row-of-pascal-s-triangle_1082551

#include <bits/stdc++.h> 
vector<long long int> kthRow(int k) 
{
	// Write your code here.
	vector<long long>ans ; 
	long long res =1 ; 
	ans.push_back(res) ; 

	for(int i =1 ; i<k ; i++){
		res*=(k-i) ; 
		res/=i ; 
		ans.push_back(res) ; 
	}

	return ans ; 
} 