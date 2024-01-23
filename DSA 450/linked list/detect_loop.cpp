// Given a linked list of N nodes. The task is to check if the linked list has a loop. 
// Linked list can contain self loop.

bool detectCycle(Node *head)
{
	//	Write your code here
    if(head==NULL){
        return false ; 
    }

    Node *fast = head ; 
    Node *slow = head ; 

    while(fast!=NULL && fast->next !=NULL){
        slow = slow->next ; 
        fast = fast->next->next ; 

        if(fast==slow){
            return true ; 

        }
            
    }

    return false ;
}