// Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. 
// The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 
// 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

Node* sortList(Node *head){
    // Write your code here.
    int countZero = 0 ; 
    int countOne = 0 ; 
    int countTwo = 0 ; 

    Node *curr = head ; 

    while(curr!=NULL){
        if(curr->data==0){
            countZero++ ; 
        }

        if(curr->data==1){
            countOne++ ; 
            
        }

        if(curr->data==2){
            countTwo++ ;
        }
        curr = curr->next ;
    }


    curr = head ; 

    while(curr!=NULL){
        while(countZero){
            curr->data = 0 ; 
            curr =curr->next ; 
            countZero-- ;
        }

        while(countOne){
            curr->data = 1; 
            curr = curr->next ; 
            countOne-- ;
        }

        while(countTwo){
            curr->data =2 ; 
            curr = curr->next ; 
            countTwo-- ;
        }
    }

    return head ;
}