class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int target = 0;

        for(int &n : nums) target += n;
        if(target%2) return false;
        target /= 2;

        vector<bool> dp(target + 1);
        dp[0] = true;

        for(int i = 0; i < nums.size();  i++){

            vector<bool> next = dp;
            for(int j = 1; j <= target; j ++){

                if(j - nums[i] >= 0) next[j] = next[j] || dp[j - nums[i]];

            }
            dp = next;

        }
        return dp[target];

    }
};
