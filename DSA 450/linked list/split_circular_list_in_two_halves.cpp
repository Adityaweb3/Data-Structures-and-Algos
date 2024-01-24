// Given a Cirular Linked List of size N, split it into two halves circular lists. 
// If there are odd number of nodes in the given circular linked list then out of the resulting two halved lists, 
// first list should have one node more than the second list. 
// The resultant lists should also be circular lists and not linear lists.

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    Node *slow = head ; 
    Node *fast = head->next ; 
    
    while(fast!=head && fast->next!=head){
        slow = slow->next ;
        fast= fast->next->next;
        
    }
    
    *head1_ref = head ; 
    *head2_ref = slow->next ; 
    slow->next = *head1_ref ;
    Node *curr= *head2_ref ;
    while(curr->next!=head){
        curr = curr->next ;
        
    }
    curr->next= *head2_ref ;
}