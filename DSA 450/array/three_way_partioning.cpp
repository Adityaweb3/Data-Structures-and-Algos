// Problem Link : https://www.geeksforgeeks.org/problems/three-way-partitioning/1
 //that array is divided into three parts.

 
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        // code here 
       int n = array.size();
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high) {
        if (array[mid] < a) {
            swap(array[mid], array[low]);
            low++;
            mid++;
        } else if (array[mid] >= a && array[mid] <= b) {
            mid++;
        } else {
            swap(array[mid], array[high]);
            high--;
           
        }
    }
    }