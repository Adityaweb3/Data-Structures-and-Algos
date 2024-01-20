// A sorted(in ascending order) array A[ ] with distinct elements is rotated at some unknown point, 
// the task is to find the minimum element in it.

int findMin(vector<int>& arr)
{
	// Write your code here.
	int low = 0 ; 
	int high = arr.size() -1 ;
	int ans = INT_MAX ;

	while(low<=high){
		int mid = low + (high-low)/2 ;

		if(arr[low]<=arr[high]){
			ans = min(ans , arr[low]) ;
			break ;
		}

		if(arr[low] <=arr[mid]){
			ans = min(ans , arr[low]);
			low =  mid+1 ;
		}

		else {
			high = mid-1 ;
			ans = min(ans , arr[mid]) ;
		}
	}

	return ans ;
}