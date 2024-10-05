// problem link : https://leetcode.com/problems/alphabet-board-path/

class Solution {
public:
    string alphabetBoardPath(string target) {
        string ans;
		int x = 0, y = 0;
		for (auto ch : target) 
        {
			int x1 = (ch - 'a') % 5 , y1 = (ch - 'a') / 5;
			ans += string(max(0, y - y1), 'U') + string(max(0, x - x1), 'L') + string(max(0, y1 - y), 'D') + string(max(0, x1 - x), 'R') + "!";
			x = x1, y = y1;
		}
		return ans;
    }
};