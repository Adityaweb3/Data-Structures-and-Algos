Given a linked list of N nodes such that it may contain a loop.
A loop here means that the last node of the link list is connected to the node at position X(1-based index). 
If the link list does not have any loop, X=0.
Remove the loop from the linked list, if it is present, i.e. unlink the last node which is forming the loop.

void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        if(head==NULL || head->next==NULL){
            return ;
        }
        Node *fast  = head ; 
        Node *slow = head ; 
        
        while(fast && fast->next){
            slow = slow->next ; 
            fast = fast ->next->next ; 
            
            if(fast==slow){
                break ;
            }
        }
        
        if(fast==NULL || fast->next==NULL){
            return ; 
        }
        
        slow = head ; 
        
        if(slow=fast){
            while(fast->next!=slow){
                fast = fast->next ;
            }
        }
        
        else {
            while(fast->next!=slow->next){
                fast = fast->next ; 
                slow = slow->next ; 
            }
        }
        
        fast->next = NULL ; 
        
        return ;
    }