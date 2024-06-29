// Problem Link : https://www.interviewbit.com/problems/palindrome-list/

ListNode *reverse(ListNode *head){
     if(head==NULL || head->next==NULL){
         return head ;
     }
     ListNode *prev = NULL ; 
     ListNode *curr = head ; 
     ListNode *nextNode = NULL ;
     
     while(curr){
         nextNode = curr->next ; 
         curr->next = prev ; 
         prev = curr ; 
         curr = nextNode ; 
     }
     return prev ;
 }
int Solution::lPalin(ListNode* A) {
    if (A == NULL || A->next == NULL) {
        return true;
    }

    ListNode *slow = A;
    ListNode *fast = A;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *secondHalf = reverse(slow);

    
    ListNode *firstHalf = A;
    ListNode *secondHalfCopy = secondHalf; 

    while (secondHalf) {
        if (firstHalf->val != secondHalf->val) {
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }


    return true;
}