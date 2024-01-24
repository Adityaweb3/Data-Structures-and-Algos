// Given two decimal numbers represented by two linked lists of size N and M respectively. 
// The task is to return a linked list that represents the sum of these two numbers.

Node <int>*reverse(Node<int>*root){
    if(root==NULL || root->next==NULL){
        return root ; 
    }
    Node <int>*prev = NULL ; 
    Node <int>*curr = root ; 
    Node <int>*nextNode = NULL ;

    while(curr!=NULL){
        nextNode = curr->next ; 
        curr->next = prev ; 
        prev = curr ; 
        curr = nextNode ; 
    }

    return prev ;
}

Node<int>* addTwoLists(Node<int>* first, Node<int>* second) {
    // Write your code here.
    first = reverse(first) ;
    second = reverse(second) ; 
    int c = 0 ; 
    int s = 0 ; 

    Node<int>*temp ;

    Node <int>*res = NULL ; 
    Node <int>*curr = NULL ; 

    while(first!=NULL || second !=NULL){
        s = c+(first ? first->data :0) + (second ? second->data : 0) ; 
        c = (s>=10) ? 1 : 0 ; 
        s = s%10 ; 

        temp = new Node<int>(s) ;

        if(res==NULL){
            res = temp ; 
        }
        else {
            curr->next = temp ;
        }
        curr = temp ; 

        if(first) {
                    first = first->next ;
                }
                
        if(second){
                    second = second->next ;
                }
    }

    if(c>0){
        Node<int>*car = new Node<int>(c) ; 
        curr->next = car ; 
        car->next = NULL ;
    }

    res = reverse(res) ; 

    return res ;
}