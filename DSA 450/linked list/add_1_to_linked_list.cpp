// A number N is represented in Linked List such that each digit corresponds to a node in linked list. 
// You need to add 1 to it.

  Node *reverse(Node *head){
        Node *prev = NULL ; 
        Node *curr = head ; 
        Node *nextNode = NULL ; 
        
        while(curr!=NULL){
            nextNode = curr->next ; 
            curr->next = prev ; 
            prev = curr ; 
            curr = nextNode ; 
        }
        
        return prev ;
    }
    Node* addOne(Node *head) 
    {
        head = reverse(head);
        int carry =1 ; 
        Node *prev = NULL ; 
        Node *curr = head ;
        
        while(curr!=NULL){
            prev = curr ; 
            int num = curr->data+carry ;
            curr->data = num%10 ; 
            carry = num/10 ; 
            curr = curr->next ;
        }
        
        if(carry!=0){
            Node *car = new Node(1) ;
            prev->next = car ; 
            car->next = NULL ; 
        }
        
        head = reverse(head) ;
        return head ;
    }