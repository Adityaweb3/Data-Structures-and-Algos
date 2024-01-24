// Given a doubly linked list of n elements. Your task is to reverse the doubly linked list in-place.

Node *reverseDLL(Node *ead){
    if(head==NULL || head-.next==NULL){
        return head ;
    }

    Node *prev = NULL ; 
    Node *curr = head ;
    
    while(curr!=NULL){
        prev = curr->prev ; 
        curr->prev = curr->next ; 
        curr->next = prev ; 
        curr =curr->prev ; 
    }

    return prev->prev ;
}