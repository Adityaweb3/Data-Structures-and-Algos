// Approach : 

// We maintain a single queue que.
// When pushing a new element, we first push it onto the queue. Then, we rotate the queue by pushing and popping elements until the newly pushed element becomes the front.
// Pop, top, and empty operations are straightforward, as they directly operate on the single queue.

class MyStack {
public:
  queue<int>q ; 
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x) ; 
        int n =q.size(); 
        for(int i = 0 ; i<n-1 ; i++){
            q.push(q.front()) ; 
            q.pop() ; 
        }
    }
    
    int pop() {
        int res = q.front() ; 
        q.pop() ; 
        return res ; 
    }
    
    int top() {
        return q.front() ;
    }
    
    bool empty() {
        return q.empty() ; 
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */