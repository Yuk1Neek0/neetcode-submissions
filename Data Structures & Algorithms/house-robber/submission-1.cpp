class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[105][2];
        dp[0][0] = 0;
        dp[0][1] = 0;
        for(int i = 1; i <=  nums.size(); i++){

            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + nums[i - 1];

        }

        return max(dp[nums.size()][0],dp[nums.size()][1]);
    }
};
