/*You are given an array ‘ARR’ of size ‘N,’ and you have to tell the minimum number of elements 
that need to be removed such that the array contains all distinct elements. More formally, 
there should not be any ‘I’ and ‘J’ such that ‘I’ != ‘J’ and ‘ARR’[‘I’] = ‘ARR’[‘J’].
*/

#include <bits/stdc++.h> 
int minElementsToRemove(vector<int> &arr)
{
	// Write your code here.
	int n = arr.size() ; 
	unordered_map<int, int>mp ; 
	int count = 0 ; 

	for(int i = 0 ; i<n ; i++){
		mp[arr[i]]++ ; 
	}

	for(auto i:mp){
		if(i.second >1){
			count+=i.second-1 ; 
		}
	}

	return count ; 
}