// Queue is a linear data structure that follows the idea of First In First Out. 
// That means insertion and retrieval operations happen at opposite ends.
// Implement a simple queue using arrays.
// You are given 'query' queries which are either of the 2 types:
// 1 'e': Enqueue (add) element ‘e’ at the end of the queue.
// 2: Dequeue (retrieve) the element from the front of the queue. If the queue is empty, return -1.

class Queue {

	int front, rear;
	vector<int> arr;

public:
	Queue()
	{
		front = 0;
		rear = 0;
		arr.resize(100001);
	}

	// Enqueue (add) element 'e' at the end of the queue.
	void enqueue(int e)
	{
		// Write your code here.
		 if(rear == arr.size())return;

        else{

            arr[rear] = e;

          rear++;
		}


		
	}

	// Dequeue (retrieve) the element from the front of the queue.
	int dequeue()
	{
		// Write your code here.
		   if(front == rear)return -1;

        else{

            int element = arr[front];

            front++;

        return element;
		}
		
 
	}
};