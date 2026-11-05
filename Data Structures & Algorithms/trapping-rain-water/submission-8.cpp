class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2) return 0;
        int maxleft = height[0];
        int maxright = height[height.size() - 1];

        int l = 0, r = height.size() - 1;
        int res = 0;
        while(l <= r){

            if(maxleft < maxright){

                if(height[l] < maxleft){

                    res += maxleft - height[l];

                }
                else{

                    maxleft = height[l];

                }
                l ++;

            }
            else{

                if(height[r] < maxright){

                    res += maxright - height[r];

                }
                else{

                    maxright = height[r];

                }
                r --;


            }

        } 
        return res;
    }
};
