class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        int dp[105][2] = {0};
        int dp2[105][2] = {0};
        int res1,res2 = 0;
        dp[0][0] = 0;
        dp[0][0] = 0;

        for(int i = 1; i<= nums.size() -1; i++){

            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + nums[i-1];

        }
        res1 = max(dp[nums.size() - 1][0],dp[nums.size() - 1][1]);

        dp2[1][0] = 0;
        dp2[1][1] = 0;

        for(int i = 2; i<= nums.size(); i++){

            dp2[i][0] = max(dp2[i-1][0],dp2[i-1][1]);
            dp2[i][1] = dp2[i-1][0] + nums[i-1];
        }

        res2=max(dp2[nums.size()][0],dp2[nums.size()][1]);

        return max(res1,res2);
    }
};
