// Problem Link : https://leetcode.com/problems/middle-of-the-linked-list/description/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head ; 
        }

        ListNode *fast = head ; 
        ListNode *slow = head ; 

        while(fast!=NULL && fast->next !=NULL){
            fast = fast->next->next ; 
            slow = slow->next ; 
        }

        return slow ; 
    }
};