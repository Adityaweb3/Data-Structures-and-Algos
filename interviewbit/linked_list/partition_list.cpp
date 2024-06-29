// Problem Link : https://www.interviewbit.com/problems/partition-list/

ListNode* Solution::partition(ListNode* head, int x) {
    ListNode *temp = head ; 
    ListNode *dummy = new ListNode (-1) ; 
    ListNode *ans = dummy ; 
    
    while(temp){
        if(temp->val<x){
            dummy->next = new ListNode(temp->val) ; 
            dummy = dummy->next ;
        }
        temp = temp->next ;
    }
    temp = head ; 
    while(temp){
        if(temp->val>=x){
            dummy->next = new ListNode (temp->val) ; 
            dummy = dummy->next ;
        }
        temp = temp->next ;
    }
    
    return ans->next ;
}
