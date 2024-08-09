// Problem link : https://leetcode.com/problems/spiral-matrix-iv/

vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m , vector<int>(n , -1)) ; 

        int rs = 0 ; 
        int re = m-1 ; 
        int cs = 0 ; 
        int ce = n-1; 
        ListNode *temp = head ; 

        while(rs<=re && cs<=ce && temp!=NULL){
            for(int i = cs ; i<=ce && temp ; i++){
                ans[rs][i]= temp->val ; 
                temp = temp->next ; 
            }

            rs++ ; 

            for(int i = rs ; i<=re && temp ; i++){
                ans[i][ce]= temp->val ; 
                temp= temp->next ; 
            }

            ce-- ; 

            if(rs<=re){
                for(int i =ce ; i>=cs && temp ; i--){
                    ans[re][i]=temp->val ; 
                    temp= temp->next ; 
                }
                re-- ; 
            }

            if(ce>=cs){
                for(int i = re ; i>=rs && temp ; i--){
                    ans[i][cs]= temp->val ; 
                    temp = temp->next ; 
                }

                cs++ ; 
            }
        }

        return ans ; 
    }