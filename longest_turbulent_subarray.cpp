class Solution {
    public:
        int maxTurbulenceSize(vector<int>& arr) {
            int n = arr.size() ; 
            if(n==1){
                return 1 ; 
            }
            int i = 0 ; 
            int j=1 ; 
            int ans = 1 ; 
            int temp =1 ; 
            int symbol = -1 ; 
            while(j<n){
                if(arr[i]<arr[j] && symbol!=0){
                    symbol = 0 ; 
                    temp++ ; 
                    ans = max(ans , temp) ; 
                    i++ ; j++ ; 
                }
                else if (arr[i]>arr[j] && symbol!=1){
                    symbol =1 ; 
                    temp++ ; 
                    ans = max(ans , temp) ; 
                    i++ ; 
                    j++ ; 
                }
                else {
                    if(arr[i]==arr[j]){
                        i++ ; 
                        j++ ; 
                    }
                    temp =1 ; 
                    symbol= -1 ; 
                }
            }
            return ans ; 
        }
    };