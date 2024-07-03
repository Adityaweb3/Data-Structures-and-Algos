// Problem Link : https://leetcode.com/problems/sum-of-subarray-minimums/

vector<int>preSmall(vector<int>&arr){
        int n = arr.size() ;
        vector<int>res(n) ;
        stack<int>st ; 

        for(int i = 0 ; i<n ; i++){
            if(st.empty()){
                res[i]=-1 ;
            }
            else {
                while(!st.empty() && arr[st.top()]>arr[i]){
                    st.pop() ;
                }

                res[i]= st.empty()?-1 : st.top() ;
            }
            st.push(i) ;
        }
        return res ; 
    }

    vector<int>nextSmall(vector<int>arr){
        int n = arr.size() ;
        vector<int>res(n) ; 
        stack<int>st ; 
        for(int i = n-1 ; i>=0 ; i--){
            if(st.empty()){
                res[i]=n ;
            }
            else {
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop() ;
                }
                res[i]= st.empty() ? n : st.top() ;
            }
            st.push(i) ;
        }
        return res ; 
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n =arr.size() ;
        vector<int>res1 = preSmall(arr) ; 
        vector<int>res2 = nextSmall(arr) ;
        int M = 1e9+7 ; 
        long long sum = 0 ; 
        for(int i = 0 ; i<n ; i++){
            long long d1 = i-res1[i] ; 
            long long d2 =res2[i]-i ; 

            long long totals = d1*d2 ; 
            long long sumi = arr[i]*totals ; 
            sum = (sum +sumi)%M ; 
        }

        return sum ;

    }