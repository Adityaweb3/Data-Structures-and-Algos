// Problem Link : https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head){
            return NULL ; 
        }

        ListNode *slow = head ; 
        ListNode *fast = head ; 
        ListNode *prev = NULL ; 

        while(fast && fast->next){
            prev = slow ; 
            slow = slow->next ; 
            fast = fast->next->next  ;
        }

        TreeNode *root= new TreeNode(slow->val) ; 

        if(slow== head){
            return root ; 
        }

        prev->next = NULL ; 
        root->left = sortedListToBST(head) ; 
        root->right = sortedListToBST(slow->next) ; 

        return root ; 
    }
};