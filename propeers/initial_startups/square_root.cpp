/*You are given a positive integer ‘n’.
Your task is to find and return its square root. 
If ‘n’ is not a perfect square, then return the floor value of sqrt(n).
*/

int floorSqrt(int n)
{
    // Write your code here.
    int low = 0 ; 
    int high = n ;
    while(low<=high){
        long long mid = (low+high)/2 ;
        long long val = (mid*mid) ;

        if(val<=n){
            low= mid+1 ;
        }

        else {
            high = mid-1;
        }
    }

    return high ;
}
