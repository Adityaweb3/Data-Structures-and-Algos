// You are given an arbitrary linked list consisting of 'N' nodes having integer values. 
// You need to perform insertion sort on the linked list and print the final list in sorted order.
// In other words, you are given a singly linked list, you need to perform insertion sort on it.

 ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(10000) ;

        while(head){
            ListNode *next = head->next ; 
            ListNode *temp = dummy ; 

            while(temp->next && temp->next->val<head->val){
                temp = temp->next ;
            }
            head->next = temp->next ; 
            temp->next = head ;
            head = next ;
        }

        return dummy->next ;
        
    }