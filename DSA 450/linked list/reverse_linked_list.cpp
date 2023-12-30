/*Given a linked list of N nodes. The task is to reverse this list.*/

/*Iterative*/

struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        
        Node *prev = NULL ;
        Node *current = head ;
        Node *nextNode = NULL ;
        
        while(current!= NULL){
            
            nextNode = current->next ;
            current->next = prev ; 
            prev = current ;
            current = nextNode ;
            
            
            
        }
        
        return prev ;
        
        
    }

/*Recursive*/

struct Node *solve(Node *prev , Node *curr , Node *forward){
        if(curr==NULL){
            return prev ; 
        }
        
        forward = curr->next ; 
        curr->next = prev ; 
        
        solve(curr , forward , forward) ; 
    }
    struct Node* reverseList(struct Node *head)
    {
        
        Node *prev = NULL ; 
        Node *curr = head ; 
        
        Node *forward = curr->next ; 
        
        return solve(prev , curr , forward) ; 
    }