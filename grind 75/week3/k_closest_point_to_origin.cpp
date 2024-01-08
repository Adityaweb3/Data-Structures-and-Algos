// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, 
//return the k closest points to the origin (0, 0).

// The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

// You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans ; 
        priority_queue<pair<int , vector<int>>>pq ;

        for(int i = 0 ; i<points.size() ; i++){
            int temp = (points[i][0])*(points[i][0]) + (points[i][1])*(points[i][1]) ;

            pq.push({-temp , {points[i][0] , points[i][1]}}) ; 


        }
        while(k--){
           ans.push_back(pq.top().second) ; 
           pq.pop() ; 

        }

        return ans ; 


        
    }
};