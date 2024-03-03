// Problem Link : https://leetcode.com/problems/partition-list/

 ListNode* partition(ListNode* head, int x) {
        vector<int>v1 ; 
        vector<int>v2 ; 

        ListNode *temp = head ; 

        while(temp!=NULL){
            if(temp->val<x){
                v1.push_back(temp->val) ; 
                temp = temp->next ; 
            }

            else {
                v2.push_back(temp->val); 
                temp = temp->next ; 
            }
        }

        temp = head ; 

        while(temp!=NULL){
            for(auto i : v1){
                temp->val = i ; 
                temp = temp->next ; 
            }

            for(auto i : v2){
                temp->val = i;
                temp = temp->next ;
            }
        }

        return head ;
    }