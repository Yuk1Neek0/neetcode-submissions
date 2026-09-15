class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int l = 0, r = heights.size() - 1;

        int res = 0;

        while( l < r ){

            int v = min(heights[l],heights[r]) * abs(l - r);

            if(res < v) res = v;

            if( heights[l] < heights[r] ) l ++;
            else r --;

        }
        
        return res;
    }
};
