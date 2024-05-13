// Problem Link : https://leetcode.com/problems/max-chunks-to-make-sorted/description/

int maxChunksToSorted(vector<int>& arr) {
        int p=arr[0];
        int n = arr.size() ;
   int cnt=0;
   for(int i=0;i<n;i++)
   {
       if(p<arr[i])
       {
           p=arr[i];
       }
       if(p==i)
       {
           cnt++;
       }
   }
   return cnt;
    }