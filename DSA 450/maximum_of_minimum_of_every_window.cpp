// Problem link : https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1

vector<int>presmall(vector<int>&arr){
    int n = arr.size() ; 
    vector<int>pre(n) ; 
    stack<int>st ;
    st.push(-1) ; 
    for(int i = 0 ; i<n; i++){
        while(st.top()!=-1 && arr[st.top()]>=arr[i]){
            st.pop() ; 
        }
        pre[i] = st.top() ; 
        st.push(i) ; 
    }
    return pre ; 
}
vector<int>nextsmall(vector<int>&arr){
    int n = arr.size() ; 
    vector<int>next(n) ; 
    stack<int>st ; 
    st.push(n) ; 
    for(int i = n-1 ; i>=0 ; i--){
        while(st.top()!=n && arr[st.top()]>=arr[i]){
            st.pop() ; 
        }
        next[i] = st.top() ; 
        st.push(i) ; 
    }
    return next ; 
}
vector<int> maxOfMins(vector<int>& arr) {
    // Your code here
    int n = arr.size() ; 
    vector<int>next(n) ; 
    vector<int>pre(n) ; 
    next = nextsmall(arr) ; 
    pre = presmall(arr) ; 
    vector<int>ans(n , 0) ; 
    for(int i = 0 ; i<n ; i++){
        int maxi = next[i]-pre[i]-1 ; 
        ans[maxi-1]= max(ans[maxi-1] , arr[i]) ; 
    }
    for(int i = n-2 ; i>=0 ; i--){
        ans[i] = max(ans[i] , ans[i+1]) ; 
    }
    return ans ; 
    
}