// Given an unsorted linked list of N nodes. 
// The task is to remove duplicate elements from this unsorted Linked List. 
// When a value appears in multiple nodes, the node which appeared first should be kept, 
// all others duplicates are to be removed.

 Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     unordered_set<int>s ;
     Node *prev = NULL ;
     Node *curr = head ;
     
     
     
     if(head ==NULL){
         return head ;
     }
     
     
     while(curr!=NULL){
         if(s.find(curr->data)!=s.end()){
             prev->next = curr->next ;
             delete(curr);
         }
         
         else {
             s.insert(curr->data) ;
             prev = curr ;
             
         }
         
         curr = prev->next ;
     }
     
     return head ;
     
     
    }
