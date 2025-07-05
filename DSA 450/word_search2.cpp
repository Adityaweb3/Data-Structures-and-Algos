class Solution {
    public:
        struct trieNode {
            bool end ; 
            trieNode *children[26] ; 
            string word ; 
        } ; 
    
        trieNode *getNode(){
            trieNode * newNode = new trieNode() ; 
            newNode ->end = false ; 
            newNode->word = "" ; 
            for(int i = 0 ; i<26 ; i++){
                newNode->children[i]=NULL ; 
            }
            return newNode ; 
        } 
    
        void insert(trieNode *root , string &res){
            trieNode *temp = root ; 
            for(int i = 0 ; i<res.length() ; i++){
                if(temp->children[board[i][j]-'a']==NULL){
                    temp->children[board[i][j]-'a']=getNode() ; 
                }
                temp = temp->children[board[i][j]-'a'] ; 
            }
            temp->word = res ; 
            temp->end = true ; 
        }
    
        void solve(int i , )
    
        vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
            int n = board.size() ;
            int m = board[0].size() ; 
            vector<string>ans ; 
            trieNode *root = getNode() ; 
    
            for(auto i : words){
                insert(root , i) ; 
            }
            for(int i = 0 ; i<n ; i++){
                for(int j = 0 ; j<m ; j++){
                    if(root->children[board[i][j]-'a']!=NULL)){
                        solve(i , j , n , m , board , root , ans) ; 
                    }
                }
            }
            return ans ; 
    
        }
    };