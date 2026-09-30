class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> dp1(nums.size(),0);
        vector<int> dp2(nums.size(),0);

        dp1[0] = nums[0];
        for(int i = 1; i < nums.size() - 1; i ++){

            if(i == 1) dp1[i]= max(nums[i],dp1[i - 1]);
            else dp1[i] = max(nums[i] + dp1[i - 2], dp1[i - 1]);

        }
        dp2[1] = nums[1];
        for(int i = 2; i < nums.size(); i ++){

            dp2[i] = max(nums[i] + dp2[i - 2], dp2[i - 1]);

        }

        int size = nums.size();

        return max(dp1[size - 2],dp2[size - 1]);
    }
};
