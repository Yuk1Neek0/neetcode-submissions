class Solution {
public:
    int trap(vector<int>& height) {

        if(height.size() <= 2) return 0;

        int l = 0, r = height.size() - 1;
        int leftMax = height[l], rightMax = height[r];
        int res = 0;
        while(l < r){

            if(rightMax <= leftMax){

                if(rightMax > height[r]){

                    res += rightMax - height[r];

                }
                r --;
                rightMax = max(rightMax,height[r]);

            }
            else{
                if(leftMax > height[l]){

                    res += leftMax - height[l];

                }
                l ++;
                leftMax = max(leftMax,height[l]);
            }

        }

        return res;


    }
};
