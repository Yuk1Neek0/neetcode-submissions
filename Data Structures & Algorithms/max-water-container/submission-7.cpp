class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int l = 0, r = heights.size() - 1;
        int maxarea = 0;
        while( l < r ){
            
            int area = (r - l) * min(heights[r] , heights[l]);
            if( maxarea < area ) maxarea = area; 

            if(heights[l] < heights[r]) l++;
            else r--;
        }

        return maxarea;
    }
};
