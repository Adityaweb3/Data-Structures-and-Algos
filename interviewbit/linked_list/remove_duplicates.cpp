// Problem Link :https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/

ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *curr = A ; 
    ListNode *temp = new ListNode(0) ; 
    temp->next =curr ; 
    ListNode *prev = temp ; 
    
    while(curr && curr->next){
        if(curr->next!=NULL && curr->val == curr->next->val){
            while(curr->next && curr->val == curr->next->val){
                curr= curr->next ;
            }
            prev->next = curr->next ;
            
        }
        else {
            prev = prev->next ; 
        }
        curr = curr->next ; 
    }
    return temp->next ;
}