/*You are given an array/list ‘ARR’ consisting of ‘N’ distinct integers arranged in ascending order. Y
ou are also given an integer ‘TARGET’.
 Your task is to count all the distinct pairs in ‘ARR’ such that their sum is equal to ‘TARGET’.
*/

#include <bits/stdc++.h> 
int pairSum(vector<int> &arr, int n, int target){
	// Write your code here.
	int i = 0 ; 
	int j = n-1 ; 
	int count = 0 ;

	while(i<j){
		if(arr[i]+arr[j]==target){
			count++ ; 
		}

		if(arr[i]+arr[j]<target){
			i++ ; 
		}

		else {
			j-- ; 
		}
	}

	if(count==0){
		return -1 ;
	}

	return count ; 
}