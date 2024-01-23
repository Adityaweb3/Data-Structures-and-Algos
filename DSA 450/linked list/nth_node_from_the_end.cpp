// Given a linked list consisting of L nodes and given a number N. 
// The task is to find the Nth node from the end of the linked list.

 int getNthFromLast(Node *head, int n)
    {
           // Your code here
           if(head==NULL) return -1;
           Node *fast=head,
           Node *slow=head;
           
           for(int i=0;i<n;i++){
               if(fast==NULL) 
               return -1;
               fast=fast->next;
           }
           while(fast!=NULL){
               fast=fast->next;
               slow=slow->next;
           }
           return slow->data;
    }