/*move alll zeros to end without canging order of non zeros elements */


#include <bits/stdc++.h> 
void pushZerosAtEnd(vector<int> &arr) 
{
	// Write your code here.
	int count = 0 ;
	int n = arr.size() ;  

	for(int i = 0 ; i<n ; i++){
		if(arr[i]!=0){
			swap(arr[i], arr[count]) ; 
			count++ ; 
		}
	}
}
