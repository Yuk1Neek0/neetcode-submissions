class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int &n : nums) sum += n;
        if(sum % 2 == 1) return false;
        vector<int> dp(sum/2 + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++){

            for(int j = sum/2; j > 0; j --){

                if(j - nums[i] >= 0) dp[j] = dp[j] || dp[j - nums[i]];

            }

        }
        return dp[sum/2];
    }
};
