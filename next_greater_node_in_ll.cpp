// Problem Link : https://leetcode.com/problems/next-greater-node-in-linked-list/description/

class Solution {
public:
   ListNode *rev(ListNode *head){
    if(head==NULL || head->next==NULL){
        return head; 
    }

    ListNode *prev = NULL ; 
    ListNode *curr = head ; 
    ListNode *nextNode =NULL ; 

    while(curr!=NULL){
        nextNode = curr->next ; 
        curr->next = prev  ; 
        prev = curr ; 
        curr = nextNode; 
    }

    return prev ; 
   }
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ans ; 
        head = rev(head) ; 

        if(head==NULL){
            return ans ; 
        }

        ListNode *curr = head ; 

        stack<int>st ; 
        st.push(curr->val) ; 
        ans.push_back(0) ; 
        curr= curr->next ; 

        while(curr!=NULL){
            while(!st.empty() && st.top()<=curr->val){
            st.pop() ; 
        }

        int ng = st.empty()?0:st.top() ; 
        ans.push_back(ng) ; 
        st.push(curr->val) ;
        curr=curr->next ;  
        }
       reverse(ans.begin() , ans.end()) ; 
        return ans ; 
    }
};