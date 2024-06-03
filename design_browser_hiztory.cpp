// Problem link : https://leetcode.com/problems/design-browser-history/

class Node {
    public : 
    string value ; 
    Node *next ; 
    Node *prev ; 

    Node(string res){
        value = res ; 
        next = NULL ;
        prev =NULL ; 
    }
};


class BrowserHistory {
public:

    Node *head , *curr ; 
    BrowserHistory(string homepage) {
        head = new Node(homepage) ; 
        curr=head ; 
    }
    
    void visit(string url) {
        curr->next = new Node (url) ; 
        curr->next->prev = curr ; 
        curr = curr->next ; 
    }
    
    string back(int steps) {
        while(steps-->0 && curr->prev!=NULL){
            curr=curr->prev ; 
        }
        return curr->value ;
    }
    
    string forward(int steps) {
        while(steps-->0 && curr->next!=NULL){
            curr=curr->next ; 
        }

        return curr->value ; 
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */