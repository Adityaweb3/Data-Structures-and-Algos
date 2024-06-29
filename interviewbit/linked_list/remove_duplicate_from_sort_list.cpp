// Problem Link : https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/

ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A==NULL || A->next==NULL){
        return A ;
    }
    ListNode *curr= A ; 
    
    while(curr->next!=NULL){
        if(curr->val ==curr->next->val){
            curr->next = curr->next->next ; 
        }
        else {
            curr= curr->next ; 
        }
    }
    
    return A ;
}
