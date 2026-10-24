class Solution {
public:
    int trap(vector<int>& height) {

        if(height.size() <= 2) return 0;
        vector<int> maxleft(height.size());
        vector<int> maxright(height.size());
        maxleft[0] = 0;
        maxright[height.size() - 1] = 0;
        for(int i = 1; i < height.size(); i ++) maxleft[i] = max(maxleft[i - 1],height[i - 1]);
        for(int i = height.size() - 2; i >= 0; i --) maxright[i] = max(maxright[i + 1], height[i + 1]);

        int res = 0;
        for(int i = 0; i < height.size(); i ++){

            if(min(maxleft[i],maxright[i]) - height[i] <= 0) continue;

            res += min(maxleft[i],maxright[i]) - height[i];

        }
        return res;
    }
};
