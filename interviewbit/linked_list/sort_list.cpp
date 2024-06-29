// Problem link : https://www.interviewbit.com/problems/sort-list/

ListNode *mergeList(ListNode *A , ListNode *B){
    ListNode *temp = new ListNode(0) ; 
    ListNode *curr = temp ; 
    
    while(A && B){
        if(A->val<=B->val){
            curr->next = A ; 
            A = A->next ;
        }
        else {
            curr->next = B ; 
            B = B->next ; 
        }
        curr = curr->next ;
    }
    
    if(A){
        curr->next = A ;
        A = A->next ;
    }
    if(B){
        curr->next = B ;
        B = B->next ;
    }
    
    return temp->next ; 
}
ListNode* Solution::sortList(ListNode* A) {
    if (A == NULL || A->next == NULL) {
        return A;
    }

    ListNode *temp = NULL;
    ListNode *slow = A;
    ListNode *fast = A;

    while (fast && fast->next) {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    temp->next = NULL;  // Split the list into two halves

    ListNode *l1 = sortList(A);
    ListNode *l2 = sortList(slow);

    return mergeList(l1, l2);
}
