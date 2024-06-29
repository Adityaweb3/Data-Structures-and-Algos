// Problem link : https://www.interviewbit.com/problems/rotate-list/

ListNode* Solution::rotateRight(ListNode* A, int B) {
   ListNode *start = A ; 
   
   if(A==NULL){
       return A ;
   }
   
   int len =1 ; 
   
   while(start->next!=NULL){
       len++ ; 
       start = start->next ; 
   }
   
   start->next = A ; 
   
   for(int i = 0 ; i<len-(B%len) ; i++){
       start = start->next ; 
       A = A->next ;
   }
   
   start->next = NULL ;
   return A ;
}
