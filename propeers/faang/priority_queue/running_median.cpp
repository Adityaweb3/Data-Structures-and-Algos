// The median is the middle value in an ordered integer list. If the size of the list is even, 
// there is no middle value, and the median is the mean of the two middle values.
// For example, for arr = [2,3,4], the median is 3.
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
// Implement the MedianFinder class:
// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

class MedianFinder {
    priority_queue<int>maxpq ; 
    priority_queue<int , vector<int> , greater<int>>minpq ; 

public:
    MedianFinder() {

        
    }
    
    void addNum(int num) {
        if(maxpq.empty() || num<maxpq.top()){
            maxpq.push(num) ; 

        }

        else {
            minpq.push(num) ; 
        }

        if(maxpq.size()>minpq.size()+1){
            minpq.push(maxpq.top()) ; 
            maxpq.pop() ; 
        }

        else if(minpq.size()>maxpq.size()+1){
            maxpq.push(minpq.top()) ; 
            minpq.pop() ; 
        }
        
    }
    
    double findMedian() {
        if(maxpq.size()==minpq.size()){
            return (maxpq.top()+minpq.top())/2.0 ; 

        }

        else {
            if(minpq.size()>maxpq.size()){
                return minpq.top() ; 
            }

            else {
                return maxpq.top() ; 
            }
        }
        
    }
};