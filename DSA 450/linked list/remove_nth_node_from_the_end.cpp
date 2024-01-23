// Given the head of a linked list, 
// remove the nth node from the end of the list and return its head.

 ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return head; 
        }

        ListNode *fast = head ; 
        ListNode *slow = head ;
        for(int i = 0 ; i<n && fast!=NULL ; i++){
            fast =fast->next ; 
        }


        //if fast is at last node remove first node of linked list ; 

        
         if (fast == NULL) {
           return head->next;
        }


        while(fast!=NULL && fast->next!=NULL){
            slow= slow->next ; 
            fast = fast->next ; 
        }

        
        slow->next  = slow->next->next ;

        return head ;  
    

        
        
    }