// Problem Link : https://leetcode.com/problems/design-circular-queue/description/

class Node{      //for creating singly linked list Node
    public:
    int data;
    Node* next;
    
    Node(int data){
        this->data = data;
        next = NULL;
    }
};
class MyCircularQueue {
public:
    
    int size, currSize = 0;
    Node* front = NULL;
    Node* rear = NULL;
    MyCircularQueue(int k) {
        size = k;
    }
    
    bool enQueue(int value) {
        if(isFull())    return 0;
        Node* newnode = new Node(value);
        if(front==NULL and rear==NULL){
            front = newnode;
            rear = newnode;
        }
        else{
            rear->next = newnode;
        }
        newnode->next = front;
        rear = newnode;
        currSize++;
        return 1;
    }
    
    bool deQueue() {
        if(isEmpty())   return 0;
        if(front == rear){
            front =NULL;
            rear = NULL;
        }
        else{
           front = front->next;
           delete rear->next;        // free the node, by deleting that node
           rear->next = front;
        }
               
        currSize--;
        return 1;
    }
    
    int Front() {
        if(isEmpty())   return -1;
        return front->data;
    }
    
    int Rear() {
        if(isEmpty())   return -1;
        return rear->data;
    }
    
    bool isEmpty() {
        return currSize==0;
    }
    
    bool isFull() {
        return currSize==size;
    }
};