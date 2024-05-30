// Problem link : https://leetcode.com/problems/robot-bounded-in-circle/description/

class Solution {
public:
    bool isRobotBounded(string instructions) {
        char curr = 'N';
        int x = 0, y= 0;
        for(int i=0;i<instructions.length();i++){ 
            if(instructions[i] == 'G'){
                y += curr =='N' ? 1 : 0;
				y += curr =='S' ? -1 : 0;
				x += curr == 'E' ? 1 : 0;
				x += curr == 'W' ? -1 : 0;
            }
            else{
                char res = instructions[i];
                if(curr == 'N'){
                    curr= res == 'R' ? 'E' : 'W';
                }
                else if(curr == 'W'){
                    curr = res == 'R' ? 'N' : 'S';
                }
                else if(curr == 'S'){
                    curr = res == 'R' ? 'W' : 'E';
                }
                else{
                    curr = res == 'R' ? 'S' : 'N';
                }
            } 
            
        }
        
        if(x==0 && y==0 || curr!='N')
            return true;
        
        return false;
    }
};