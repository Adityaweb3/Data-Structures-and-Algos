// Given a sorted doubly linked list of positive distinct elements, 
// the task is to find pairs in a doubly-linked list whose sum is equal to given value target.

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        vector<pair<int,int>>ans ; 
        Node *start = head ; 
        Node *end = head ; 
        
        while(end->next !=NULL){
            end = end->next ;
        }
        
        while(start->data <end->data){
            int sum = start->data + end->data ; 
            
            if(sum>target){
                end = end->prev ; 
            }
            
            else if (sum<target){
                start = start->next ;
            }
            else {
                ans.push_back({start->data , end->data});
                
                end = end->prev ; 
                start = start->next ;
            }
        }
        
        return ans ;
    }