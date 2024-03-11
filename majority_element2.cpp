// Problem Link : https://leetcode.com/problems/majority-element-ii/description/

vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size() ; 
        int count1= 0 ; 
        int count2 = 0 ; 
        int element1= INT_MIN ; 
        int element2 = INT_MIN ; 

        for(auto i : nums){
            if(count1==0 && i!=element2){
                count1++ ; 
                element1=i ; 
            }

            else if(count2==0 && i!=element1){
                count2++ ; 
                element2= i ; 
            }

            else if(i==element1){
                count1++ ; 
            }

            else if(i==element2){
                count2++ ; 
            }
            else {
                count1-- ; 
                count2-- ; 
            }
        }
        vector<int>ans ; 
        count1= 0 ; 
        count2=0 ; 
        for(auto i :nums){
            if(i==element1){
                count1++ ; 
            }

            if(i==element2){
                count2++ ; 
            }
        }

        if(count1>=(int)(n/3)+1){
            ans.push_back(element1) ;
        }

        if(count2>=(int)(n/3)+1){
            ans.push_back(element2) ;
        }

        return ans ; 
    }