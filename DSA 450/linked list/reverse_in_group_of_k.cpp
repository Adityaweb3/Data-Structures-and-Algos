// You are given a linked list of 'n' nodes and an integer 'k', where 'k' is less than or equal to 'n'.
// Your task is to reverse the order of each group of 'k' consecutive nodes, if 'n' is not divisible by 'k', 
// then the last group of nodes should remain unchanged.
// For example, if the linked list is 1->2->3->4->5, and 'k' is 3, we have to reverse the first three elements, 
// and leave the last two elements unchanged. Thus, the final linked list being 3->2->1->4->5.
// Implement a function that performs this reversal, and returns the head of the modified linked list.

Node* kReverse(Node* head, int k) {
    // Write your code here.
   if(head==NULL || k==1){
            return head ; 
        }

         int count = 0;
        Node* curr1 = head;
        
        
        while (curr1 != NULL) {
            count++;
            curr1 = curr1->next;
        }

        if (count < k) {
           
            return head;
        }

        Node *prev = NULL ; 
        Node *nextNode = NULL ; 
        Node *curr = head ; 

        for(int i = 0 ; i<k && curr!=NULL ; i++){
            nextNode = curr->next ; 
            curr->next = prev ; 
            prev = curr ; 
            curr = nextNode ; 
        }

        if(nextNode !=NULL){
            head->next = kReverse(nextNode, k) ;
              
            
        }

        return prev ;
}