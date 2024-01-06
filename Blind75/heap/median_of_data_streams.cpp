// The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

// For example, for arr = [2,3,4], the median is 3.
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5. 
// Implement the MedianFinder class:

// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
	vector<int> result;
    priority_queue<int> maxpq; // Max heap for smaller half elements
    priority_queue<int, std::vector<int>,greater<int>> minpq; // Min heap for larger half elements
    
    for (int i = 0; i < n; ++i) {
        // Insert element into the appropriate heap
        if (maxpq.empty() || arr[i] <= maxpq.top()) {
            maxpq.push(arr[i]);
        } else {
            minpq.push(arr[i]);
        }
        
        // Balance the heaps
        if (maxpq.size() > minpq.size() + 1) {
            minpq.push(maxpq.top());
            maxpq.pop();
        } else if (minpq.size() > maxpq.size()) {
            maxpq.push(minpq.top());
            minpq.pop();
        }
        
        // Calculate median based on the sizes of the heaps
        if (maxpq.size() == minpq.size()) {
            result.push_back((maxpq.top() + minpq.top()) / 2);
        } else {
            result.push_back(maxpq.top());
        }
    }
    
    return result;
}
